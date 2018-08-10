/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:05:24 by afesyk            #+#    #+#             */
/*   Updated: 2018/06/03 14:05:27 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	specular_reflection(t_mlx *p, t_light *l, t_xyz normal)
{
	t_xyz	refl_vec;
	t_xyz	view_vec;
	double	dot_nl;

	dot_nl = vecdot(normal, l->dir);
	refl_vec = vecsub(vecscale(normal, (2 * dot_nl)), l->dir);
	refl_vec = vecnorm(refl_vec);
	view_vec = vecscale(p->rd, -1);
	view_vec = vecnorm(view_vec);
	return (vecdot(refl_vec, view_vec));
}

double	light_intensity(t_mlx *p, t_light *l, t_xyz normal)
{
	t_xyz	light_pos;
	double	cos_a;
	double	li;

	li = 0;
	if (l->type == ambient)
		li += l->intensity;
	else
	{
		if (l->type == point)
		{
			light_pos = vecadd(l->pos, (t_xyz) {0.0001, 0.0001, 0.0001});
			l->dir = vecsub(light_pos, p->intersect.point);
		}
		cos_a = vecdot(l->dir, normal) / (veclen(l->dir) * veclen(normal));
		if (!trace_shadow_ray(l, p) && cos_a > 0)
		{
			li += l->intensity * cos_a;
			if (p->intersect.obj->specular > 0)
				if ((cos_a = specular_reflection(p, l, normal)) > 0)
					li += l->intensity * pow(cos_a, p->intersect.obj->specular);
		}
	}
	return (li);
}

int		apply_to_rgb(double li, int color)
{
	double	r;
	double	g;
	double	b;

	r = ((color >> 16) & 0xFF) * li;
	if (r > 255)
		r = 255;
	g = ((color >> 8) & 0xFF) * li;
	if (g > 255)
		g = 255;
	b = (color & 0xFF) * li;
	if (b > 255)
		b = 255;
	return ((int)r << 16 | (int)g << 8 | (int)b);
}

int		compute_lighting(t_mlx *p)
{
	t_light	*l;
	double	li;
	int		clr;

	p->intersect.obj->normal = p->intersect.obj->find_normal((void*)p);
	l = p->light;
	li = 0;
	while (l)
	{
		li += light_intensity(p, l, p->intersect.obj->normal);
		l = l->next;
	}
	clr = apply_to_rgb(li, p->intersect.obj->color);
	return (clr);
}
