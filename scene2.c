/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:06:52 by afesyk            #+#    #+#             */
/*   Updated: 2018/06/03 14:06:54 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_scene4_3(t_obj *obj)
{
	while (obj->next)
		obj = obj->next;
	obj->next = create_obj(sphere, (t_xyz){-3, -2, -2}, 0xDCDCDC, 100);
	obj->next->radius = 1;
	obj->next->next = create_obj(sphere, (t_xyz){3, -2, -2}, 0xDCDCDC, 100);
	obj->next->next->radius = 1;
	obj->next->next->next =
			create_obj(sphere, (t_xyz){3, -2, 3}, 0xDCDCDC, 100);
	obj->next->next->next->radius = 1;
	obj->next->next->next->next =
			create_obj(sphere, (t_xyz){-3, -2, 3}, 0xDCDCDC, 100);
	obj->next->next->next->next->radius = 1;
	obj->next->next->next->next->next = NULL;
}

void	get_scene4_2(t_obj *obj)
{
	while (obj->next)
		obj = obj->next;
	obj->next = create_obj(cylinder, (t_xyz){3, 4, -2}, 0xDCDCDC, 100);
	obj->next->radius = 0.6;
	obj->next->axis = (t_xyz){0, -1, 0};
	obj->next->next = create_obj(cylinder, (t_xyz){-3, 4, -2}, 0xDCDCDC, 100);
	obj->next->next->radius = 0.6;
	obj->next->next->axis = (t_xyz){0, -1, 0};
	obj->next->next->next =
			create_obj(sphere, (t_xyz){-3, 3, 3}, 0xDCDCDC, 100);
	obj->next->next->next->radius = 1;
	obj->next->next->next->next =
			create_obj(sphere, (t_xyz){3, 3, 3}, 0xDCDCDC, 100);
	obj->next->next->next->next->radius = 1;
	obj->next->next->next->next->next =
			create_obj(sphere, (t_xyz){3, 3, -2}, 0xDCDCDC, 100);
	obj->next->next->next->next->next->radius = 1;
	obj->next->next->next->next->next->next =
			create_obj(sphere, (t_xyz){-3, 3, -2}, 0xDCDCDC, 100);
	obj->next->next->next->next->next->next->radius = 1;
	get_scene4_3(obj);
}

void	get_scene4_1(t_mlx *p)
{
	t_light	*l;

	l = create_light(ambient, 0.2, (t_xyz){0, 0, 0});
	p->light = l;
	l->next = create_light(point, 0.4, (t_xyz){-8, 2, -8});
	l->next->next = create_light(point, 0.4, (t_xyz){8, 2, -8});
	l->next->next->next = NULL;
}

void	get_scene4(t_mlx *p)
{
	t_obj	*obj;

	p->cam = (t_xyz){0, 0.5, -15};
	obj = create_obj(plane, (t_xyz){0, 3, 0}, 0x696969, 10);
	p->scene = obj;
	obj->normal = (t_xyz){0, -1, 0};
	obj->next = create_obj(plane, (t_xyz){0, -2, 0}, 0x696969, 10);
	obj->next->normal = (t_xyz){0, 1, 0};
	obj->next->next = create_obj(plane, (t_xyz){0, 0, 6}, 0xFF00FF, 10);
	obj->next->next->normal = (t_xyz){0, 0, -1};
	obj->next->next->next =
			create_obj(sphere, (t_xyz){0, -1.5, -2}, 0xFF0000, 50);
	obj->next->next->next->radius = 0.35;
	obj->next->next->next->next =
			create_obj(cylinder, (t_xyz){-3, 4, 3}, 0xDCDCDC, 100);
	obj->next->next->next->next->radius = 0.6;
	obj->next->next->next->next->axis = (t_xyz){0, -1, 0};
	obj->next->next->next->next->next =
			create_obj(cylinder, (t_xyz){3, 4, 3}, 0xDCDCDC, 100);
	obj->next->next->next->next->next->radius = 0.6;
	obj->next->next->next->next->next->axis = (t_xyz){0, -1, 0};
	get_scene4_2(obj);
	get_scene4_1(p);
}
