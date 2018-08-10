/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:00:52 by afesyk            #+#    #+#             */
/*   Updated: 2017/12/29 16:00:54 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstfold(t_list **lst, \
	long long (*f)(long long, long long))
{
	long long	ret;

	if (lst == NULL || f == NULL || *lst == NULL)
		return (-1);
	ret = (long long)(*lst)->content;
	while ((*lst)->next != NULL)
	{
		ret = f(ret, (long long)(*lst)->next->content);
		*lst = (*lst)->next;
	}
	if (ret > 2147483647 || ret < -2147483648)
		return (-1);
	return ((int)ret);
}
