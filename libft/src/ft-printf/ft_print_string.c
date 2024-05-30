/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:59:00 by svereten          #+#    #+#             */
/*   Updated: 2024/04/24 17:24:39 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_string(const char *s)
{
	size_t	len;
	int		bytes_written;

	if (!s)
	{
		bytes_written = write(STDOUT_FILENO, "(null)", 6);
		return (bytes_written);
	}
	len = ft_strlen(s);
	bytes_written = write(STDOUT_FILENO, s, len);
	return (bytes_written);
}
