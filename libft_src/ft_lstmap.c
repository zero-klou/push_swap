/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:50:44 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/12 17:46:57 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new;
	t_list	*next;

	if (!lst)
		return (0);
	res = 0;
	while (lst)
	{
		next = lst->next;
		if ((*f)(lst->content))
		{
			new = ft_lstnew((*f)(lst->content));
			if (!new)
				return (0);
			ft_lstadd_back(&res, new);
		}
		else
			ft_lstdelone(lst, del);
		lst = next;
	}
	return (res);
}
