/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:26 by svereten          #+#    #+#             */
/*   Updated: 2024/06/18 17:17:41 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "get_next_line.h"
#include "pipex.h"
#include "dev.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) {
	t_pipex_state	state;

	if (argc == 1)
		return (0);
	state_init(&state, argc, argv, envp);
	state_feed(&state);
	if (state.error)
		return (state_free(&state), 1);

	int	fd[2];
	pipe(fd);
	pid_t p2 = fork();
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
	}
	/*else
	{
		close(fd[1]);
		close(fd[0]);
		exit (0);
	}*/
	pid_t p1 = fork();
	if (!p1)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
		execve(state.commands[1]->path, state.commands[1]->args, NULL);
	}
	/*else
	{
		close(fd[1]);
		close(fd[0]);
		exit (0);
	}*/

	close(fd[0]);
	close(fd[1]);

	waitpid(p2, NULL, 0);
	waitpid(p1, NULL, 0);
	state_free(&state);
}
