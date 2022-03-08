/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:29:49 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 15:07:36 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
		i++;
	return (i);
}

static void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != 0)
		free(strs[i++]);
	free(strs);
}

static void	valid_number(t_struct *data, char **strs, int *res, char *number)
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
			free_strs(strs);
			free(res);
			pointer_err(data);
		}
		i++;
	}
}

static int	valid_int(long long checker, t_struct *data, char **strs, int *res)
{
	if (checker < -2147483648 || checker > 2147483647)
	{
		free_strs(strs);
		free(res);
		pointer_err(data);
	}
	return ((int) checker);
}

int	*parse_numbers_one(char **argv, t_struct *data)
{
	int			i;
	char		**strs;
	int			*res;
	long long	checker;

	strs = ft_split(argv[1], ' ');
	if (!strs)
		pointer_err(data);
	data->size = arr_len(strs);
	res = malloc(sizeof(int) * data->size);
	if (!res)
	{
		free_strs(strs);
		pointer_err(data);
	}
	i = 0;
	while (strs[i] != 0)
	{
		valid_number(data, strs, res, strs[i]);
		checker = ft_atoi_mod(strs[i]);
		res[i] = valid_int(checker, data, strs, res);
		i++;
	}
	free_strs(strs);
	return (res);
}
