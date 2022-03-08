/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:16:53 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/12 18:16:54 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*conv_s;

	i = 0;
	conv_s = (const char *) s;
	while (i < n)
	{
		if (conv_s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (0);
}
