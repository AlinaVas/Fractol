/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:01:55 by afesyk            #+#    #+#             */
/*   Updated: 2017/11/04 18:40:38 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_div(int n)
{
	int div;

	div = 1;
	if (n == -2147483648)
		return (1000000000);
	if (n < 0)
		n = n * (-1);
	while (n / div > 9)
		div = div * 10;
	return (div);
}

static int	num_len(int n)
{
	int l;

	l = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * (-1);
		l++;
	}
	while (n / 10 > 0)
	{
		l++;
		n /= 10;
	}
	return (l);
}

char		*ft_itoa(int n)
{
	char			*res;
	int				i;
	int				div;
	unsigned int	num;

	i = 0;
	num = (unsigned int)n;
	div = ft_div(num);
	res = (char*)malloc(sizeof(char) * (num_len(n) + 2));
	if (!res)
		return (NULL);
	if (n < 0 && ++i)
	{
		res[0] = '-';
		num = (-1) * num;
	}
	while (div >= 1)
	{
		res[i] = num / div + 48;
		num = num - (num / div) * div;
		div = div / 10;
		i++;
	}
	res[i] = '\0';
	return (res);
}
