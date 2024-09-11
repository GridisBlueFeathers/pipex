/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:15:39 by svereten          #+#    #+#             */
/*   Updated: 2024/09/11 15:15:21 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "libft/ft_printf.h"

/**
 * Panic and exit child if execve fails because command doesn't exist
 */
static void	cmd_exec_child_panic(t_pipex_state *s, int i)
{
	char	*msg;
	int		msg_len;

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
	msg_len = 27 + ft_strlen(s->cmds[i]->path);
	write(2, msg, msg_len);
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
	{
		dup2_wrapper(s, pipes[WR], STDOUT_FILENO);
		close_wrapper(s, s->out_fd);
	}
	if (execve(s->cmds[i]->path, s->cmds[i]->args, s->envp) == -1)
		cmd_exec_child_panic(s, i);
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
		panic_perror_exit(state, 1);
	pid = fork();
	if (pid == -1)
		panic_perror_exit(state, 1);
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
