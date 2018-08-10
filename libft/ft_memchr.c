/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:53:53 by afesyk            #+#    #+#             */
/*   Updated: 2017/10/27 19:59:32 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char			a;
	const unsigned char		*tmp;
	size_t					i;

	a = (unsigned char)c;
	tmp = (const unsigned char*)str;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == a)
			return ((void*)str);
		i++;
		str++;
	}
	return (NULL);
}
