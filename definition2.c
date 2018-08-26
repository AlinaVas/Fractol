/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:24:01 by afesyk            #+#    #+#             */
/*   Updated: 2018/04/23 20:24:06 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_pack(t_pack *p)
{
	p->modify_julia = 1;
	p->max_iter = 60;
	p->c_real = -0.7;
	p->c_imaginary = 0.27015;
	p->dx = (p->max_re - p->min_re) / 2;
	p->dy = (p->max_im - p->min_im) / 2;
	p->x_center = p->min_re + p->dx;
	p->y_center = p->min_im + p->dy;
	p->shift_by = STEP * (p->max_re - p->min_re) / (double)DWIDTH;
}

void	define_fractol(t_pack *p, char *argv)
{
	if (!ft_strcmp(argv, "julia"))
		p->fractol_type = 0;
	else if (!ft_strcmp(argv, "mandelbrot"))
		p->fractol_type = 1;
	else if (!ft_strcmp(argv, "mandelbrot_4th"))
		p->fractol_type = 2;
	else if (!ft_strcmp(argv, "burning_ship"))
		p->fractol_type = 3;
	else if (!ft_strcmp(argv, "celtic_mandelbrot"))
		p->fractol_type = 4;
	else if (!ft_strcmp(argv, "tricorn"))
		p->fractol_type = 5;
	else if (!ft_strcmp(argv, "heart_mandelbrot"))
		p->fractol_type = 6;
	else if (!ft_strcmp(argv, "buffalo"))
		p->fractol_type = 7;
	else
		error_exit(3);
}

void	put_description(t_pack *p)
{
	mlx_string_put(p->mlx, p->win, 20, 20, 0xFFFFFF, "ESC            exit");
	mlx_string_put(p->mlx, p->win, 20, 40, 0xFFFFFF, "Scroll/+/-     zoom");
	mlx_string_put(p->mlx, p->win, 20, 60, 0xFFFFFF, "Arrows         shift");
	if (p->fractol_type == 0)
		mlx_string_put(p->mlx, p->win, 20, 80, 0xFFFFFF, "Space          stop");
	mlx_string_put(p->mlx, p->win, 20, 100, 0xFFFFFF, "ITERATIONS:");
	free(p->display_iter);
	p->display_iter = ft_itoa((int)p->max_iter);
	mlx_string_put(p->mlx, p->win, 172, 100, 0xFFFFFF, p->display_iter);
}
