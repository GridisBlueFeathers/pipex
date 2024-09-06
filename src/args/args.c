/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:19:26 by svereten          #+#    #+#             */
/*   Updated: 2024/09/06 13:54:32 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Checks if all quotes in arguments are closed
 */
int	args_check_quotes(char *arg)
{
	int		s_quote_count;
	int		d_quote_count;
	int		i;
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
 * Increments res and checks if res overflows, sets check to 0 if overflows
 */
static void	args_count_increment_res(size_t *res, int *check)
{
	size_t	prev;

	prev = *res;
	(*res)++;
	if (prev > *res)
		*check = 0;
}

/**
 * Returns amount of arguments in command
 */
size_t	args_count(char *s, int *check)
{
	int			i;
	size_t		res;
	char		quote;

	i = 0;
	res = 0;
	quote = 0;
	if (s[0] != ' ' && s[0])
		args_count_increment_res(&res, check);
	if (s[0] && (s[0] == '\'' || s[0] == '"'))
	{
		quote = s[0];
		args_count_increment_res(&res, check);
	}
	while (s[i])
	{
		if (!quote && s[i] == ' ' && s[i + 1] != ' ' && s[i + 1])
			args_count_increment_res(&res, check);
		if (!quote && i && (s[i] == '\'' || s[i] == '"'))
			quote = s[i];
		else if (quote && i && s[i] == quote)
			quote = 0;
		i++;
	}
	return (res);
}
