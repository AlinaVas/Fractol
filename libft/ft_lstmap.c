/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:36:54 by afesyk            #+#    #+#             */
/*   Updated: 2017/11/15 19:36:55 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;
	t_list *ret;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = (*f)(lst);
	ret = tmp;
	lst = lst->next;
	while (lst != NULL)
	{
		new = (*f)(lst);
		tmp->next = new;
		tmp = new;
		lst = lst->next;
	}
	tmp->next = NULL;
	return (ret);
}
