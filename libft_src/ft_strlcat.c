/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:15:33 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/06 15:13:58 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;
	size_t	src_size;
	size_t	dst_len;

	src_size = 0;
	dst_len = 0;
	while (src[src_size] != '\0')
		src_size++;
	while (dst[dst_len] != '\0')
		dst_len++;
	if (dstsize < dst_len || dstsize == 0)
		return (src_size + dstsize);
	j = 0;
	i = dst_len;
	while (i < dstsize - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (src_size + dst_len);
}
