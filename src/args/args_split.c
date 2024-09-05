/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:23:07 by svereten          #+#    #+#             */
/*   Updated: 2024/09/05 17:49:20 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "pipex.h"

static int	args_toggle_quote(char *quote, char *str, int i)
{
	if (*quote && str[i] == '\\' && str[i + 1] && str[i + 1] == *quote)
		return (1);
	if (!*quote && (str[i] == '\'' || str[i] == '"'))
	{
		*quote = str[i];
		return (1);
	}
	else if (*quote && str[i] == *quote)
	{
		*quote = 0;
		return (1);
	}
	return (0);
}

static int	arg_len(char *args, int start)
{
	int		res;
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	res = 0;
	while (args[start + i])
	{
		if (args_toggle_quote(&quote, args, start + i))
			start++;
		if (!quote && args[start + i] == ' ')
			break ;
		if ((!quote && args[start + i] != ' ') || quote)
			res++;
		i++;
	}
	return (res);
}

static int	arg_append_to_res(char **res, char *args, int start)
{
	int		j;
	int		i;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	while (res[j])
		j++;
	res[j] = (char *)ft_calloc(arg_len(args, start) + 1, sizeof(char));
	if (!res[j])
		return (0);
	while (args[start + i])
	{
		if (args_toggle_quote(&quote, args, start + i))
			start++;
		if (!quote && args[start + i] == ' ')
			break ;
		if ((!quote && args[start + i] != ' ') || quote)
			res[j][i] = args[start + i];
		i++;
	}
	return (1);
}

static int	args_iterate_split(char *args, char **res)
{
	int		i;
	int		check;
	char	quote;

	i = 0;
	check = 1;
	quote = 0;
	while (args[i] && check)
	{
		if (!i && args[i] != ' ')
			check = arg_append_to_res(res, args, i);
		else if (!quote && args[i] == ' ' && args[i + 1] != ' ' && args[i + 1])
			check = arg_append_to_res(res, args, i + 1);
		if (!quote && (args[i] == '\'' || args[i] == '"'))
			quote = args[i];
		else if (quote && args[i] == quote)
			quote = 0;
		i++;
	}
	if (!check)
		ft_free(STR_ARR, &res);
	return (check);
}

char	**args_split(char *args)
{
	char	**res;
	int		words_num;

	if (!args || !args_check_quotes(args))
		return (NULL);
	words_num = args_count(args);
	res = (char **)ft_calloc(words_num + 1, sizeof(char *));
	if (!res || !args_iterate_split(args, res))
		return (NULL);
	return (res);
}
