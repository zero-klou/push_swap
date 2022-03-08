/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:35:02 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 14:45:11 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_struct *data)
{
	t_elem	*last;

	if (ft_lstsize_mod(data->list_a) < 2)
		return ;
	last = ft_lstlast_mod(data->list_a);
	last->next = data->list_a;
	data->list_a = data->list_a->next;
	last->next->next = 0;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_struct *data)
{
	t_elem	*last;

	if (ft_lstsize_mod(data->list_b) < 2)
		return ;
	last = ft_lstlast_mod(data->list_b);
	last->next = data->list_b;
	data->list_b = data->list_b->next;
	last->next->next = 0;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_struct *data)
{
	ra(data);
	rb(data);
	ft_putstr_fd("rr\n", 1);
}
