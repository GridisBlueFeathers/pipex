/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:12:04 by svereten          #+#    #+#             */
/*   Updated: 2024/09/11 15:07:53 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>

typedef enum e_pipe
{
	RD,
	WR
}	t_pipe;

typedef struct s_cmd
{
	char	*path;
	char	**args;
	int		exec;
	int		in_path;
}	t_cmd;

typedef struct s_pipex_state
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
int		cmds_exec(t_pipex_state *state);

int		cmd_process(t_pipex_state *state, int i);
void	cmd_exec(t_pipex_state *state, int i, int target);

char	*env_get(t_pipex_state *state, char *env);

int		path_get(t_pipex_state *state);
void	path_free(t_pipex_state *state);

char	**args_split(char *s);
size_t	args_count(char *s);
int		args_check_quotes(char *arg);

void	state_fd_get_in_out(t_pipex_state *s);

void	panic_msg_exit(t_pipex_state *state, char *msg, int status);
void	panic_perror_exit(t_pipex_state *state, int status);
void	panic_silent_exit(t_pipex_state *state, int status);

void	dup2_wrapper(t_pipex_state *state, int old, int new);
void	close_wrapper(t_pipex_state *state, int fd);

#endif
