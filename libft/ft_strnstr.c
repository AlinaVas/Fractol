/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:23:20 by afesyk            #+#    #+#             */
/*   Updated: 2017/10/31 15:23:21 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	l;

	if (!*little)
		return ((char*)big);
	i = 0;
	l = (int)len;
	while (big[i] != '\0' && i < l)
	{
		j = 0;
		while (little[j] == big[i + j] && i + j < l && little[j] != '\0')
		{
			j++;
			if (i + j <= l && little[j] == '\0')
				return ((char*)big + i);
		}
		i++;
	}
	return (NULL);
}
