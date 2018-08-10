/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:06:17 by afesyk            #+#    #+#             */
/*   Updated: 2018/06/03 14:06:19 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_xyz	sphere_normal(void *p_mlx)
{
	t_mlx	*p;

	p = (t_mlx*)p_mlx;
	p->intersect.point =
			vecadd(p->cam, vecscale(p->rd, p->intersect.scalar - 0.000001));
	p->intersect.obj->normal =
			vecsub(p->intersect.point, p->intersect.obj->center);
	return (vecnorm(p->intersect.obj->normal));
}

t_xyz	plane_normal(void *p_mlx)
{
	t_mlx	*p;

	p = (t_mlx*)p_mlx;
	p->intersect.point =
			vecadd(p->cam, vecscale(p->rd, p->intersect.scalar - 0.000001));
	return (vecnorm(p->intersect.obj->normal));
}

t_xyz	cylinder_normal(void *p_mlx)
{
	t_mlx	*p;
	t_xyz	co;
	double	axis_inters;

	p = (t_mlx*)p_mlx;
	co = vecsub(p->cam, p->intersect.obj->center);
	axis_inters = vecdot(p->rd, p->intersect.obj->axis) * p->intersect.scalar +
			vecdot(co, p->intersect.obj->axis);
	p->intersect.point =
			vecadd(p->cam, vecscale(p->rd, p->intersect.scalar - 0.000001));
	p->intersect.obj->normal =
			vecsub(p->intersect.point,
				vecadd(p->intersect.obj->center,
					vecscale(p->intersect.obj->axis, axis_inters)));
	return (vecnorm(p->intersect.obj->normal));
}

t_xyz	cone_normal(void *p_mlx)
{
	t_mlx	*p;
	t_xyz	co;
	double	axis_inters;
	double	n;

	p = (t_mlx*)p_mlx;
	n = 1 + p->intersect.obj->angle * p->intersect.obj->angle;
	co = vecsub(p->cam, p->intersect.obj->center);
	axis_inters = vecdot(p->rd, p->intersect.obj->axis) * p->intersect.scalar +
			vecdot(co, p->intersect.obj->axis);
	p->intersect.point =
			vecadd(p->cam, vecscale(p->rd, p->intersect.scalar - 0.000001));
	p->intersect.obj->normal =
			vecsub(p->intersect.point,
				vecadd(p->intersect.obj->center,
					vecscale(p->intersect.obj->axis, axis_inters * n)));
	return (vecnorm(p->intersect.obj->normal));
}
