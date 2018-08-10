/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:06:36 by afesyk            #+#    #+#             */
/*   Updated: 2018/06/03 14:06:44 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_scene1(t_mlx *p)
{
	t_obj	*obj;
	t_light	*l;

	p->cam = (t_xyz){0, 0.5, -6};
	obj = create_obj(sphere, (t_xyz){0, -1, 3}, 0xFF0000, 500);
	p->scene = obj;
	obj->radius = 1;
	obj->next = create_obj(sphere, (t_xyz){2, 0, 4}, 0x0000FF, 10);
	obj->next->radius = 1;
	obj->next->next = create_obj(sphere, (t_xyz){-2, 0, 4}, 0x00FF00, 5);
	obj->next->next->radius = 1;
	obj->next->next->next =
			create_obj(plane, (t_xyz){0, -1, 0}, 0xFFFF00, 10);
	obj->next->next->next->normal = (t_xyz){0, 1, 0};
	obj->next->next->next->next =
			create_obj(plane, (t_xyz){0, 0, 4}, 0xFF00FF, 10);
	obj->next->next->next->next->normal = (t_xyz){0, 0, -1};
	obj->next->next->next->next->next = NULL;
	l = create_light(ambient, 0.2, (t_xyz){0, 0, 0});
	p->light = l;
	l->next = create_light(point, 0.4, (t_xyz){2, 1, 0});
	l->next->next = create_light(directional, 0.2, (t_xyz){1, 4, 4});
	l->next->next->next = NULL;
}

void	get_scene2_2(t_mlx *p)
{
	t_light	*l;

	l = create_light(ambient, 0.2, (t_xyz){0, 0, 0});
	p->light = l;
	l->next = create_light(point, 0.4, (t_xyz){0, 0, -10});
	l->next->next = create_light(directional, 0.2, (t_xyz){-1, -4, -4});
	l->next->next->next = NULL;
}

void	get_scene2(t_mlx *p)
{
	t_obj	*obj;

	p->cam = (t_xyz){0, 0, -35};
	obj = create_obj(plane, (t_xyz){0, 0, 0}, 0xCCCCFF, 10);
	p->scene = obj;
	obj->normal = (t_xyz){-1, 0, -1};
	obj->next = create_obj(plane, (t_xyz){0, 0, 0}, 0xFFCCFF, 10);
	obj->next->normal = (t_xyz){1, 0, -1};
	obj->next->next = create_obj(plane, (t_xyz){0, 0, 0}, 0xFFFFCC, 10);
	obj->next->next->normal = (t_xyz){0, -1, -1};
	obj->next->next->next = create_obj(plane, (t_xyz){0, 0, 0}, 0xCCE5FF, 10);
	obj->next->next->next->normal = (t_xyz){0, 1, -1};
	obj->next->next->next->next =
			create_obj(cone, (t_xyz){0, 0, -3.5}, 0xB266FF, 10);
	obj->next->next->next->next->angle = 0.3;
	obj->next->next->next->next->axis = (t_xyz){-1, 1, 0};
	obj->next->next->next->next->next =
			create_obj(cone, (t_xyz){0, 0, -3.5}, 0xB266FF, 10);
	obj->next->next->next->next->next->angle = 0.3;
	obj->next->next->next->next->next->axis = (t_xyz){1, 1, 0};
	obj->next->next->next->next->next->next = NULL;
	get_scene2_2(p);
}

void	get_scene3(t_mlx *p)
{
	t_obj	*obj;
	t_light	*l;

	p->cam = (t_xyz){0, 1, -30};
	obj = create_obj(plane, (t_xyz){0, -2, 0}, 0xFF3399, 10);
	p->scene = obj;
	obj->normal = (t_xyz){0, 1, 0};
	obj->next = create_obj(plane, (t_xyz){0, 0, 10}, 0x808080, 10);
	obj->next->normal = (t_xyz){0, 0, -1};
	obj->next->next = create_obj(sphere, (t_xyz){-0.8, 0, 2.3}, 0x009999, 10);
	obj->next->next->radius = 2.5;
	obj->next->next->next = create_obj(cone, (t_xyz){2, 0.5, 2}, 0xAAAAFF, 10);
	obj->next->next->next->angle = 0.8;
	obj->next->next->next->axis = (t_xyz){1, -1.5, 0};
	obj->next->next->next->next =
			create_obj(cylinder, (t_xyz){-2.5, 1, 2}, 0xFF9933, 100);
	obj->next->next->next->next->radius = 1.2;
	obj->next->next->next->next->axis = (t_xyz){1, 1, 0};
	obj->next->next->next->next->next = NULL;
	l = create_light(ambient, 0.2, (t_xyz){0, 0, 0});
	p->light = l;
	l->next = create_light(point, 0.6, (t_xyz){2, 1, 0});
	l->next->next = create_light(directional, 0.2, (t_xyz){1, 4, 4});
	l->next->next->next = NULL;
}
