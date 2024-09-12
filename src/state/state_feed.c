/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_feed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:28:59 by svereten          #+#    #+#             */
/*   Updated: 2024/09/12 17:02:36 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/**
 * Processes arguments and creates cmds out of arguments
 */
void	state_feed(t_pipex_state *state)
{
	state_fd_get_in(state);
	if (!path_get(state) || !cmds_process(state))
		state->error = 1;
	path_free(state);
}
