/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:28:32 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/12 18:20:10 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	res;
	int	i;
	int	w_flag;

	res = 0;
	i = 0;
	w_flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && w_flag == 0)
		{
			w_flag = 1;
			res++;
		}
		else if (s[i] == c && w_flag == 1)
			w_flag = 0;
		i++;
	}
	return (res);
}

static size_t	calc_word_len(char const **s, char c)
{
	size_t	i;

	i = 0;
	while (**s != c && **s != '\0')
	{
		i++;
		(*s)++;
	}
	return (i);
}

static int	malloc_error(char **res, int i)
{
	if (res[i] == 0)
	{
		while (i >= 0)
			free(res[i--]);
		free(res);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;
	int		w_count;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	w_count = count_word(s, c);
	res = (char **) ft_calloc(w_count + 1, sizeof(*res));
	if (res == 0)
		return (0);
	while (*s != '\0' && i < w_count)
	{
		while (*s == c)
			s++;
		res[i] = ft_substr(s, 0, calc_word_len(&s, c));
		if (malloc_error(res, i))
			return (0);
		i++;
	}
	res[i] = 0;
	return (res);
}
