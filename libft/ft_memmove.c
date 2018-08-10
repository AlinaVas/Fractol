/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:53:42 by afesyk            #+#    #+#             */
/*   Updated: 2017/10/27 16:04:10 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dest;

	src = (unsigned char*)str2;
	dest = (unsigned char*)str1;
	if (src < dest)
		while (n-- > 0)
			dest[n] = src[n];
	else
		dest = (unsigned char*)ft_memcpy(str1, str2, n);
	return ((void*)dest);
}
