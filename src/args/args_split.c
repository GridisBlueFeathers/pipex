/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:23:07 by svereten          #+#    #+#             */
/*   Updated: 2024/08/21 15:47:20 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "pipex.h"

static void	ft_free_split(char **res, int words_amount)
{
	int	i;

	i = 0;
	while (i < words_amount)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	ft_append_to_res(char **res, char const *s, char c, int start)
{
	int		j;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i + start] != c && s[i + start])
	{
		i++;
		len++;
	}
	j = 0;
	while (res[j])
		j++;
	res[j] = ft_substr(ft_strdup(s), start, len);
	if (!res[j])
		return (0);
	return (1);
}

static int	iterate_split(char *s, char **res, int size)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	while (s[i])
	{
		if (!i && s[i] != ' ')
			check = ft_append_to_res(res, s, ' ', i);
		else if (s[i] == ' ' && s[i + 1] != ' ' && s[i + 1])
			check = ft_append_to_res(res, s, ' ', i + 1);
		if (!check)
		{
			ft_free_split(res, size);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**args_split(char *s)
{
	char	**res;
	int		words_num;

	if (!s || !args_check_quotes(s))
		return (NULL);
	words_num = args_count(s);
	res = (char **)ft_calloc(words_num + 1, sizeof(char *));
	if (!res && !iterate_split(s, res, words_num))
		return (NULL);
	return (res);
}
