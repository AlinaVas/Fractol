/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:44:12 by afesyk            #+#    #+#             */
/*   Updated: 2017/11/09 17:44:14 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_count(char const *s, char c)
{
	int n;

	n = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			n++;
		s++;
	}
	return (n);
}

static int	str_len(char const *str, char c)
{
	int i;

	i = 0;
	while (*str == c)
		str++;
	if (*str != c && *str != '\0')
	{
		while (*str != c && *str != '\0')
		{
			i++;
			str++;
		}
	}
	return (i);
}

static void	free_array(char **array, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		free(array[i]);
	free(array);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		n;
	int		i;

	if (!s || !(array = (char**)malloc(sizeof(char*) * (str_count(s, c) + 1))))
		return (NULL);
	n = -1;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			array[++n] = ft_strsub(s, i, str_len(&s[i], c));
			if (!array[n])
			{
				free_array(array, n);
				return (NULL);
			}
			i = i + str_len(&s[i], c) - 1;
		}
	}
	array[++n] = 0;
	return (array);
}
