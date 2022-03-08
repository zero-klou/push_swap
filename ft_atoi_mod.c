/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:24:15 by vaustin           #+#    #+#             */
/*   Updated: 2022/01/17 19:50:46 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_res(int *fig_flag, long long *res, char ch)
{
	*fig_flag = 1;
	*res = (long long)(10 * *res + (ch - 48));
}

static void	process_sign(int *sign_flag, char ch)
{
	if (ch == '-')
		*sign_flag = -1;
	else
		*sign_flag = 1;
}

static int	ft_isspace3(char ch, int fig_flag, int sign_flag)
{
	if ((ch == ' ' || ch == '\f' || ch == '\n'
			|| ch == '\r' || ch == '\t'
			|| ch == '\v') && fig_flag == 0
		&& sign_flag == 0)
	{
		return (1);
	}
	return (0);
}

static void	process_vars(int *i, long long *res, int *sign_flag, int *fig_flag)
{
	*i = 0;
	*res = 0;
	*sign_flag = 0;
	*fig_flag = 0;
}

long long	ft_atoi_mod(const char *str)
{
	int			i;
	long long	res;
	int			sign_flag;
	int			fig_flag;

	process_vars(&i, &res, &sign_flag, &fig_flag);
	while (str[i] != '\0')
	{
		if ((str[i] == '+' || str[i] == '-') && sign_flag == 0 && fig_flag == 0)
			process_sign(&sign_flag, str[i]);
		else if (str[i] >= '0' && str[i] <= '9')
			process_res(&fig_flag, &res, str[i]);
		else if (ft_isspace3(str[i], fig_flag, sign_flag))
			;
		else
			return (-2147483649);
		i++;
	}
	if (sign_flag != 0)
		return (res * sign_flag);
	return (res);
}
