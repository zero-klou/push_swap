/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:25:54 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/10 18:45:21 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*conv_s1;
	const char	*conv_s2;

	i = 0;
	conv_s1 = (const char *) s1;
	conv_s2 = (const char *) s2;
	while (i < n)
	{
		if (conv_s1[i] != conv_s2[i])
			return ((unsigned char) conv_s1[i] - (unsigned char) conv_s2[i]);
		i++;
	}
	return (0);
}
