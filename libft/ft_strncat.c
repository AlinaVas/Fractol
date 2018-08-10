/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:22:44 by afesyk            #+#    #+#             */
/*   Updated: 2017/10/28 17:22:46 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if ((!*s1 && !*s2) || n == 0)
		return (s1);
	tmp = (char*)s2;
	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (j < n && tmp[j] != '\0')
	{
		s1[i + j] = tmp[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
