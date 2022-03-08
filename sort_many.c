/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:36:33 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 15:17:40 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_a(t_struct *data)
{
	data->max = get_max(data);
	data->mid = get_mid(data, 0);
	push_from_a_2(data);
}

static void	first_process_a(t_struct *data)
{	
	data->next = get_elem_by_order(data, 1);
	data->max = get_max(data);
	data->mid = get_mid(data, -1);
	push_from_a(data);
}

static void	process_b(t_struct *data)
{
	int	i;

	i = 0;
	while (data->list_b)
	{
		data->max = get_max_b(data);
		data->mid = get_mid(data, 0);
		data->flag += 1;
		sort_b(data);
	}
}

static void	sort_heaps(t_struct *data)
{
	int		c_flag;

	while (data->list_a->flag != 0 && data->list_a->flag != -1)
	{
		c_flag = data->list_a->flag;
		while (data->list_a->flag == c_flag)
		{
			if (check_top_a(data) == 0)
				pb(data);
		}
		process_b(data);
	}
}

void	sort_many(t_struct *data)
{
	first_process_a(data);
	while (1)
	{
		process_b(data);
		sort_heaps(data);
		if (is_stack_sorted(data->list_a))
			return ;
		process_a(data);
	}
}
