/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:59:07 by afesyk            #+#    #+#             */
/*   Updated: 2018/04/24 14:59:09 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	tricorn(int x, int y, void *argset)
{
	int		i;
	t_args	*as;

	as = (t_args*)argset;
	i = 0;
	as->c_im = (double)y / (double)HEIGHT * (as->p->dy * 2) - as->p->dy + \
				as->p->y_center;
	as->c_re = (double)x / (double)WIDTH * (as->p->dx * 2) - as->p->dx + \
				as->p->x_center;
	as->new_re = 0;
	as->new_im = 0;
	as->old_re = 0;
	as->old_im = 0;
	while ((pow(as->new_re, 2) + pow(as->new_im, 2)) < 4 && i < as->p->max_iter)
	{
		as->old_re = as->new_re;
		as->old_im = as->new_im;
		as->new_re = as->old_re * as->old_re - as->old_im * as->old_im + \
					as->c_re;
		as->new_im = -2 * as->old_re * as->old_im + as->c_im;
		i++;
	}
	return (i);
}

int	celtic_mandelbrot(int x, int y, void *argset)
{
	int		i;
	t_args	*as;

	as = (t_args*)argset;
	i = 0;
	as->c_im = (double)y / (double)HEIGHT * (as->p->dy * 2) - as->p->dy + \
				as->p->y_center;
	as->c_re = (double)x / (double)WIDTH * (as->p->dx * 2) - as->p->dx + \
				as->p->x_center;
	as->new_re = 0;
	as->new_im = 0;
	as->old_re = 0;
	as->old_im = 0;
	while ((pow(as->new_re, 2) + pow(as->new_im, 2)) < 4 && i < as->p->max_iter)
	{
		as->old_re = as->new_re;
		as->old_im = as->new_im;
		as->new_re = fabsl(as->old_re * as->old_re - as->old_im * \
			as->old_im) + as->c_re;
		as->new_im = 2 * as->old_re * as->old_im + as->c_im;
		i++;
	}
	return (i);
}

int	burning_ship(int x, int y, void *argset)
{
	int		i;
	t_args	*as;

	as = (t_args*)argset;
	i = 0;
	as->c_im = (double)y / (double)HEIGHT * (as->p->dy * 2) - as->p->dy + \
				as->p->y_center;
	as->c_re = (double)x / (double)WIDTH * (as->p->dx * 2) - as->p->dx + \
				as->p->x_center;
	as->new_re = 0;
	as->new_im = 0;
	as->old_re = 0;
	as->old_im = 0;
	while ((pow(as->new_re, 2) + pow(as->new_im, 2)) < 4 && i < as->p->max_iter)
	{
		as->old_re = as->new_re;
		as->old_im = as->new_im;
		as->new_re = pow(as->old_re, 2) - pow(as->old_im, 2) + as->c_re;
		as->new_im = 2 * fabsl(as->old_im * as->old_re) + as->c_im;
		i++;
	}
	return (i);
}

int	buffalo(int x, int y, void *argset)
{
	int		i;
	t_args	*as;

	as = (t_args*)argset;
	i = 0;
	as->c_im = (double)y / (double)HEIGHT * (as->p->dy * 2) - as->p->dy + \
				as->p->y_center;
	as->c_re = (double)x / (double)WIDTH * (as->p->dx * 2) - as->p->dx + \
				as->p->x_center;
	as->new_re = 0;
	as->new_im = 0;
	as->old_re = 0;
	as->old_im = 0;
	while ((pow(as->new_re, 2) + pow(as->new_im, 2)) < 4 && i < as->p->max_iter)
	{
		as->old_re = as->new_re;
		as->old_im = as->new_im;
		as->new_im = 2 * fabs(as->old_re * as->old_im) + as->c_im;
		as->new_re = fabs(as->old_re * as->old_re - as->old_im * as->old_im) + \
				as->c_re;
		i++;
	}
	return (i);
}

int	heart_mandelbrot(int x, int y, void *argset)
{
	int		i;
	t_args	*as;

	as = (t_args*)argset;
	i = 0;
	as->c_im = (double)y / (double)HEIGHT * (as->p->dy * 2) - as->p->dy + \
				as->p->y_center;
	as->c_re = (double)x / (double)WIDTH * (as->p->dx * 2) - as->p->dx + \
				as->p->x_center;
	as->new_re = 0;
	as->new_im = 0;
	as->old_re = 0;
	as->old_im = 0;
	while ((pow(as->new_re, 2) + pow(as->new_im, 2)) < 4 && i < as->p->max_iter)
	{
		as->old_re = as->new_re;
		as->old_im = as->new_im;
		as->new_re = as->old_re * as->old_re - as->old_im * as->old_im + \
					as->c_re;
		as->new_im = 2 * fabsl(as->old_re) * as->old_im + as->c_im;
		i++;
	}
	return (i);
}
