/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:33:59 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 15:44:28 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_a(t_struct *data, int var)
{
	if (var == 1)
	{
		ra(data);
		sa(data);
	}
	else if (var == 2)
		sa(data);
	else if (var == 3)
		ra(data);
	else if (var == 4)
	{
		rra(data, 0);
		sa(data);
	}
	else if (var == 5)
		rra(data, 0);
}

static void	sort_stack_b(t_struct *data, int var)
{
	if (var == 1)
	{
		rb(data);
		sb(data);
	}
	else if (var == 2)
		sb(data);
	else if (var == 3)
		rb(data);
	else if (var == 4)
	{
		rrb(data, 0);
		sb(data);
	}
	else if (var == 5)
		rrb(data, 0);
}

static void	process_stack(t_elem *s1, t_elem *s2, t_elem *s3, int *var)
{
	if (s1->order > s2->order && s1->order > s3->order)
	{
		if (s2->order > s3->order)
			*var = 1;
		else
			*var = 3;
	}
	else if (s1->order == (s3->order + s2->order) / 2)
	{
		if (s2->order < s3->order)
			*var = 2;
		else
			*var = 5;
	}
	else if (s1->order < s2->order && s2->order > s3->order)
		*var = 4;
}

void	sort_three(t_struct *data, int f)
{
	int		var;
	t_elem	*stack_1;
	t_elem	*stack_2;
	t_elem	*stack_3;

	var = 0;
	if (f == 0)
		stack_1 = data->list_a;
	else
		stack_1 = data->list_b;
	stack_2 = stack_1->next;
	if (stack_2->next != 0)
		stack_3 = stack_1->next->next;
	else
		stack_3 = stack_2;
	process_stack(stack_1, stack_2, stack_3, &var);
	if (f == 0)
		sort_stack_a(data, var);
	else
		sort_stack_b(data, var);
}
