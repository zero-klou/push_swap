/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:27:05 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/07 13:57:33 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (needle[0] == '\0')
		return ((char *) haystack);
	if (len == 0 || haystack[0] == '\0')
		return (0);
	i = 0;
	needle_len = ft_strlen(needle);
	while (ft_strncmp(&haystack[i], needle, needle_len) != 0)
	{
		i++;
		len--;
		while (haystack[i] != needle[0])
		{
			if (haystack[i] == '\0' || len < 1)
				return (0);
			len--;
			i++;
		}
		if (needle_len > len)
			return (0);
	}
	return ((char *) &haystack[i]);
}
