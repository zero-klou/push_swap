/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_alg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:09:15 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 15:45:16 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_push(t_struct *data, t_elem *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		if (lst->order < data->mid->order && lst->flag != -1)
			len++;
		lst = lst->next;
	}
	return (len);
}

int	len_push_a(t_struct *data, t_elem *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		if (lst->order > data->mid->order)
			len++;
		lst = lst->next;
	}
	return (len);
}

void	push_from_a(t_struct *data)
{
	int	i;

	i = len_push(data, data->list_a);
	while (i >= 0)
	{
		if (data->list_a->order <= data->mid->order)
		{
			pb(data);
			i--;
			continue ;
		}
		ra(data);
	}
}

void	push_from_a_2(t_struct *data)
{
	int	i;
	int	back;

	back = 0;
	i = len_push(data, data->list_a);
	while (i >= 0)
	{
		if (data->list_a->order <= data->mid->order)
		{
			pb(data);
			i--;
			continue ;
		}
		ra(data);
		back++;
	}
	rotate_back_a_b(data, back);
}

void	rotate_back_a_b(t_struct *data, int back)
{
	while (back > 0)
	{
		if (data->list_b->next != data->next)
			rrr(data);
		else
			rra(data, 0);
		back--;
	}
}
