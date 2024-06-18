/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_feed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:28:59 by svereten          #+#    #+#             */
/*   Updated: 2024/06/18 14:30:54 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	state_feed_command(t_pipex_state *state, int i)
{
	if (!state_feed_command_args(state, i)
		|| !state_feed_command_path(state, i))
		return (0);
	return (1);
}

int	state_feed_process_commands(t_pipex_state *state)
{
	int		i;

	state->commands = (t_command **)ft_calloc(state->argc - 2, sizeof(t_command *));
	if (!state->commands)
		return (0);
	i = 0;
	while (i < state->argc - 3)
	{
		if (!state_feed_command(state, i))
			return (0);
		i++;
	}
	return (1);
}

void	state_feed(t_pipex_state *state)
{
	if (!path_get(state) || !state_feed_process_commands(state))
		state->error = 1;
}

