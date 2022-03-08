/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:47:30 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/11 22:05:57 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{	
	t_list	*next;

	if (!*lst)
		return ;
	while (*lst)
	{
		next = (*(lst))->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}
