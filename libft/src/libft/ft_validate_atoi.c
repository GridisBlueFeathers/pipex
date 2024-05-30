/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:07:31 by svereten          #+#    #+#             */
/*   Updated: 2024/05/29 17:23:16 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_validate_atoi(char *str, int	*num)
{
	int	str_num;

	str_num = ft_atoi(str);
	if (ft_strlen(str) != ft_intlen(str_num))
		return (0);
	if (str_num == 0 && str[0] != '0')
		return (0);
	*num = str_num;
	return (1);
}
