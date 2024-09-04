/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:53:12 by svereten          #+#    #+#             */
/*   Updated: 2024/09/04 17:08:09 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "libft/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/*int	command_exec(t_pipex_state *state, int i)
{
	pid_t	pid;
	int		infile_fd;

	pipe(state->fds);
	pid = fork();
	if (pid == -1)
		exit (1);
	if (!pid)
	{
		int stdin_dup = dup(STDIN_FILENO);
		if (!i)
		{
			infile_fd = open("./infile", O_RDONLY);
			if (infile_fd == -1)
			{
				close(state->fds[1]);
				close(state->fds[0]);
				exit(1);
			}
			dup2(infile_fd, stdin_dup);
			close(infile_fd);
		}
		dup2(state->fds[1], STDOUT_FILENO);
		close(state->fds[1]);
		close(state->fds[0]);
		execve(state->commands[i]->path, state->commands[i]->args, NULL);
	}
	else
	{
		close(state->fds[0]);
		close(state->fds[1]);
		exit(0);
	}
	return (1);
}*/

/*int	command_exec_first(t_pipex_state *state)
{
	pid_t	pid;
	int		infile_fd;
	int		fds[2];

	pipe(fds);
	pid = fork();
	if (pid == -1)
		exit (1);
	if (!pid)
	{
		int	stdout_fd = dup(STDOUT_FILENO);
		close(fds[0]);
		infile_fd = open("./infile", O_RDONLY);
		if (infile_fd == -1)
		{
			close(state->fds[1]);
			close(state->fds[0]);
			exit(1);
		}
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
		dup2(fds[1], stdout_fd);
		close(fds[1]);
		execve(state->commands[0]->path, state->commands[0]->args, NULL);
	}
	else
	{
		close(fds[1]);
		//waitpid(pid, NULL, 0);
		wait(NULL);
		dup2(fds[0], STDOUT_FILENO);
		close(fds[0]);
		exit(0);
	}
	return (1);

}*/

void	command_exec(t_pipex_state *state, int i, int target)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
		perror("pipex");
	pid = fork();
	if (pid == -1)
		perror("pipex");
	if (pid == 0)
	{
		close(fd[0]);
		if (target)
		{
			dup2(target, STDOUT_FILENO);
			close(target);
		}
		else
			dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (execve(state->commands[i]->path, state->commands[i]->args, state->envp) == -1)
		{
			ft_dprintf(STDERR_FILENO, "pipex: command not found: %s", state->commands[i]->path);
			state_free(state);
			exit(127);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			perror("pipex");
		if (WIFEXITED(status))
			state->exit_status = WEXITSTATUS(status);
		close(fd[1]);
		if (!target)
			dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

int	state_commands_run(t_pipex_state *state)
{
	int infile_fd = open(state->argv[1], O_RDONLY);
	if (infile_fd > 0)
		dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	int i = 0;
	while (i < state->argc - 4)
	{
		command_exec(state, i, 0);
		i++;
	}
	int outfile_fd = open(state->argv[state->argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		return (state_free(state), 126);
	command_exec(state, i, outfile_fd);
	close(outfile_fd);
	return (state_free(state), state->exit_status);
}

int main(int argc, char **argv, char **envp) {
	t_pipex_state	state;

	if (argc < 5)
		return (1);
	state_init(&state, argc, argv, envp);
	state_feed(&state);
	if (state.error)
		return (state_free(&state), 127);
	return (state_commands_run(&state));
}
