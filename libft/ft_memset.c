/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:20:08 by afesyk            #+#    #+#             */
/*   Updated: 2017/10/26 13:06:42 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char			*arr;
	size_t			i;
	unsigned char	b;

	arr = (char*)str;
	b = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		arr[i] = b;
		i++;
	}
	return (arr);
}
