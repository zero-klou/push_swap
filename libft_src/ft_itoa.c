/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:51:34 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/12 18:18:31 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	res;

	if (n == 0)
		return (1);
	res = 0;
	if (n < 0)
		res++;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static long long	ft_modul(int n)
{
	if (n < 0)
		return ((long long) n * -1);
	return ((long long) n);
}

char	*ft_itoa(int n)
{
	int			len;
	long long	conv_n;
	char		*res;

	len = int_len(n);
	res = malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	res[len--] = '\0';
	conv_n = ft_modul(n);
	while (conv_n != 0)
	{
		res[len--] = conv_n % 10 + '0';
		conv_n /= 10;
	}
	return (res);
}
