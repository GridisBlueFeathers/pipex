/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:54:27 by svereten          #+#    #+#             */
/*   Updated: 2024/09/05 18:32:34 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/**
 * Allocates array of cmds structs
 *
 * Runs allocation and processing function for each cmd
 *
 * NULL terminated (argc minus program name, infile, outfile plus NULL)
 */
int	cmds_process(t_pipex_state *state)
{
	int		i;
	int		argc;

	argc = state->argc;
	state->cmds = (t_cmd **)ft_calloc(argc - 2, sizeof(t_cmd *));
	if (!state->cmds)
		return (0);
	i = 0;
	while (i < state->argc - 3)
	{
		if (!cmd_process(state, i))
			return (0);
		i++;
	}
	return (1);
}
