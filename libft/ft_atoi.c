/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:01:48 by afesyk            #+#    #+#             */
/*   Updated: 2017/11/04 13:01:54 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_min(unsigned long long number, int sign, const char nptr)
{
	if (((number == 922337203685477580 && (nptr - '0' > 8)) ||
		number > 922337203685477580) && sign == -1)
		return (1);
	return (0);
}

static	int	is_max(unsigned long long number, int sign, const char nptr)
{
	if (((number == 922337203685477580 && (nptr - '0' > 7)) ||
		number > 922337203685477580) && sign == 1)
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	int					sign;
	unsigned long long	number;

	sign = 1;
	number = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' ||
		*nptr == '\v' || *nptr == '\r' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		if (is_max(number, sign, *nptr))
			return (-1);
		if (is_min(number, sign, *nptr))
			return (0);
		number = (number * 10) + (*nptr - '0');
		nptr++;
	}
	return ((int)(number * sign));
}
