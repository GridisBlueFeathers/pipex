/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:15:39 by svereten          #+#    #+#             */
/*   Updated: 2024/09/10 14:18:58 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "libft/ft_printf.h"

static void	cmd_exec_child_panic(t_pipex_state *s, int i)
{
	ft_dprintf(
		STDERR_FILENO,
		"pipex: command not found: %s\n",
		s->cmds[i]->path
		);
	state_free(s);
	exit(127);
}

static void	cmd_exec_child(t_pipex_state *s, int pipes[2], int i, int t)
{
	close(pipes[RD]);
	if (!i && s->in_fd == -1)
	{
		close(pipes[WR]);
		panic_silent_exit(s, 127);
	}
	else if (t)
	{
		dup2(t, STDOUT_FILENO);
		close(t);
	}
	else
		dup2(pipes[WR], STDOUT_FILENO);
	close(pipes[WR]);
	if (execve(s->cmds[i]->path, s->cmds[i]->args, s->envp) == -1)
		cmd_exec_child_panic(s, i);
}

void	cmd_exec(t_pipex_state *state, int i, int target)
{
	pid_t	pid;
	int		pipes[2];

	if (pipe(pipes) == -1)
		panic_perror_exit(state, 1);
	pid = fork();
	if (pid == -1)
		panic_perror_exit(state, 1);
	if (pid == 0)
		cmd_exec_child(state, pipes, i, target);
	else
	{
		state->last_pid = pid;
		close(pipes[WR]);
		if (target == -1)
		{
			close(pipes[RD]);
			panic_perror_exit(state, 126);
		}
		if (!target)
			dup2(pipes[RD], STDIN_FILENO);
		close(pipes[RD]);
	}
}
