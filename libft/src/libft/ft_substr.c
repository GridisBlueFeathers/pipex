/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:26:32 by svereten          #+#    #+#             */
/*   Updated: 2024/04/04 17:00:19 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	new_len;
	unsigned int	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		new_len = 0;
	else if (len > ft_strlen(s) - start)
		new_len = ft_strlen(s) - start;
	else
		new_len = len;
	res = (char *)ft_calloc(new_len + 1, sizeof(char));
	if (!res)
		return (0);
	i = start;
	while ((i < len + start) && s[i] && start < ft_strlen(s))
	{
		res[i - start] = s[i];
		i++;
	}
	return (res);
}
