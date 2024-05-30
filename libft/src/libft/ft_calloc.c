/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:56:08 by svereten          #+#    #+#             */
/*   Updated: 2024/04/11 19:05:21 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;
	size_t	res_size;

	res_size = nmemb * size;
	if (res_size / size != nmemb)
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
