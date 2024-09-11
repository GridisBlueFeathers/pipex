/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:10 by svereten          #+#    #+#             */
/*   Updated: 2024/09/11 01:54:21 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	path_free(t_pipex_state *state)
{
	int	len;
	
	len = state->path_length;
	while (len > 0)
	{
		free(state->path[len - 1]);
		len--;
	}
	free(state->path);
}

/**
 * Get's amount of pathes in PATH variable
 */
static int	path_get_length(t_pipex_state *state)
{
	int	i;

	i = 0;
	while (state->path[i])
		i++;
	return (i);
}

/**
 * Gets PATH environment variable and splits it in an array of strings
 */
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
		return (ft_free(STR, &path_env), 0);
	state->path = ft_split(path_raw, ':');
	ft_free(STR, &path_raw);
	if (!state->path)
		return (ft_free(STR, &path_env), 0);
	state->path_length = path_get_length(state);
	i = 0;
	while (state->path[i])
	{
		state->path[i] = ft_strjoin(state->path[i], "/");
		if (!state->path[i])
			return (ft_free(STR, &path_env), 0);
		i++;
	}
	return (ft_free(STR, &path_env), 1);
}
