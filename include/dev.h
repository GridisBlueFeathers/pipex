/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:44:24 by svereten          #+#    #+#             */
/*   Updated: 2024/06/17 17:50:26 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEV_H
# define DEV_H

#include "pipex.h"

void	dev_state_print_path(t_pipex_state *state);
void	dev_command_print_args(t_command *command);

#endif
