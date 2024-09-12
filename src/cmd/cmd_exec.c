/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:15:39 by svereten          #+#    #+#             */
/*   Updated: 2024/09/12 17:30:16 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/**
 * Panic and exit child if execve fails because command doesn't exist
 */
static void	cmd_exec_child_panic(t_pipex_state *s, int i)
{
	char	*msg;

	if (!s->cmds[i]->exec && s->cmds[i]->in_path)
		panic_perror_exit(s, 126);
	msg = ft_strdup("pipex: command not found: ");
	if (!msg)
		panic_silent_exit(s, 1);
	msg = ft_strjoin(msg, s->cmds[i]->path);
	if (!msg)
		panic_silent_exit(s, 1);
	msg = ft_strjoin(msg, "\n");
	if (!msg)
		panic_silent_exit(s, 1);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_free(STR, &msg);
	state_free(s);
	exit(127);
}

/**
 * Setup redirections to pipes and attempt to execute cmd
 *
 * If t is a valid fd redirects to t
 * 
 * If execve fails will panic and exit
 */
static void	cmd_exec_child(t_pipex_state *s, int pipes[2], int i, int t)
{
	close_wrapper(s, pipes[RD]);
	if ((!i && s->in_fd == -1) || (!s->cmds[i + 1] && s->out_fd == -1))
	{
		close_wrapper(s, pipes[WR]);
		panic_silent_exit(s, 1);
	}
	else if (t)
	{
		dup2_wrapper(s, t, STDOUT_FILENO);
		close_wrapper(s, pipes[WR]);
	}
	else
		dup2_wrapper(s, pipes[WR], STDOUT_FILENO);
	if (execve(s->cmds[i]->path, s->cmds[i]->args, s->envp) == -1)
		cmd_exec_child_panic(s, i);
}

static void	cmd_exec_fork_panic(t_pipex_state *state, int pipes[2])
{
	close_wrapper(state, pipes[0]);
	close_wrapper(state, pipes[1]);
	close_wrapper(state, state->out_fd);
	panic_perror_exit(state, 1);
}

/**
 * Sets pipes, forks a child, saves pid of a child
 *
 * If not last command, redirects reading side of the pipe into stdin
 */
void	cmd_exec(t_pipex_state *state, int i, int target)
{
	pid_t	pid;
	int		pipes[2];

	if (pipe(pipes) == -1)
	{
		close_wrapper(state, state->out_fd);
		panic_perror_exit(state, 1);
	}
	pid = fork();
	if (pid == -1)
		cmd_exec_fork_panic(state, pipes);
	if (pid == 0)
		cmd_exec_child(state, pipes, i, target);
	else
	{
		state->last_pid = pid;
		close_wrapper(state, pipes[WR]);
		if (!target)
			dup2_wrapper(state, pipes[RD], STDIN_FILENO);
		else
			close_wrapper(state, pipes[RD]);
	}
}
