/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:05:58 by afesyk            #+#    #+#             */
/*   Updated: 2018/06/03 14:06:00 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	find_closest(double res[2])
{
	double	t_closest;

	t_closest = TMAX;
	if (res[0] > 0)
		t_closest = res[0];
	if (res[1] > 0 && res[1] < t_closest)
		t_closest = res[1];
	return (t_closest);
}

double	sphere_intersection(void *obj, t_xyz starting_point, t_xyz rd)
{
	t_obj	*sph;
	t_xyz	co;
	double	res[2];
	double	k[4];

	sph = (t_obj*)obj;
	co = vecsub(starting_point, sph->center);
	k[0] = vecdot(rd, rd);
	k[1] = 2 * vecdot(co, rd);
	k[2] = vecdot(co, co) - sph->radius * sph->radius;
	k[3] = k[1] * k[1] - 4 * k[0] * k[2];
	if (k[3] < 0)
		return (0);
	res[0] = (-k[1] - sqrt(k[3])) / (2 * k[0]);
	res[1] = (-k[1] + sqrt(k[3])) / (2 * k[0]);
	return (find_closest(res));
}

double	plane_intersection(void *obj, t_xyz starting_point, t_xyz rd)
{
	t_obj	*pln;
	t_xyz	co;
	t_xyz	pln_norm;
	double	dot_rd_norm;
	double	dot_co_norm;

	pln = (t_obj*)obj;
	pln_norm = vecnorm(pln->normal);
	co = vecsub(starting_point, pln->center);
	dot_co_norm = -1 * vecdot(co, pln_norm);
	dot_rd_norm = vecdot(rd, pln_norm);
	if (dot_rd_norm)
		return (dot_co_norm / dot_rd_norm);
	return (TMAX);
}

double	cylinder_intersection(void *obj, t_xyz starting_point, t_xyz rd)
{
	t_obj	*cyl;
	t_xyz	co;
	double	res[2];
	double	k[4];

	cyl = (t_obj*)obj;
	// cyl->axis = vecnorm(cyl->axis);
	co = vecsub(starting_point, cyl->center);
	k[0] = vecdot(rd, rd) - pow(vecdot(rd, cyl->axis), 2);
	k[1] = 2 * (vecdot(rd, co) - vecdot(rd, cyl->axis) * vecdot(co, cyl->axis));
	k[2] = vecdot(co, co) - pow(vecdot(co, vecnorm(cyl->axis)), 2) -
			cyl->radius * cyl->radius;
	k[3] = k[1] * k[1] - 4 * k[0] * k[2];
	if (k[3] < 0)
		return (0);
	res[0] = (-k[1] - sqrt(k[3])) / (2 * k[0]);
	res[1] = (-k[1] + sqrt(k[3])) / (2 * k[0]);
	return (find_closest(res));
}

double	cone_intersection(void *obj, t_xyz starting_point, t_xyz rd)
{
	t_obj	*con;
	t_xyz	co;
	double	res[2];
	double	k[4];
	double	n;

	con = (t_obj*)obj;
	con->axis = vecnorm(con->axis);
	co = vecsub(starting_point, con->center);
	n = 1 + con->angle * con->angle;
	k[0] = vecdot(rd, rd) - n * pow(vecdot(rd, con->axis), 2);
	k[1] = 2 * (vecdot(rd, co) -
			n * vecdot(rd, con->axis) * vecdot(co, con->axis));
	k[2] = vecdot(co, co) - n * pow(vecdot(co, con->axis), 2);
	k[3] = k[1] * k[1] - 4 * k[0] * k[2];
	if (k[3] < 0)
		return (0);
	res[0] = (-k[1] - sqrt(k[3])) / (2 * k[0]);
	res[1] = (-k[1] + sqrt(k[3])) / (2 * k[0]);
	return (find_closest(res));
}
