/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers_many.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:53:45 by vaustin           #+#    #+#             */
/*   Updated: 2022/01/17 19:52:01 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	valid_number(t_struct *data, int *res, char *number)
{
	int	i;

	i = 0;
	if (number[0] == '-' && number[1] == '\0')
	{
		free(res);
		pointer_err(data);
	}
	while (number[i] != '\0')
	{
		if (!ft_isdigit(number[i]) && number[i] != '-')
		{
			free(res);
			pointer_err(data);
		}
		i++;
	}
}

static int	valid_int(long long checker, t_struct *data, int *res)
{
	if (checker < -2147483648 || checker > 2147483647)
	{
		free(res);
		pointer_err(data);
	}
	return ((int) checker);
}

int	*parse_numbers_many(int argc, char **argv, t_struct *data)
{
	size_t		i;
	int			*res;
	long long	checker;

	i = 0;
	data->size = argc - 1;
	res = malloc(sizeof(int) * data->size);
	if (!res)
		pointer_err(data);
	while (i < data->size)
	{
		valid_number(data, res, argv[i + 1]);
		checker = ft_atoi_mod(argv[i + 1]);
		res[i] = valid_int(checker, data, res);
		i++;
	}
	return (res);
}
