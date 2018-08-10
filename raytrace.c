/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:06:26 by afesyk            #+#    #+#             */
/*   Updated: 2018/06/03 14:06:27 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_xyz	ray_direction(double x, double y, t_mlx *p)
{
	t_xyz	rd;
	double	tmp;
	double	proportion;

	proportion = (double)WIN_X / (double)WIN_Y;
	x = ((x / WIN_X) * p->viewport_x - p->viewport_x / 2) * proportion;
	y = -(y / WIN_Y) * p->viewport_y + p->viewport_y / 2;
	rd = (t_xyz){x, y, p->d};
	rd.y = y * cos(p->camdir.x) - p->d * sin(p->camdir.x);
	rd.z = y * sin(p->camdir.x) + p->d * cos(p->camdir.x);
	rd.x = x * cos(p->camdir.y) + rd.z * sin(p->camdir.y);
	rd.z = -x * sin(p->camdir.y) + rd.z * cos(p->camdir.y);
	tmp = rd.x;
	rd.x = rd.x * cos(p->camdir.z) + rd.y * sin(p->camdir.z);
	rd.y = -tmp * sin(p->camdir.z) + rd.y * cos(p->camdir.z);
	return (vecnorm(rd));
}

double	trace_viewing_ray(t_mlx *p)
{
	t_obj	*curr;
	double	i;

	curr = p->scene;
	p->intersect.scalar = TMAX;
	p->intersect.obj = NULL;
	while (curr)
	{
		i = curr->find_intersection(curr, p->cam, p->rd);
		if (i >= 1 && i < p->intersect.scalar)
		{
			p->intersect.scalar = i;
			p->intersect.obj = curr;
		}
		curr = curr->next;
	}
	if (!p->intersect.obj)
		return (0);
	return (1);
}

double	trace_shadow_ray(t_light *l, t_mlx *p)
{
	t_obj	*curr;
	t_obj	*closest;
	double	closest_b;
	double	light_distance;
	double	i;

	curr = p->scene;
	light_distance = veclen(l->dir);
	l->dir = vecnorm(l->dir);
	closest_b = light_distance;
	closest = NULL;
	while (curr)
	{
		i = curr->find_intersection(curr, p->intersect.point, l->dir);
		if (i > 0.0001 && i < closest_b)
		{
			closest_b = i;
			closest = curr;
		}
		curr = curr->next;
	}
	if (!closest)
		return (0);
	return (closest_b);
}
