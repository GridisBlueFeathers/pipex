/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:54:27 by svereten          #+#    #+#             */
/*   Updated: 2024/09/10 17:10:41 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/**
 * Allocates array of cmds structs
 *
 * Runs allocation and processing function for each cmd
 *
 * NULL terminated (argc minus program name, infile, outfile plus NULL)
 */
int	cmds_process(t_pipex_state *state)
{
	int		i;
	int		argc;

	argc = state->argc;
	state->cmds = (t_cmd **)ft_calloc(argc - 2, sizeof(t_cmd *));
	if (!state->cmds)
		return (0);
	i = 0;
	while (i < state->argc - 3)
	{
		if (!cmd_process(state, i))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Executes commands, for all but the last one target is 0, for the last one
 * it's out file descriptor (to redirect to out instead of stdin)
 *
 * After starting all commands waits for the last one to terminate and
 * saves it's exit status
 */
int	cmds_exec(t_pipex_state *state)
{
	int	status;
	int	i;

	i = 0;
	while (i < state->argc - 4)
	{
		cmd_exec(state, i, 0);
		i++;
	}
	cmd_exec(state, i, state->out_fd);
	close(state->out_fd);
	if (waitpid(state->last_pid, &status, 0) == -1)
		panic_perror_exit(state, 1);
	if (WIFEXITED(status))
		state->exit_status = WEXITSTATUS(status);
	return (state_free(state), state->exit_status);
}
