/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_int_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:53:27 by svereten          #+#    #+#             */
/*   Updated: 2024/06/26 18:00:53 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "colors.h"

int	test_int_func(int func_res, int exp_res, int label)
{
	ft_printf("%d. Expected result: %d Actual result %d\n", label, exp_res, func_res);
	if (exp_res != func_res)
		return (ft_printf(RED"[KO]\n"RESET), 0);
	return (ft_printf(GREEN"[OK]\n"RESET), 0);
}
