/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:26 by svereten          #+#    #+#             */
/*   Updated: 2024/06/20 09:47:51 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "get_next_line.h"
#include "pipex.h"
#include "dev.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	command_exec(t_pipex_state *state, int i)
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
}

int	command_exec_first(t_pipex_state *state)
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

}

int main(int argc, char **argv, char **envp) {
	t_pipex_state	state;

	if (argc == 1)
		return (0);
	state_init(&state, argc, argv, envp);
	state_feed(&state);
	if (state.error)
		return (state_free(&state), 1);

	command_exec_first(&state);
	/*pid_t p2 = fork();
	if (!p2)
	{
		//write(fd[1], content, ft_strlen(content));
		int fd_infile = open("./infile", O_RDONLY);
		if (fd_infile == -1)
		{
			close(fd[1]);
			close(fd[0]);
			exit(1);
		}
		dup2(fd_infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd_infile);
		close(fd[1]);
		close(fd[0]);
		execve(state.commands[0]->path, state.commands[0]->args, NULL);
	}*/
	/*else
	{
		close(fd[0]);
		close(fd[1]);
	}*/

	pid_t p1 = fork();
	if (!p1)
	{
		execve(state.commands[1]->path, state.commands[1]->args, NULL);
	}
	/*else
	{
		close(fd[0]);
		close(fd[1]);
	}*/

	//waitpid(p1, NULL, 0);
	state_free(&state);
}
