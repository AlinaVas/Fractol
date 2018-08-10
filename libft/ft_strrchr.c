/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:03:18 by afesyk            #+#    #+#             */
/*   Updated: 2017/10/31 13:03:20 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

	str = (char*)s;
	while (*str != '\0')
		str++;
	if (c == '\0')
		return (str);
	else
		str--;
	len = ft_strlen(s);
	while (len-- > 0)
	{
		if (*str == c)
			return (str);
		str--;
	}
	return (NULL);
}
