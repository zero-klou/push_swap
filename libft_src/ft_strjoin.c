/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:06:34 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/12 18:21:03 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	process_vars(int *len, int *i, int *j)
{
	*len = *len + *i;
	*i = 0;
	*j = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	if (s1 == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
		i++;
	len = i;
	i = 0;
	while (s2[i] != '\0')
		i++;
	process_vars(&len, &i, &j);
	res = malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	while (s1[i] != '\0')
		res[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
