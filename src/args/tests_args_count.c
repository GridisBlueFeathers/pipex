/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_args_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:23:37 by svereten          #+#    #+#             */
/*   Updated: 2024/06/26 16:24:28 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "ft_printf.h"

void	test_args_count()
{
	ft_printf("\033[1;31m");
	ft_printf("hello\n");
	ft_printf("\033[0m");
	args_count("hey", ' ');

}
