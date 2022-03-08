/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:52:27 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/10 18:42:19 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*conv_src;
	char	*conv_dst;
	size_t	i;

	if (!dst && !src)
		return (0);
	conv_src = (char *) src;
	conv_dst = (char *) dst;
	i = 0;
	while (i < n)
	{
		conv_dst[i] = conv_src[i];
		i++;
	}
	return (conv_dst);
}
