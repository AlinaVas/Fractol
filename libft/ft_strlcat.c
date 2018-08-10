/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:37:51 by afesyk            #+#    #+#             */
/*   Updated: 2017/10/29 14:38:32 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	space_left;
	size_t	i;
	size_t	j;

	if (size == 0 && !dst)
		return (ft_strlen(src));
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	space_left = size - ft_strlen(dst);
	j = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && space_left > 1)
	{
		dst[i + j] = src[i];
		space_left--;
		i++;
	}
	dst[j + i] = '\0';
	return (j + ft_strlen(src));
}
