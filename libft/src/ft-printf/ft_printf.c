/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:54:24 by svereten          #+#    #+#             */
/*   Updated: 2024/04/24 17:26:24 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_format(va_list ap, char f)
{
	if (f == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (f == 's')
		return (ft_print_string(va_arg(ap, char *)));
	if (f == 'p')
		return (ft_print_pointer_addr(va_arg(ap, void *)));
	if (f == 'd' || f == 'i')
		return (ft_print_int(va_arg(ap, int)));
	if (f == 'u')
		return (ft_print_uint(va_arg(ap, unsigned int)));
	if (f == 'x' || f == 'X')
		return (ft_print_uhex(va_arg(ap, unsigned int), f));
	if (f == '%')
		return (ft_print_char('%'));
	return (-1);
}

static int	ft_iterate_print(va_list ap, const char *fmt)
{
	size_t	len;
	size_t	i;
	int		bytes_written;

	i = 0;
	len = 0;
	while (fmt && fmt[i])
	{
		if (fmt[i + 1] && fmt[i] == '%')
		{
			bytes_written = ft_format(ap, fmt[i + 1]);
			i++;
		}
		else
			bytes_written = ft_print_char(fmt[i]);
		i++;
		if (bytes_written == -1)
			return (bytes_written);
		len += bytes_written;
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	len;

	if (!fmt)
		return (-1);
	len = 0;
	va_start(ap, fmt);
	len = ft_iterate_print(ap, fmt);
	va_end(ap);
	return (len);
}
