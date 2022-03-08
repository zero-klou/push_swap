/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:38:51 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 15:15:43 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_flags(t_struct *data)
{
	t_elem	*lst;

	lst = data->list_a;
	while (lst)
	{
		lst->flag = 0;
		lst = lst->next;
	}
}

void	lets_sort_already(t_struct *data)
{
	set_flags(data);
	data->flag = 0;
	if (data->size <= 3)
		sort_three(data, 0);
	else if (data->size <= 5)
		sort_five_a(data);
	else
		sort_many(data);
}
