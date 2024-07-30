/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:19:26 by svereten          #+#    #+#             */
/*   Updated: 2024/07/30 16:55:46 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	args_count(char const *s, char c)
{
	int		i;
	int		res;
	char	quote;

	i = 0;
	res = 0;
	quote = 0;
	if (s[0] != c && s[0])
		res++;
	if (s[0] && (s[0] == '\'' || s[0] == '"'))
	{
		quote = s[0];
		res++;
	}
	while (s[i])
	{
		if (!quote && s[i] == c && s[i + 1] != c && s[i + 1])
			res++;
		if (!quote && i && (s[i] == '\'' || s[i] == '"'))
			quote = s[i];
		else if (quote && i && s[i] == quote)
			quote = 0;
		i++;
	}
	return (res);
}
