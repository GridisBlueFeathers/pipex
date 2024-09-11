/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:23:56 by svereten          #+#    #+#             */
/*   Updated: 2024/08/22 14:51:57 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

void	ft_putstrarr_fd(char **arr, int fd)
{
	int	i;

	i = 0;
	if (!arr)
		ft_putstr_fd("NULL", fd);
	ft_putstr_fd("{", fd);
	while (arr[i])
	{
		ft_putstr_fd("\"", fd);
		ft_putstr_fd(arr[i], fd);
		ft_putstr_fd("\", ", fd);
		i++;
	}
	ft_putstr_fd("NULL}", fd);
}
