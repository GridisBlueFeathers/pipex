/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_args_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:23:37 by svereten          #+#    #+#             */
/*   Updated: 2024/06/26 17:08:59 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "ft_printf.h"
#include "colors.h"

void	test_args_count()
{
	ft_printf(RED"hello\n\e[0m"RESET);
	ft_printf(GREEN"hello\n\e[0m"RESET);
	args_count("hey", ' ');

}
