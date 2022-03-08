/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:47:25 by vaustin           #+#    #+#             */
/*   Updated: 2022/01/26 18:58:43 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_mod(t_elem **lst, t_elem *new)
{
	t_elem	*lstlast;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lstlast = ft_lstlast_mod(*lst);
	lstlast->next = new;
}

t_elem	*ft_lstnew_mod(int content)
{
	t_elem	*res;

	res = malloc(sizeof(t_elem));
	if (res == 0)
		return (0);
	res->value = content;
	res->order = 0;
	res->flag = 0;
	res->next = 0;
	return (res);
}

t_elem	*ft_lstlast_mod(t_elem *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear_mod(t_elem **lst)
{	
	t_elem	*next;

	if (!*lst)
		return ;
	while (*lst)
	{
		next = (*(lst))->next;
		(*(lst))->next = 0;
		(*(lst))->value = 0;
		(*(lst))->order = 0;
		(*(lst))->flag = 0;
		free(*(lst));
		*lst = next;
	}
}

void	ft_lstiter_order(int *numbers, t_struct *data)
{
	size_t	i;
	t_elem	*temp;

	i = 0;
	while (i < data->size)
	{
		temp = data->list_a;
		while (temp)
		{
			if (numbers[i] == temp->value && temp->order == 0)
			{
				temp->order = i + 1;
				break ;
			}
			temp = temp->next;
		}
		i++;
	}
}
