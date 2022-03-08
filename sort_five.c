/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:35:18 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 15:16:47 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_order(t_elem *lst)
{
	int	min;

	min = 2147483647;
	while (lst)
	{
		if (lst->order < min)
			min = lst->order;
		lst = lst->next;
	}
	return (min);
}

static void	move_2_a(t_struct *data)
{
	int	i;
	int	m_o;

	i = 0;
	m_o = min_order(data->list_a);
	while (i < 2)
	{
		if (data->list_a->order == m_o || data->list_a->order == m_o + 1)
		{
			pb(data);
			i++;
		}
		else
			ra(data);
	}
	if (data->list_b->order < data->list_b->next->order)
		sb(data);
}

static void	move_2_b(t_struct *data)
{
	int	i;
	int	m_o;

	i = 0;
	m_o = min_order(data->list_b);
	while (i < 2)
	{
		if (data->list_b->order == m_o || data->list_b->order == m_o + 1)
		{
			pa(data);
			i++;
		}
		else
			rb(data);
	}
	if (data->list_a->order > data->list_a->next->order)
		sa(data);
}

void	sort_five_a(t_struct *data)
{
	move_2_a(data);
	sort_three(data, 0);
	pa(data);
	pa(data);
}

void	sort_five_b(t_struct *data)
{
	move_2_b(data);
	sort_three(data, 1);
}
