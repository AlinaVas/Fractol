/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:05:48 by afesyk            #+#    #+#             */
/*   Updated: 2018/06/03 14:05:49 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	deal_key2(int key, t_mlx *p)
{
	if (key == four)
		p->camdir.y -= 0.08;
	if (key == six)
		p->camdir.y += 0.08;
	if (key == two)
		p->camdir.x += 0.08;
	if (key == eight)
		p->camdir.x -= 0.08;
	if (key == one)
		p->camdir.z -= 0.08;
	if (key == three)
		p->camdir.z += 0.08;
}

int		deal_key(int key, t_mlx *p)
{
	deal_key2(key, p);
	if (key == esc)
	{
		free_everything(p);
		exit(0);
	}
	if (key == arr_left)
		p->cam.x -= 1;
	if (key == arr_right)
		p->cam.x += 1;
	if (key == arr_up)
		p->cam.y += 1;
	if (key == arr_down)
		p->cam.y -= 1;
	redraw_image(p);
	return (0);
}

int		mouse_zoom(int button, int x, int y, t_mlx *p)
{
	if (x < 0 || x > WIN_X || y < 0 || y > WIN_Y)
		return (0);
	if (button == scrollup)
		p->cam.z += 1;
	if (button == scrolldown)
		p->cam.z -= 1;
	redraw_image(p);
	return (0);
}
