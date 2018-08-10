/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splittolst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:06:47 by afesyk            #+#    #+#             */
/*   Updated: 2017/12/29 16:06:50 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		str_count(char const *s, char c)
{
	int n;

	if (s == NULL)
		return (-1);
	n = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			n++;
		s++;
	}
	return (n);
}

static size_t	mod_strlen(char const *s, char c)
{
	int i;

	i = 0;
	while (*s == c)
		s++;
	if (s[i] != c && s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (i);
}

static char		*mod_strsub(char const *s, size_t len)
{
	char	*str;
	size_t	i;

	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_list			*ft_splittolst(char const *s, char c)
{
	int			n;
	int			i;
	t_list		*ret;
	t_list		*tmp;

	i = -1;
	n = str_count(s, c);
	(n == -1 || n == 0) ? (ret = NULL) : 0;
	while (n != 0 && n != -1 && s[++i] != '\0')
	{
		if (s[i] != c && n == str_count(s, c) && \
			(tmp = malloc(sizeof(t_list))))
			(tmp != NULL) ? (ret = tmp) : (NULL);
		if (s[i] != c && tmp != NULL && n--)
		{
			tmp->content_size = mod_strlen(&s[i], c);
			tmp->content = mod_strsub(&s[i], tmp->content_size);
			i += tmp->content_size;
			(n == 0) ? (tmp->next = NULL) : \
			(tmp->next = malloc(sizeof(t_list)));
			tmp = tmp->next;
		}
	}
	return (ret);
}
