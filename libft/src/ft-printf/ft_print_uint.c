/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:59:06 by svereten          #+#    #+#             */
/*   Updated: 2024/09/04 15:48:11 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/ft_printf.h"

int	ft_print_uint(unsigned int n, int fd)
{
	int	bytes_written;
	int	res;

	res = 0;
	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	bytes_written = ft_print_uint(n / 10, fd);
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	bytes_written = ft_print_uint(n % 10, fd);
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	return (res);
}
