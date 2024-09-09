/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:53:12 by svereten          #+#    #+#             */
/*   Updated: 2024/09/09 17:44:49 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "libft/ft_printf.h"

void	cmd_exec_child_exit(t_pipex_state *s, int i)
{
	ft_dprintf(
		STDERR_FILENO,
		"pipex: command not found: %s\n",
		s->cmds[i]->path
		);
	state_free(s);
	exit(127);
}

void	cmd_exec_child(t_pipex_state *s, int fd[2], int i, int t)
{
	close(fd[0]);
	if (t)
	{
		dup2(t, STDOUT_FILENO);
		close(t);
	}
	else
		dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (execve(s->cmds[i]->path, s->cmds[i]->args, s->envp) == -1)
		cmd_exec_child_exit(s, i);
}

void	cmd_exec(t_pipex_state *state, int i, int target)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		perror("pipex");
	pid = fork();
	if (pid == -1)
		perror("pipex");
	if (pid == 0)
		cmd_exec_child(state, fd, i, target);
	else
	{
		state->last_pid = pid;
		close(fd[1]);
		if (!target)
			dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

int	state_cmds_run(t_pipex_state *state)
{
	int	status;
	int	i;

	if (state->in_fd > 0)
		dup2(state->in_fd, STDIN_FILENO);
	close(state->in_fd);
	i = 0;
	while (i < state->argc - 4)
	{
		cmd_exec(state, i, 0);
		i++;
	}
	if (state->out_fd == -1)
		return (state_free(state), 126);
	cmd_exec(state, i, state->out_fd);
	close(state->out_fd);
	if (waitpid(state->last_pid, &status, 0) == -1)
		perror("pipex");
	if (WIFEXITED(status))
		state->exit_status = WEXITSTATUS(status);
	return (state_free(state), state->exit_status);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex_state	state;

	if (argc < 5)
		return (1);
	state_init(&state, argc, argv, envp);
	state_feed(&state);
	if (state.error)
		return (state_free(&state), 127);
	return (state_cmds_run(&state));
}
