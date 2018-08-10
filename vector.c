/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:07:10 by afesyk            #+#    #+#             */
/*   Updated: 2018/06/03 14:07:11 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_xyz	vecscale(t_xyz a, double n)
{
	a.x *= n;
	a.y *= n;
	a.z *= n;
	return (a);
}

t_xyz	vecadd(t_xyz a, t_xyz b)
{
	t_xyz	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_xyz	vecsub(t_xyz a, t_xyz b)
{
	t_xyz	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

double	veclen(t_xyz v)
{
	return (sqrt(vecdot(v, v)));
}

t_xyz	vecnorm(t_xyz a)
{
	double	len;

	len = veclen(a);
	a.x = a.x / len;
	a.y = a.y / len;
	a.z = a.z / len;
	return (a);
}
