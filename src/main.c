/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:53:12 by svereten          #+#    #+#             */
/*   Updated: 2024/09/09 18:41:20 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	state_cmds_run(t_pipex_state *state)
{
	int	status;
	int	i;

	if (state->in_fd > 0)
		dup2(state->in_fd, STDIN_FILENO);
	close(state->in_fd);
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

int	main(int argc, char **argv, char **envp)
{
	t_pipex_state	state;

	if (argc < 5)
		return (1);
	state_init(&state, argc, argv, envp);
	state_feed(&state);
	if (state.error)
		return (state_free(&state), 127);
	return (state_cmds_run(&state));
}
