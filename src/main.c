/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:26 by svereten          #+#    #+#             */
/*   Updated: 2024/06/18 14:30:48 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "get_next_line.h"
#include "pipex.h"
#include "dev.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	state_init(t_pipex_state *s, int c, char **v, char **e)
{
	s->path = NULL;
	s->commands = NULL;
	s->argc = c;
	s->argv = v;
	s->envp = e;
	s->path_length = 0;
	s->error = 0;
}

void	state_free(t_pipex_state *state)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	path_free(state);
	while (state->commands && state->commands[i])
	{
		j = 0;
		while (state->commands[i]->args && state->commands[i]->args[j])
		{
			ft_free_n_null((void **)&(state->commands[i]->args[j]));
			j++;
		}
		ft_free_n_null((void **)&(state->commands[i]->args));
		ft_free_n_null((void **)&(state->commands[i]->path));
		ft_free_n_null((void **)&(state->commands[i]));
		i++;
	}
	ft_free_n_null((void **)&(state->path));
	ft_free_n_null((void **)&(state->commands));
	state->argv = NULL;
	state->envp = NULL;
}

int	state_feed_command_args(t_pipex_state *state, int i)
{
	state->commands[i] = (t_command *)ft_calloc(1, sizeof(t_command));
	if (!state->commands[i])
		return (0);
	state->commands[i]->args = ft_split(state->argv[i + 2], ' ');
	if (!state->commands[i]->args)
		return (0);
	return (1);
}

int	state_feed_command_path(t_pipex_state *state, int index)
{
	char	*path_arg;
	char	*path_dup;
	int		i;

	i = 0;
	while (state->path[i])
	{
		path_dup = ft_strdup(state->path[i]);
		if (!path_dup)
			return (0);
		path_arg = ft_strjoin(path_dup, state->commands[index]->args[0]);
		if (!access(path_arg, X_OK))
		{
			state->commands[index]->path = path_arg;
			return (1);
		}
		ft_free_n_null((void **)&path_arg);
		i++;
	}
	return (0);
}


int main(int argc, char **argv, char **envp) {
	t_pipex_state	state;

	if (argc == 1)
		return (0);
	state_init(&state, argc, argv, envp);
	state_feed(&state);
	if (state.error)
		return (state_free(&state), 1);

	int	fd[2];

	/*int fd_infile = open("./nofile", O_RDONLY);
	if (fd_infile == -1)
		perror("Error");
	char *content = NULL;
	char *buf = "";
	while (get_next_line(fd_infile, &buf) && buf)
	{
		content = ft_strjoin(content, buf);
		ft_free_n_null((void **)&buf);
	}
	close(fd_infile);*/

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

	close(fd[1]);
	close(fd[0]);
	//write(0, content, ft_strlen(content));
	//ft_free_n_null((void **)&content);
	/*int	fd[2];
	if (pipe(fd) == -1) {
		return 1;
	}

	int pid = fork();
	if (pid == -1) {
		return 1;
	}
	if (!pid) {
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
	}*/
	state_free(&state);
}
