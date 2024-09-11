/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:46:03 by svereten          #+#    #+#             */
/*   Updated: 2024/09/04 15:50:54 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# include "libft/libft.h"

int		ft_print_uhex(unsigned long n, int fd, char fmt);

int		ft_print_pointer_addr(void *p, int fd);
int		ft_print_uint(unsigned int n, int fd);

int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);

#endif
