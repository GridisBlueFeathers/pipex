/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:33:58 by svereten          #+#    #+#             */
/*   Updated: 2024/09/06 13:36:17 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/ft_printf.h"
#include "pipex.h"

void	panic_msg_exit(t_pipex_state *state, char *msg, int status)
{
	ft_dprintf(STDERR_FILENO, "pipex: %s\n", msg);
	state_free(state);
	exit(status);
}
