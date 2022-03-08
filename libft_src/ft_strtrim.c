/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:39:48 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/13 12:41:12 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isch_inarr(char const *set, char ch)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	process_istart(char const *s1, char const *set, size_t *i_start)
{
	size_t	len;

	len = 0;
	while (s1[len] != '\0')
	{
		if (!isch_inarr(set, s1[len]))
		{
			*i_start = len;
			break ;
		}
		len++;
	}
}

static void	process_isend(char const *s1, char const *set, size_t *i_end)
{
	size_t	len;

	len = ft_strlen(s1) - 1;
	while (len >= 0)
	{
		if (!isch_inarr(set, s1[len]))
		{
			*i_end = len;
			break ;
		}
		len--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i_start;
	size_t	i_end;

	if (!s1)
		return (0);
	len = 0;
	i_start = 0;
	i_end = 0;
	process_istart(s1, set, &i_start);
	process_isend(s1, set, &i_end);
	len = i_end - i_start + 1;
	return (ft_substr(s1 + i_start, 0, len));
}
