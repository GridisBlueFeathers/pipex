/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 02:21:10 by svereten          #+#    #+#             */
/*   Updated: 2024/09/11 02:23:16 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	dup2_wrapper(t_pipex_state *state, int old, int new)
{
	if (dup2(old, new) == -1)
		panic_perror_exit(state, 1);
	if (close(old) == -1)
		panic_perror_exit(state, 1);
}
