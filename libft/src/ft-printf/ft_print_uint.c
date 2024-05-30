/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:59:06 by svereten          #+#    #+#             */
/*   Updated: 2024/04/24 17:26:10 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_uint(unsigned int n)
{
	int	bytes_written;
	int	res;

	res = 0;
	if (n < 10)
	{
		bytes_written = ft_print_char(n + '0');
		return (bytes_written);
	}
	bytes_written = ft_print_uint(n / 10);
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	bytes_written = ft_print_uint(n % 10);
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	return (res);
}
