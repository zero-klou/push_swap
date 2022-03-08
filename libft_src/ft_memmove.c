/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:03:56 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/05 19:31:15 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*conv_src;
	char	*conv_dst;
	size_t	i;

	conv_src = (char *) src;
	conv_dst = (char *) dst;
	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			conv_dst[i] = conv_src[i];
			i++;
		}
	}
	else if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			conv_dst[i - 1] = conv_src[i - 1];
			i--;
		}
	}
	return (conv_dst);
}
