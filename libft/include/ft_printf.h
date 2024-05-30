/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:46:03 by svereten          #+#    #+#             */
/*   Updated: 2024/05/16 21:33:55 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

#include "libft.h"

int		ft_print_uhex(unsigned long n, char fmt);

int		ft_print_char(char c);
int		ft_print_string(const char *s);
int		ft_print_pointer_addr(void *p);
int		ft_print_int(int n);
int		ft_print_uint(unsigned int n);

int		ft_printf(const char *fmt, ...);

#endif
