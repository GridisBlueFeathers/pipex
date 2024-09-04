/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_feed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:28:59 by svereten          #+#    #+#             */
/*   Updated: 2024/09/04 12:33:07 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/**
 * Allocates command struct
 *
 * Splits and puts arguments to struct field
 */
static int	state_feed_command_args(t_pipex_state *state, int i)
{
	state->commands[i] = (t_command *)ft_calloc(1, sizeof(t_command));
	if (!state->commands[i])
		return (0);
	state->commands[i]->args = args_split(state->argv[i + 2]);
	if (!state->commands[i]->args)
		return (0);
	return (1);
}

/**
 * Checks if first command argument is executable
 *
 * True: puts it to command path
 *
 * False: checks if executable could be found in PATH directories
 */
static int	state_feed_command_path(t_pipex_state *state, int index)
{
	char	*path_arg;
	char	*path_dup;
	int		i;

	i = 0;
	while (state->path[i])
	{
		path_dup = ft_strdup(state->path[i]);
		if (!path_dup)
			return (0);
		path_arg = ft_strjoin(path_dup, state->commands[index]->args[0]);
		if (!access(path_arg, X_OK))
		{
			state->commands[index]->path = path_arg;
			return (1);
		}
		ft_free(STR, &path_arg);
		i++;
	}
	state->commands[index]->path = ft_strdup(state->commands[index]->args[0]);
	return (1);
}

/**
 * Processes arguments and PATH variable to get commands
 */
static int	state_feed_command(t_pipex_state *state, int i)
{
	if (!state_feed_command_args(state, i)
		|| !state_feed_command_path(state, i))
		return (0);
	return (1);
}

/**
 * Allocates array of commands structs
 *
 * Runs allocation and processing function for each command
 *
 * NULL terminated
 */
static int	state_feed_process_commands(t_pipex_state *state)
{
	int		i;
	int		argc;

	argc = state->argc;
	state->commands = (t_command **)ft_calloc(argc - 2, sizeof(t_command *));
	if (!state->commands)
		return (0);
	i = 0;
	while (i < state->argc - 3)
	{
		if (!state_feed_command(state, i))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Processes arguments and creates commands out of arguments
 */
void	state_feed(t_pipex_state *state)
{
	if (!path_get(state) || !state_feed_process_commands(state))
		state->error = 1;
}
