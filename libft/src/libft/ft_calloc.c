/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:56:08 by svereten          #+#    #+#             */
/*   Updated: 2024/08/18 15:09:37 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

/**
 * Mimics `calloc`
 *
 * protected against and overflows 0 in arguments
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;
	size_t	res_size;

	res_size = nmemb * size;
	if (!nmemb || !size || res_size / size != nmemb)
		return (NULL);
	res = malloc(res_size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < res_size)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}
