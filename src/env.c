/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:35:57 by svereten          #+#    #+#             */
/*   Updated: 2024/09/09 17:46:36 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/**
 * Creates a copy of an environment variable
 *
 * If environment variable doesn't exist returns NULL
 */
char	*env_get(t_pipex_state *state, char *env)
{
	char	*res;
	int		i;

	i = 0;
	while (state->envp[i])
	{
		if (!ft_strncmp(state->envp[i], env, ft_strlen(env)))
		{
			res = ft_strdup(state->envp[i]);
			return (res);
		}
		i++;
	}
	return (NULL);
}
