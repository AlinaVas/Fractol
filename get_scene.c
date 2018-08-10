/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:05:40 by afesyk            #+#    #+#             */
/*   Updated: 2018/06/03 14:05:42 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	validate_scene(t_obj *obj, t_light *l, t_mlx *p)
{
	int error;

	error = 0;
	while (obj)
	{
		if (obj->error && ++error)
			break ;
		obj = obj->next;
	}
	while (l)
	{
		if (l->error && ++error)
			break ;
		l = l->next;
	}
	if (error)
		error_exit(3, p);
}

int		get_rgb(int color)
{
	int	r;
	int	g;
	int	b;

	if (color < 0)
		return (0);
	r = (color >> 16) & 0xFF;
	if (r > 255)
		r = 255;
	g = (color >> 8) & 0xFF;
	if (g > 255)
		g = 255;
	b = color & 0xFF;
	if (b > 255)
		b = 255;
	return (r << 16 | g << 8 | b);
}

void	pass_params(t_obj **obj, t_xyz center, int color, double specular)
{
	(*obj)->center = center;
	(*obj)->color = get_rgb(color);
	if (specular <= 0)
		(*obj)->specular = 10;
	else
		(*obj)->specular = specular;
	(*obj)->error = 0;
}

t_obj	*create_obj(int type, t_xyz center, int color, double specular)
{
	t_obj	*obj;

	obj = (t_obj*)ft_memalloc(sizeof(t_obj));
	pass_params(&obj, center, color, specular);
	if (type == plane)
		obj->find_intersection = &plane_intersection;
	else if (type == sphere)
		obj->find_intersection = &sphere_intersection;
	else if (type == cylinder)
		obj->find_intersection = &cylinder_intersection;
	else if (type == cone)
		obj->find_intersection = &cone_intersection;
	else
		obj->error = 1;
	if (type == plane)
		obj->find_normal = &plane_normal;
	else if (type == sphere)
		obj->find_normal = &sphere_normal;
	else if (type == cylinder)
		obj->find_normal = &cylinder_normal;
	else if (type == cone)
		obj->find_normal = &cone_normal;
	return (obj);
}

t_light	*create_light(int type, double intensity, t_xyz vec)
{
	t_light	*l;

	l = (t_light*)ft_memalloc(sizeof(t_light));
	l->error = 0;
	l->type = type;
	l->intensity = intensity;
	if (type == point)
		l->pos = vec;
	else if (type == directional)
		l->dir = vec;
	else if (type != ambient)
		l->error = 1;
	return (l);
}
