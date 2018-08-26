/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:03:43 by afesyk            #+#    #+#             */
/*   Updated: 2018/04/24 15:03:44 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia(int x, int y, void *argset)
{
	int		i;
	t_args	*as;

	as = (t_args*)argset;
	i = 0;
	as->new_re = (double)x / (double)WIDTH * (as->p->dx * 2) - as->p->dx + \
				as->p->x_center;
	as->new_im = (double)y / (double)HEIGHT * (as->p->dy * 2) - as->p->dy + \
				as->p->y_center;
	while ((pow(as->new_re, 2) + pow(as->new_im, 2)) < 4 && i < as->p->max_iter)
	{
		as->old_re = as->new_re;
		as->old_im = as->new_im;
		as->new_re = pow(as->old_re, 2) - pow(as->old_im, 2) + as->c_re;
		as->new_im = 2 * as->old_re * as->old_im + as->c_im;
		i++;
	}
	return (i);
}

int		mouse_motion_julia(int x, int y, t_pack *p)
{
	if (!(p->fractol_type == 0 && p->modify_julia == 1 && x >= 400 && \
		x <= DWIDTH && y >= 0 && y <= HEIGHT))
		return (0);
	p->c_real = -1.75 + (double)(x - WIDTH) * (1.75 * (-1.75)) / WIDTH;
	p->c_imaginary = 1.46 - (double)(y - HEIGHT) * (-1.45) / HEIGHT;
	redraw_image(p);
	return (0);
}

int		mandelbrot(int x, int y, void *argset)
{
	int		i;
	t_args	*as;

	as = (t_args*)argset;
	i = 0;
	as->c_re = (double)x / (double)WIDTH * (as->p->dx * 2) - as->p->dx + \
				as->p->x_center;
	as->c_im = (double)y / (double)HEIGHT * (as->p->dy * 2) - as->p->dy + \
				as->p->y_center;
	as->new_re = 0;
	as->new_im = 0;
	as->old_re = 0;
	as->old_im = 0;
	while ((pow(as->new_re, 2) + pow(as->new_im, 2)) < 4 && i < as->p->max_iter)
	{
		as->old_re = as->new_re;
		as->old_im = as->new_im;
		as->new_re = pow(as->old_re, 2) - pow(as->old_im, 2) + as->c_re;
		as->new_im = 2 * as->old_re * as->old_im + as->c_im;
		i++;
	}
	return (i);
}

int		mandelbrot_4th(int x, int y, void *argset)
{
	int		i;
	t_args	*as;

	as = (t_args*)argset;
	i = 0;
	as->c_re = (double)x / (double)WIDTH * (as->p->dx * 2) - as->p->dx + \
				as->p->x_center;
	as->c_im = (double)y / (double)HEIGHT * (as->p->dy * 2) - as->p->dy + \
				as->p->y_center;
	as->new_re = 0;
	as->new_im = 0;
	as->old_re = 0;
	as->old_im = 0;
	while ((pow(as->new_re, 2) + pow(as->new_im, 2)) < 4 && i < as->p->max_iter)
	{
		as->old_re = as->new_re;
		as->old_im = as->new_im;
		as->new_re = as->old_re * as->old_re * as->old_re * as->old_re + \
			as->old_im * as->old_im * as->old_im * as->old_im - \
			6 * as->old_re * as->old_re * as->old_im * as->old_im + as->c_re;
		as->new_im = 4 * as->old_re * as->old_im * (as->old_re * as->old_re - \
			as->old_im * as->old_im) + as->c_im;
		i++;
	}
	return (i);
}
