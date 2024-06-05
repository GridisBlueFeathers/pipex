/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:26 by svereten          #+#    #+#             */
/*   Updated: 2024/06/05 11:36:55 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

char	*read_file(char *file_name)
{
	(void)file_name;
	return (NULL);
}

int	parse_args(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char	*argvv[2] = {"hi", NULL};
	(void)argvv;
	int i = 0;
	while(argv[i])
	{
		printf("%p\n", argv[i]);
		i++;
	}
	printf("%p\n", argv[i]);
	//execve("/usr/bin/echo", argv, NULL);

}
