/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:14:04 by svereten          #+#    #+#             */
/*   Updated: 2024/09/11 18:24:39 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/**
 * Gets file descriptors of both infile and outfile
 *
 * Prints errors to stderr(2) if file is not availible
 */
void	state_fd_get_in_out(t_pipex_state *s)
{
	int	out_arg;

	out_arg = s->argc - 1;
	s->in_fd = open(s->argv[1], O_RDONLY);
	if (s->in_fd == -1)
		perror("pipex");
	else
		dup2_wrapper(s, s->in_fd, STDIN_FILENO);
	s->out_fd = open(s->argv[out_arg], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (s->out_fd == -1)
		perror("pipex");
}
