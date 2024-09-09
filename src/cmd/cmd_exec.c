/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:15:39 by svereten          #+#    #+#             */
/*   Updated: 2024/09/09 18:33:44 by svereten         ###   ########.fr       */
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

static void	cmd_exec_child(t_pipex_state *s, int fd[2], int i, int t)
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
		cmd_exec_child_panic(s, i);
}

void	cmd_exec(t_pipex_state *state, int i, int target)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		panic_perror_exit(state, 1);
	pid = fork();
	if (pid == -1)
		panic_perror_exit(state, 1);
	if (pid == 0)
		cmd_exec_child(state, fd, i, target);
	else
	{
		state->last_pid = pid;
		close(fd[1]);
		if (target == -1)
		{
			close(fd[0]);
			panic_perror_exit(state, 126);
		}
		if (!target)
			dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}
