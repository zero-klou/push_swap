/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:21:28 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 15:28:17 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*numbers_parse(int argc, char **argv, t_struct *data)
{
	int	*numbers;

	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
		{
			free(data);
			exit(0);
		}
		numbers = parse_numbers_one(argv, data);
	}
	else
		numbers = parse_numbers_many(argc, argv, data);
	return (numbers);
}

static void	start_check(int argc)
{
	if (argc < 2)
		exit(0);
}

static void	numbers_check(int *numbers, t_struct *data)
{
	if (is_duples(numbers, data))
	{
		free(numbers);
		pointer_err(data);
	}
	if (is_sorted(numbers, data))
	{
		free(data);
		free(numbers);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_struct	*data;
	int			*numbers;

	start_check(argc);
	data = malloc(sizeof(t_struct) * 1);
	if (!data)
		return (0);
	numbers = numbers_parse(argc, argv, data);
	numbers_check(numbers, data);
	init_stack_a(numbers, data);
	data->list_b = 0;
	ft_quick_sort(numbers, data);
	ft_lstiter_order(numbers, data);
	free(numbers);
	lets_sort_already(data);
	ft_lstclear_mod(&(data->list_a));
	free(data);
	return (0);
}
