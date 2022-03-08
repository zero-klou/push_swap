/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:35:26 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 15:42:59 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_struct *data, int f)
{
	t_elem	*pre_last;

	if (ft_lstsize_mod(data->list_a) < 2)
		return ;
	pre_last = ft_lst_prelast_mod(data->list_a);
	pre_last->next->next = data->list_a;
	data->list_a = pre_last->next;
	pre_last->next = 0;
	if (!f)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_struct *data, int f)
{
	t_elem	*pre_last;

	if (ft_lstsize_mod(data->list_b) < 2)
		return ;
	pre_last = ft_lst_prelast_mod(data->list_b);
	pre_last->next->next = data->list_b;
	data->list_b = pre_last->next;
	pre_last->next = 0;
	if (!f)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_struct *data)
{
	rra(data, 1);
	rrb(data, 1);
	ft_putstr_fd("rrr\n", 1);
}
