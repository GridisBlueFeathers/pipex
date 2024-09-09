/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:12:04 by svereten          #+#    #+#             */
/*   Updated: 2024/09/09 11:01:41 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>

typedef struct	s_cmd
{
	char *path;
	char **args;
}	t_cmd;

typedef struct	s_pipex_state
{
	int			argc;
	int			error;
	int			exit_status;
	int			path_length;
	int			in_fd;
	int			out_fd;
	pid_t		last_pid;
	char		**argv;
	char		**envp;
	char		**path;
	t_cmd		**cmds;
}	t_pipex_state;

int		pipex(int argc, char **argv, char **envp);

void	state_init(t_pipex_state *s, int c, char **v, char **e);
void	state_feed(t_pipex_state *state);
void	state_free(t_pipex_state *state);

int		cmds_process(t_pipex_state *state);

int		cmd_process(t_pipex_state *state, int i);

char	*env_get(t_pipex_state *state, char *env);

int		path_get(t_pipex_state *state);
void	path_free(t_pipex_state *state);

char	**args_split(char *s);
size_t	args_count(char *s);
int		args_check_quotes(char *arg);

void	state_fd_get_in_out(t_pipex_state *s);

void	panic_msg_exit(t_pipex_state *state, char *msg, int status);

#endif
