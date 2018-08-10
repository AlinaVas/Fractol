/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 15:50:55 by afesyk            #+#    #+#             */
/*   Updated: 2018/03/17 16:09:39 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **ptr, size_t size)
{
	char	*s;
	size_t	ptrlen;

	if (!size)
	{
		if (*ptr)
			ft_memdel(ptr);
		return (NULL);
	}
	s = (char*)ft_memalloc(size);
	if (!*ptr && s)
		return ((void*)s);
	ptrlen = ft_strlen(*ptr);
	if (ptrlen < size)
		size = ptrlen;
	s = (char*)ft_memmove((void*)s, *ptr, size);
	ft_memdel(ptr);
	return ((void*)s);
}
