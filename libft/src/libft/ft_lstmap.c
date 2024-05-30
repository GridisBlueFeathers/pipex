/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:34:23 by svereten          #+#    #+#             */
/*   Updated: 2024/05/16 13:48:15 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*next;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	res = 0;
	while (lst)
	{
		content = f(lst->content);
		if (content)
		{
			next = ft_lstnew(content);
			if (next)
			{
				ft_lstadd_back(&res, next);
				lst = lst->next;
				continue ;
			}
			del(content);
		}
		ft_lstclear(&res, del);
		return (NULL);
	}
	return (res);
}
