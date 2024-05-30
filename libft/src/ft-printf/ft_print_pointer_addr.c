/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_addr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:23:32 by svereten          #+#    #+#             */
/*   Updated: 2024/04/23 16:50:18 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_pointer_addr(void *p)
{
	int	bytes_written;
	int	res;

	if (!p)
	{
		bytes_written = write(STDOUT_FILENO, "(nil)", 5);
		return (bytes_written);
	}
	res = 0;
	bytes_written = ft_print_string("0x");
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	bytes_written = ft_print_uhex((unsigned long)p, 'x');
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	return (res);
}
