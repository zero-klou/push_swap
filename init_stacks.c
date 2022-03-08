/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:57:49 by vaustin           #+#    #+#             */
/*   Updated: 2022/01/27 18:25:24 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(int *numbers, t_struct *data)
{
	size_t	i;
	t_elem	*list;
	t_elem	*temp;

	i = 0;
	list = 0;
	while (i < data->size)
	{
		temp = ft_lstnew_mod(numbers[i]);
		if (!temp)
		{
			ft_lstclear_mod(&list);
			return ;
		}
		ft_lstadd_back_mod(&list, temp);
		temp = 0;
		i++;
	}
	data->list_a = list;
}
