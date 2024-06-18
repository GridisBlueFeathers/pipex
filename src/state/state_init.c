/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:00:45 by svereten          #+#    #+#             */
/*   Updated: 2024/06/18 17:01:23 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	state_init(t_pipex_state *s, int c, char **v, char **e)
{
	s->path = NULL;
	s->commands = NULL;
	s->argc = c;
	s->argv = v;
	s->envp = e;
	s->path_length = 0;
	s->error = 0;
}

void	state_free(t_pipex_state *state)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	path_free(state);
	while (state->commands && state->commands[i])
	{
		j = 0;
		while (state->commands[i]->args && state->commands[i]->args[j])
		{
			ft_free_n_null((void **)&(state->commands[i]->args[j]));
			j++;
		}
		ft_free_n_null((void **)&(state->commands[i]->args));
		ft_free_n_null((void **)&(state->commands[i]->path));
		ft_free_n_null((void **)&(state->commands[i]));
		i++;
	}
	ft_free_n_null((void **)&(state->path));
	ft_free_n_null((void **)&(state->commands));
	state->argv = NULL;
	state->envp = NULL;
}
