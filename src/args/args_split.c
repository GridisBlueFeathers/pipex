/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:23:07 by svereten          #+#    #+#             */
/*   Updated: 2024/08/22 15:30:32 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>

static void	ft_free_split(char **res, int words_amount, int check)
{
	int	i;

	if (check)
		return ;
	i = 0;
	while (i < words_amount)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

int	args_toggle_quote(char *quote, char cur)
{
	if (!*quote && (cur == '\'' || cur == '"'))
	{
		*quote = cur;
		return (1);
	}
	else if (*quote && cur == *quote)
	{
		*quote = 0;
		return (1);
	}
	return (0);
}

static int	ft_append_to_res(char **res, char *args, int start)
{
	int		j;
	int		i;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	while (res[j])
		j++;
	res[j] = (char *)ft_calloc(1, 100); // fix this later
	if (!res[j])
		return (0);
	while (args[start + i])
	{
		if (args_toggle_quote(&quote, args[start + i]))
			start++;
		if (!quote && args[start + i] == ' ')
			break ;
		if ((!quote && args[start + i] != ' ') || quote)
			res[j][i] = args[start + i];
		i++;
	}
	return (1);
}

static int	iterate_split(char *args, char **res, int size)
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
			check = ft_append_to_res(res, args, i);
		else if (!quote && args[i] == ' ' && args[i + 1] != ' ' && args[i + 1])
		{
			check = ft_append_to_res(res, args, i + 1);
			printf("%c\n", args[i + 1]);
		}
		if (!quote && (args[i] == '\'' || args[i] == '"'))
			quote = args[i];
		else if (quote && args[i] == quote)
			quote = 0;
		i++;
	}
	return (ft_free_split(res, size, check), check);
}

char	**args_split(char *args)
{
	char	**res;
	int		words_num;

	if (!args || !args_check_quotes(args))
		return (NULL);
	words_num = args_count(args);
	res = (char **)ft_calloc(words_num + 1, sizeof(char *));
	if (!res || !iterate_split(args, res, words_num))
		return (NULL);
	return (res);
}
