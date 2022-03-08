/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:04:29 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/12 18:20:58 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;
	int		s1_size;

	i = 0;
	s1_size = 0;
	while (s1[s1_size] != '\0')
		s1_size++;
	res = malloc(s1_size + 1);
	if (res == 0)
		return (0);
	while (i < s1_size)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
