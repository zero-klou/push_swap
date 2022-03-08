/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:35:07 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 15:03:25 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pointer_err(t_struct *data)
{
	free(data);
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int	is_sorted(int *numbers, t_struct *data)
{
	size_t	i;

	i = 0;
	while (i < data->size - 1)
	{
		if (numbers[i] > numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_duples(int *numbers, t_struct *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->size - 1)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
