/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:37:53 by svereten          #+#    #+#             */
/*   Updated: 2024/06/21 11:16:54 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

void	dev_state_print_command_path(t_pipex_state *state)
{
	int i = 0;
	while (state->commands[i])
	{
		ft_printf("%s\n", state->commands[i]->path);
		i++;
	}
}

void	dev_state_print_path(t_pipex_state *state)
{
	int i = 0;
	while (state->path[i])
	{
		ft_printf("%s\n", state->path[i]);
		i++;
	}
}

void	dev_command_print_path(t_command *command)
{
	ft_printf("%s\n", command->path);
}

void	dev_command_print_args(t_command *command)
{
	int i = 0;
	while (command->args[i])
	{
		ft_printf("%s\n", command->args[i]);
		i++;
	}
}
