/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:26 by svereten          #+#    #+#             */
/*   Updated: 2024/06/10 18:16:46 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char *read_file(char *file_name) {
	(void)file_name;
	return (NULL);
}

int parse_args(int argc, char **argv) {
	(void)argc;
	(void)argv;
	return (1);
}

int main(int argc, char **argv, char **envp) {
	(void)argc;
	(void)argv;
	(void)envp;
	/*int fd = open("./infile", O_WRONLY | O_CREAT);
  dup2(fd, STDOUT_FILENO);
  close(fd);
  printf("hello there\n");
  return (0);*/

	int fd = open("./infile-extra-thicc", O_RDONLY);
	if (fd == -1)
		perror("Error");
	char *content = NULL;
	char *buf = "";
	while (get_next_line(fd, &buf) && buf)
	{
		printf("%s\n", buf);
		content = ft_strjoin(content, buf);
		ft_free_n_null((void **)&buf);
	}
	printf("%s\n", content);
	ft_free_n_null((void **)&content);
	close(fd);

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

	/*char	*argvv[2] = {"hi", NULL};
  (void)argvv;
  int i = 0;
  while(argv[i])
  {
		  printf("%p\n", argv[i]);
		  i++;
  }
  printf("%p\n", argv[i]);*/
	// execve("/usr/bin/echo", argv, NULL);
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
