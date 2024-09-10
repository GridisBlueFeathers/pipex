/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:33:58 by svereten          #+#    #+#             */
/*   Updated: 2024/09/10 14:18:20 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/ft_printf.h"
#include "pipex.h"

/**
 * Panic and exit without printing anything
 */
void	panic_silent_exit(t_pipex_state *state, int status)
{
	state_free(state);
	exit(status);
}

/**
 * Panic and exit printing out custom message
 */
void	panic_msg_exit(t_pipex_state *state, char *msg, int status)
{
	ft_dprintf(STDERR_FILENO, "pipex: %s\n", msg);
	state_free(state);
	exit(status);
}

/**
 * Panic and exit printing out message of current errno
 */
void	panic_perror_exit(t_pipex_state *state, int status)
{
	perror("pipex");
	state_free(state);
	exit(status);
}
