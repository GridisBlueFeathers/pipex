/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:17:58 by svereten          #+#    #+#             */
/*   Updated: 2024/04/09 15:25:28 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_putnbr_fd_worker(int n, int mod, int fd)
{
	if ((mod == -1 && n > -10) || (mod == 1 && n < 10))
	{
		ft_putchar_fd((mod * n) + '0', fd);
		return ;
	}
	ft_putnbr_fd_worker(n / 10, mod, fd);
	ft_putnbr_fd_worker(n % 10, mod, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	mod;

	mod = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		mod = -1;
	}
	ft_putnbr_fd_worker(n, mod, fd);
}
