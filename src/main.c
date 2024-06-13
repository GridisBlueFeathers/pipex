/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:26 by svereten          #+#    #+#             */
/*   Updated: 2024/06/13 16:27:18 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) {
	(void)argc;
	(void)argv;
	(void)envp;
	/*int fd = open("./infile", O_WRONLY | O_CREAT);
  dup2(fd, STDOUT_FILENO);
  close(fd);
  printf("hello there\n");
  return (0);*/


	/*int i = 0;
	char *path_raw;
	while (envp[i]) {
		if (!ft_strncmp("PATH=", envp[i], 5)) {
			path_raw = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			if (!path_raw) {
				printf("death\n");
				return (1);
			}
		}
		i++;
	}
	char **pathes;
	pathes = ft_split(path_raw, ':');
	i = 0;
	while (pathes[i]) {
		pathes[i] = ft_strjoin(pathes[i], "/");
		if (!access(ft_strjoin(ft_strdup(pathes[i]), "ls"), X_OK))
			printf("%s\n", ft_strjoin(ft_strdup(pathes[i]), "ls"));
		i++;
	}*/

	char *args_grep[] = {"grep", "hey", NULL};
	char *args_wc[] = {"wc", "-l", NULL};
	char *args_ls[] = {"ls", "-a", NULL};
	(void)args_ls;
	(void)args_grep;
	(void)args_wc;

	int	fd[2];

	if (access("./nofile", R_OK))
		perror("Error");
	int fd_infile = open("./nofile", O_RDONLY);
	if (fd_infile == -1)
		perror("Error");
	char *content = NULL;
	char *buf = "";
	while (get_next_line(fd_infile, &buf) && buf)
	{
		content = ft_strjoin(content, buf);
		ft_free_n_null((void **)&buf);
	}
	close(fd_infile);

	pipe(fd);
	pid_t p2 = fork();
	if (!p2)
	{
		//write(fd[1], content, ft_strlen(content));
		int fd_infile = open("./nofile", O_RDONLY);
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
		execve("/usr/bin/ls", args_ls, NULL);
	}
	pid_t p1 = fork();
	if (!p1)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
		execve("/usr/bin/wc", args_wc, NULL);
	}

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
}
