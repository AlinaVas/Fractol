/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:22:11 by afesyk            #+#    #+#             */
/*   Updated: 2018/04/23 20:22:12 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	define_borders3(t_pack *p)
{
	if (p->fractol_type == 5)
	{
		p->min_re = -2;
		p->max_re = 2;
		p->min_im = -2;
	}
	if (p->fractol_type == 6)
	{
		p->min_re = -2.2;
		p->max_re = 1.55;
		p->min_im = -1.9;
	}
	if (p->fractol_type == 7)
	{
		p->min_re = -2.3;
		p->max_re = 1.45;
		p->min_im = -2.5;
	}
}

void	define_borders2(t_pack *p)
{
	if (p->fractol_type == 2)
	{
		p->min_re = -1.9;
		p->max_re = 1.75;
		p->min_im = -1.8;
	}
	if (p->fractol_type == 3)
	{
		p->min_re = -2.5;
		p->max_re = 1.45;
		p->min_im = -2.5;
	}
	if (p->fractol_type == 4)
	{
		p->min_re = -2.5;
		p->max_re = 1.45;
		p->min_im = -2;
	}
}

void	define_borders(t_pack *p)
{
	if (p->fractol_type == 0)
	{
		p->min_re = -1.75;
		p->max_re = 1.75;
		p->min_im = -1.75;
	}
	if (p->fractol_type == 1)
	{
		p->min_re = -2;
		p->max_re = 1;
		p->min_im = -1.5;
	}
	define_borders2(p);
	define_borders3(p);
	p->max_im = p->min_im + (p->max_re - p->min_re) * HEIGHT / WIDTH;
}

t_pack	*create_pack(char *argv)
{
	t_pack	*p;

	p = ft_memalloc(sizeof(t_pack));
	if (!p)
		error_exit(0);
	p->display_iter = (char*)ft_memalloc(0);
	define_fractol(p, argv);
	define_borders(p);
	fill_pack(p);
	p->func[0] = &julia;
	p->func[1] = &mandelbrot;
	p->func[2] = &mandelbrot_4th;
	p->func[3] = &burning_ship;
	p->func[4] = &celtic_mandelbrot;
	p->func[5] = &tricorn;
	p->func[6] = &heart_mandelbrot;
	p->func[7] = &buffalo;
	return (p);
}
