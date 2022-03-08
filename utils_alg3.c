/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_alg3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:19:16 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 15:19:25 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_top_a(t_struct *data)
{
	if (data->list_a->order == data->next->order)
	{
		data->list_a->flag = -1;
		ra(data);
		data->next = get_elem_by_order(data, data->next->order + 1);
		return (1);
	}
	return (0);
}

void	push_from_b_less_five(t_struct *data)
{
	while (data->list_b)
	{
		data->list_b->flag = data->flag;
		pa(data);
		check_top_a(data);
	}
}

void	push_from_b(t_struct *data)
{
	int	i;

	i = len_push_a(data, data->list_b);
	while (i >= 0)
	{
		if (data->list_b->order >= data->mid->order)
		{
			data->list_b->flag = data->flag;
			pa(data);
			check_top_a(data);
			i--;
			continue ;
		}
		rb(data);
	}
}

void	sort_b(t_struct *data)
{
	t_elem	*stack_b;
	size_t	len;

	stack_b = data->list_b;
	len = ft_lstsize_mod(stack_b);
	if (len == 1)
	{
		push_from_b_less_five(data);
	}
	else if (len <= 3)
	{
		sort_three(data, 1);
		push_from_b_less_five(data);
	}
	else if (len <= 5)
	{
		sort_five_b(data);
		check_top_a(data);
		check_top_a(data);
		push_from_b_less_five(data);
	}
	else
		push_from_b(data);
}
