/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:19:26 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 15:18:04 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*get_max(t_struct *data)
{
	int	order;

	order = (int) data->size;
	return (get_elem_by_order(data, order));
}

t_elem	*get_max_b(t_struct *data)
{
	int		max;
	t_elem	*res;
	t_elem	*lst;

	max = -1;
	lst = data->list_b;
	res = 0;
	while (lst)
	{
		if (lst->order > max)
		{
			max = lst->order;
			res = lst;
		}
		lst = lst->next;
	}
	return (res);
}

t_elem	*get_elem_by_order(t_struct *data, int order)
{
	t_elem	*s_a;
	t_elem	*s_b;

	s_a = data->list_a;
	s_b = data->list_b;
	while (s_a)
	{
		if (s_a->order == order)
			return (s_a);
		s_a = s_a->next;
	}
	while (s_b)
	{
		if (s_b->order == order)
			return (s_b);
		s_b = s_b->next;
	}
	return (0);
}

t_elem	*get_mid(t_struct *data, int flag)
{
	int	order;

	if (flag == -1)
		order = data->max->order / 2 + data->next->order;
	else
		order = (data->max->order - data->next->order) / 2 + data->next->order;
	return (get_elem_by_order(data, order));
}

int	is_stack_sorted(t_elem *lst)
{
	while (lst->next)
	{
		if (lst->order > lst->next->order)
			return (0);
		lst = lst->next;
	}
	return (1);
}
