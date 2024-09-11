/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_t_increment_check.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:35:52 by svereten          #+#    #+#             */
/*   Updated: 2024/09/06 18:52:53 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

void	ft_size_t_increment_check(size_t *to_inc, int *check)
{
	size_t	prev;

	prev = *to_inc;
	(*to_inc)++;
	if (prev > *to_inc)
		*check = 0;
}
