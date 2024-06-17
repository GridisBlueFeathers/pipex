/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:35:57 by svereten          #+#    #+#             */
/*   Updated: 2024/06/17 11:36:25 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "libft.h"

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
