/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:03:38 by afesyk            #+#    #+#             */
/*   Updated: 2017/12/29 16:03:40 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mod_strstr(const char *big, const char *little)
{
	char	*haystack;
	char	*needle;
	char	*res;

	haystack = (char*)big;
	needle = (char*)little;
	if (!needle)
		return (0);
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			res = haystack;
			while (*needle != '\0' && *haystack == *needle && haystack++)
				needle++;
			if (*needle == '\0')
				return (1);
		}
		haystack++;
		needle = (char*)little;
	}
	return (0);
}

void		ft_lstdelif(t_list **lst, const char *s)
{
	t_list	*tmp;
	t_list	*del;

	tmp = *lst;
	(!lst || !*lst || !s) ? (tmp = NULL) : 0;
	while (tmp != NULL && mod_strstr(tmp->content, s) == 1)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->next->next != NULL && mod_strstr(tmp->next->content, s) == 1)
		{
			del = tmp->next;
			tmp->next = tmp->next->next;
			ft_memdel((void**)&del);
		}
		else if (!(tmp->next->next) && mod_strstr(tmp->next->content, s) == 1)
			ft_memdel((void**)&(tmp->next));
		else
			tmp = tmp->next;
	}
}
