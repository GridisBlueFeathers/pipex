/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:10 by svereten          #+#    #+#             */
/*   Updated: 2024/07/30 15:52:12 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	path_get_length(t_pipex_state *state)
{
	int	i;

	i = 0;
	while (state->path[i])
		i++;
	return (i);
}

void	path_free(t_pipex_state *state)
{
	int	i;

	i = 0;
	while (i < state->path_length)
	{
		ft_free_n_null((void **)&(state->path[i]));
		i++;
	}
	ft_free_n_null((void **)&(state->path));
}

int	path_get(t_pipex_state *state)
{
	char	*path_env;
	char	*path_raw;
	int		i;

	path_env = env_get(state, "PATH");
	if (!path_env)
		return (0);
	path_raw = ft_substr(path_env, 5, ft_strlen(path_env));
	if (!path_raw)
		return (0);
	state->path = ft_split(path_raw, ':');
	ft_free_n_null((void **)&path_raw);
	if (!state->path)
		return (0);
	state->path_length = path_get_length(state);
	i = 0;
	while (state->path[i])
	{
		state->path[i] = ft_strjoin(state->path[i], "/");
		if (!state->path[i])
			return (0);
		i++;
	}
	return (1);
}
