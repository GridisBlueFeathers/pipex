/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_args_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:23:37 by svereten          #+#    #+#             */
/*   Updated: 2024/06/26 18:04:08 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "ft_printf.h"
#include "colors.h"
#include "tests.h"

void	test_args_count()
{
	ft_printf("Testing args_count()\n");
	test_int_func(args_count("", ' '), 0, 1);
	test_int_func(args_count("hey", ' '), 1, 2);
	test_int_func(args_count("grep 'hey'", ' '), 2, 3);
	test_int_func(args_count("grep 'hey hey'", ' '), 2, 3);
}
