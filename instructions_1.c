/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:44:20 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 14:43:55 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_struct *data)
{
	t_elem	*tmp;
	t_elem	*tmp_next;

	if (data->list_a == 0 || ft_lstsize_mod(data->list_a) < 2)
		return ;
	tmp = data->list_a;
	data->list_a = data->list_a->next;
	tmp_next = data->list_a->next;
	data->list_a->next = tmp;
	tmp->next = tmp_next;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_struct *data)
{
	t_elem	*tmp;
	t_elem	*tmp_next;

	if (data->list_b == 0 || ft_lstsize_mod(data->list_b) < 2)
		return ;
	tmp = data->list_b;
	data->list_b = data->list_b->next;
	tmp_next = data->list_b->next;
	data->list_b->next = tmp;
	tmp->next = tmp_next;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_struct *data)
{
	sa(data);
	sb(data);
}

void	pb(t_struct *data)
{
	t_elem	*temp;

	if (data->list_a == 0)
		return ;
	temp = data->list_a;
	data->list_a = data->list_a->next;
	ft_lstadd_front_mod(&(data->list_b), temp);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_struct *data)
{
	t_elem	*temp;

	if (data->list_b == 0)
		return ;
	temp = data->list_b;
	data->list_b = data->list_b->next;
	ft_lstadd_front_mod(&(data->list_a), temp);
	ft_putstr_fd("pa\n", 1);
}
