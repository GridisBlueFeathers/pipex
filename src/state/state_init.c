/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:00:45 by svereten          #+#    #+#             */
/*   Updated: 2024/09/05 17:48:13 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/**
 * Initialises state variables and sets state argc, argv and envp
 */
void	state_init(t_pipex_state *s, int c, char **v, char **e)
{
	s->path = NULL;
	s->cmds = NULL;
	s->argc = c;
	s->argv = v;
	s->envp = e;
	s->path_length = 0;
	s->error = 0;
	s->last_pid = 0;
}

/**
 * Frees allocated fields of state
 */
void	state_free(t_pipex_state *state)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (state->path_length > 0)
	{
		ft_free(STR, &state->path[state->path_length - 1]);
		state->path_length--;
	}
	free(state->path);
	while (state->cmds && state->cmds[i])
	{
		j = 0;
		ft_free(STR, &state->cmds[i]->path);
		ft_free(STR_ARR, &state->cmds[i]->args);
		ft_free(STRUCT, &state->cmds[i]);
		i++;
	}
	ft_free(STR, &(state->cmds));
	state->argv = NULL;
	state->envp = NULL;
}
