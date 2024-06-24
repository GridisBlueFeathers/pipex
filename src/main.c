/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:26 by svereten          #+#    #+#             */
/*   Updated: 2024/06/25 00:29:43 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "get_next_line.h"
#include "pipex.h"
#include "dev.h"
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

	if (pipe(fd) == -1)
		perror("well");
	pid = fork();
	if (pid == -1)
		perror("well");
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
			perror("well fuck");
			state_free(state);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		close(fd[1]);
		if (!target)
			dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

int main(int argc, char **argv, char **envp) {
	t_pipex_state	state;

	if (argc < 5)
		return (1);
	state_init(&state, argc, argv, envp);
	state_feed(&state);
	if (state.error)
		return (state_free(&state), 127);

	int infile_fd = open(argv[1], O_RDONLY, 0777);
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	int i = 0;
	while (i < state.argc - 4)
	{
		command_exec(&state, i, 0);
		i++;
	}
	int outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd == -1)
		return (126);
	command_exec(&state, i, outfile_fd);
	close(outfile_fd);
	
	state_free(&state);
	return (EXIT_SUCCESS);
}
