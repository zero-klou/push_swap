/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:11:48 by vaustin           #+#    #+#             */
/*   Updated: 2022/01/19 15:43:07 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

static void	process_lr(int *numbers, int *left, int *right, int pivot)
{
	while (*left < *right)
	{
		while ((numbers[*right] >= pivot) && (*left < *right))
			*right -= 1;
		if (*left != *right)
		{
			ft_swap(&numbers[*left], &numbers[*right]);
			*left += 1;
		}
		while ((numbers[*left] <= pivot) && (*left < *right))
			*left += 1;
		if (*left != *right)
		{
			ft_swap(&numbers[*left], &numbers[*right]);
			*right -= 1;
		}
	}
}

static void	quick_sort(int *numbers, int left, int right)
{
	int	pivot;
	int	l_hold;
	int	r_hold;

	pivot = numbers[left];
	l_hold = left;
	r_hold = right;
	process_lr(numbers, &left, &right, pivot);
	ft_swap(&numbers[right], &pivot);
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		quick_sort(numbers, left, pivot - 1);
	if (right > pivot)
		quick_sort(numbers, pivot + 1, right);
}

void	ft_quick_sort(int *numbers, t_struct *data)
{	
	quick_sort(numbers, 0, data->size - 1);
}
