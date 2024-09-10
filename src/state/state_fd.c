/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:14:04 by svereten          #+#    #+#             */
/*   Updated: 2024/09/10 13:17:30 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/ft_printf.h"
#include "pipex.h"

void	state_fd_get_in_out(t_pipex_state *s)
{
	int	out_arg;

	out_arg = s->argc - 1;
	s->in_fd = open(s->argv[1], O_RDONLY);
	if (s->in_fd == -1)
		ft_dprintf(STDERR_FILENO, "pipex: permission denied: %s\n", s->argv[1]);
	s->out_fd = open(s->argv[out_arg], O_WRONLY | O_CREAT | O_TRUNC, 0644);
}
