/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:10 by svereten          #+#    #+#             */
/*   Updated: 2024/06/17 16:23:00 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "libft.h"

int	path_get(t_pipex_state *state)
{
	char	*path_env;
	char	*path_raw;

	path_env = env_get(state, "PATH");
	if (!path_env)
		return (0);
	path_raw = ft_substr(path_env, 5, ft_strlen(path_env));
	ft_free_n_null((void **)&path_env);
	if (!path_raw)
		return (0);
	state->path = ft_split(path_raw, ':');
	ft_free_n_null((void **)&path_raw);
	if (!state->path)
		return (0);
	return (1);
}
