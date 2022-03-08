/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:46:47 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/05 17:41:51 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	conv_c;
	char			*conv_b;
	size_t			i;

	conv_c = (unsigned char) c;
	conv_b = (char *) b;
	i = 0;
	while (i < len)
	{
		conv_b[i] = conv_c;
		i++;
	}
	return (conv_b);
}
