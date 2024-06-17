/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:12:04 by svereten          #+#    #+#             */
/*   Updated: 2024/06/17 18:44:01 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

typedef struct	s_command
{
	char *path;
	char **args;
}	t_command;

typedef struct	s_pipex_state
{
	int			infile_fd;
	int			outfile_fd;
	int			argc;
	int			error;
	int			path_length;
	char		**argv;
	char		**envp;
	char		**path;
	t_command	**commands;
}	t_pipex_state;

char	*env_get(t_pipex_state *state, char *env);

int		path_get(t_pipex_state *state);
void	path_free(t_pipex_state *state);

#endif
