/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repcnk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:42:38 by afesyk            #+#    #+#             */
/*   Updated: 2017/12/14 11:50:48 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	replace(char *str, char *old, char *new, char *ret)
{
	int i;
	int n;

	i = -1;
	n = 0;
	while (str[++i] != '\0')
	{
		if (ft_strstr(&str[i], old) == &str[i])
		{
			ft_memmove(&ret[n], new, ft_strlen(new));
			n += ft_strlen(new);
			i += ft_strlen(old);
		}
		if (ft_strstr(&str[i], old) != &str[i])
			ret[n] = str[i];
		n++;
	}
	ret[n] = '\0';
}

char		*ft_repcnk(char *str, char *old, char *new)
{
	char	*ret;
	int		i;
	int		n;

	if (str == NULL || old == NULL)
		return (NULL);
	if (new == NULL)
		return (str);
	i = -1;
	n = 0;
	while (str[++i] != '\0')
	{
		if (ft_strstr(&str[i], old) == &str[i] && n++)
			i += ft_strlen(old) - 1;
	}
	ret = (char*)malloc(i + n * (ft_strlen(new) - ft_strlen(old)) + 1);
	if (ret == NULL)
		return (NULL);
	replace(str, old, new, ret);
	return (ret);
}
