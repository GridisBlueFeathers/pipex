/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:33:07 by svereten          #+#    #+#             */
/*   Updated: 2024/09/06 14:39:19 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

/**
 * Frees a string array
 */
static void	ft_free_str_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		ft_free(STR, &arr[i]);
		i++;
	}
	free(arr);
}

/**
 * Frees variable and sets it to NULL, variable should be passed by reference
 */
void	ft_free(t_type type, void *ptr)
{
	if (type == STR || type == STRUCT)
		free(*(void **)ptr);
	if (type == STR_ARR)
		ft_free_str_arr(*(char ***)ptr);
	ptr = NULL;
}
