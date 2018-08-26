/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:40:18 by afesyk            #+#    #+#             */
/*   Updated: 2018/04/23 20:40:19 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_zoom(t_pack *p, double zoom)
{
	p->dx *= zoom;
	p->dy *= zoom;
	p->min_re = (p->x_center - p->dx) * zoom;
	p->max_re = (p->x_center + p->dx) * zoom;
	p->min_im = (p->y_center - p->dy) * zoom;
	p->max_im = (p->y_center + p->dy) * zoom;
}

void	zoom_image(t_pack *p, double x_cord, double y_cord, double zoom)
{
	double	x;
	double	y;

	x = (x_cord / WIDTH) * (2 * p->dx) - p->dx + p->x_center;
	y = (y_cord / HEIGHT) * (2 * p->dy) - p->dy + p->y_center;
	p->min_re = (p->x_center - p->dx) * zoom + x * (1 - zoom);
	p->max_re = (p->x_center + p->dx) * zoom + x * (1 - zoom);
	p->min_im = (p->y_center - p->dy) * zoom + y * (1 - zoom);
	p->max_im = (p->y_center + p->dy) * zoom + y * (1 - zoom);
	p->dx = (p->max_re - p->min_re) / 2;
	p->dy = (p->max_im - p->min_im) / 2;
	p->x_center = (p->max_re - p->dx);
	p->y_center = (p->max_im - p->dy);
}

int		mouse_buttons(int button, int x, int y, t_pack *p)
{
	if (x < 400 || x > DWIDTH || y < 0 || y > HEIGHT)
		return (0);
	if (button == scroll_down)
	{
		zoom_image(p, (double)x - 400, (double)y, ZOOM_OUT);
		p->shift_by = STEP * (p->max_re - p->min_re) / (double)DWIDTH;
		p->max_iter -= (p->max_iter > MIN_ITER) ? 1 : 0;
	}
	if (button == scroll_up)
	{
		zoom_image(p, (double)x - 400, (double)y, ZOOM_IN);
		p->shift_by = STEP * (p->max_re - p->min_re) / (double)DWIDTH;
		p->max_iter += (p->max_iter < MAX_ITER) ? 1 : 0;
	}
	redraw_image(p);
	return (0);
}

void	deal_key2(int key, t_pack *p)
{
	if (key == plus_r)
	{
		key_zoom(p, ZOOM_IN);
		p->shift_by = STEP * (p->max_re - p->min_re) / (double)DWIDTH;
		p->max_iter += (p->max_iter < MAX_ITER) ? 1 : 0;
	}
	if (key == minus_r)
	{
		key_zoom(p, ZOOM_OUT);
		p->shift_by = STEP * (p->max_re - p->min_re) / (double)DWIDTH;
		p->max_iter -= (p->max_iter > MIN_ITER) ? 1 : 0;
	}
	if (key == plus_l)
		p->max_iter += 10;
	if (key == minus_l)
		p->max_iter -= 10;
	if (key == space)
		p->modify_julia = (p->modify_julia == 1) ? 0 : 1;
}

int		deal_key(int key, t_pack *p)
{
	if (key == esc)
	{
		just_exit(p);
	}
	if (key == arr_left)
		p->x_center -= p->shift_by;
	if (key == arr_right)
		p->x_center += p->shift_by;
	if (key == arr_up)
		p->y_center -= p->shift_by;
	if (key == arr_down)
		p->y_center += p->shift_by;
	deal_key2(key, p);
	redraw_image(p);
	return (0);
}
