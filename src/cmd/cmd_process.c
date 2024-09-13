/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:59:48 by svereten          #+#    #+#             */
/*   Updated: 2024/09/13 15:42:08 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/**
 * Processes and sets cmd args
 */
static int	cmd_process_args(t_pipex_state *state, int i)
{
	state->cmds[i]->args = args_split(state->argv[i + 2]);
	if (!state->cmds[i]->args)
		return (0);
	return (1);
}

static int	cmd_process_path_access(t_pipex_state *state, int index, char *arg)
{
	if (!access(arg, X_OK))
	{
		if (state->cmds[index]->path)
			free(state->cmds[index]->path);
		state->cmds[index]->path = arg;
		state->cmds[index]->in_path = 1;
		return (1);
	}
	if (!access(arg, F_OK))
	{
		if (state->cmds[index]->path)
			free(state->cmds[index]->path);
		state->cmds[index]->path = ft_strdup(arg);
		state->cmds[index]->in_path = 1;
	}
	return (0);
}

/**
 * Checks if first element of cmd args is executable by itself or it could be
 * found in PATH
 *
 * If could be found in PATH sets path to full path to executable
 *
 * Otherwise sets path to first element of cmd args
 * (if not executable it is handled in execve)
 */
static int	cmd_process_path(t_pipex_state *state, int index)
{
	char	*path_arg;
	char	*path_dup;
	int		i;

	i = 0;
	while (state->path && state->path[i]
		&& !ft_strchr(state->cmds[index]->args[0], '/'))
	{
		path_dup = ft_strdup(state->path[i]);
		if (!path_dup)
			return (0);
		path_arg = ft_strjoin(path_dup, state->cmds[index]->args[0]);
		if (!path_arg)
			return (0);
		if (cmd_process_path_access(state, index, path_arg))
			return (1);
		ft_free(STR, &path_arg);
		i++;
	}
	if (!state->cmds[index]->path)
		state->cmds[index]->path = ft_strdup(state->cmds[index]->args[0]);
	return (1);
}

/**
 * Allocates cmd struct, processes and sets cmd args and path
 */
int	cmd_process(t_pipex_state *state, int i)
{
	state->cmds[i] = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!state->cmds[i])
		return (0);
	state->cmds[i]->path = NULL;
	state->cmds[i]->in_path = 0;
	if (!cmd_process_args(state, i)
		|| !cmd_process_path(state, i)
		|| !state->cmds[i]->path)
		return (0);
	return (1);
}
