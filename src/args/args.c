/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:19:26 by svereten          #+#    #+#             */
/*   Updated: 2024/09/09 11:02:08 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Checks if all quotes in arguments are closed
 */
int	args_check_quotes(char *arg)
{
	size_t	s_quote_count;
	size_t	d_quote_count;
	size_t	i;
	char	quote;

	i = 0;
	s_quote_count = 0;
	d_quote_count = 0;
	quote = 0;
	while (arg[i])
	{
		if (!quote && arg[i] == '\'')
			s_quote_count++;
		if (!quote && arg[i] == '"')
			d_quote_count++;
		if (!quote && (arg[i] == '\'' || arg[i] == '"'))
			quote = arg[i];
		else if (quote && arg[i] == quote)
			quote = 0;
		i++;
	}
	if (s_quote_count % 2 && d_quote_count % 2)
		return (0);
	return (1);
}

/**
 * Returns amount of arguments in command
 */
size_t	args_count(char *s)
{
	int			i;
	size_t		res;
	char		quote;

	i = 0;
	res = 0;
	quote = 0;
	if (s[0] != ' ' && s[0])
		res++;
	if (s[0] && (s[0] == '\'' || s[0] == '"'))
	{
		quote = s[0];
		res++;
	}
	while (s[i])
	{
		if (!quote && s[i] == ' ' && s[i + 1] != ' ' && s[i + 1])
			res++;
		if (!quote && i && (s[i] == '\'' || s[i] == '"'))
			quote = s[i];
		else if (quote && i && s[i] == quote)
			quote = 0;
		i++;
	}
	return (res);
}
