/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:17:12 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/12 18:19:53 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long		nb;
	char			res[10];
	int				i;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	nb = n;
	i = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	while (nb != 0)
	{
		res[i++] = nb % 10 + '0';
		nb /= 10;
	}
	i--;
	while (i >= 0)
		ft_putchar_fd(res[i--], fd);
}
