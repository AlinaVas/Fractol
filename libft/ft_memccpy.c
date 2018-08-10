/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:35:15 by afesyk            #+#    #+#             */
/*   Updated: 2017/10/26 16:38:07 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	*dest;
	size_t			i;
	unsigned char	k;

	k = (unsigned char)c;
	src = (unsigned char*)str2;
	dest = (unsigned char*)str1;
	i = 0;
	while (i < n)
	{
		if (src[i] == k)
		{
			dest[i] = src[i];
			i++;
			str1++;
			return (str1);
		}
		dest[i] = src[i];
		i++;
		str1++;
	}
	return (NULL);
}
