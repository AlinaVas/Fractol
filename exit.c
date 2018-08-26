/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:39:47 by afesyk            #+#    #+#             */
/*   Updated: 2018/04/23 20:39:49 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		just_exit(t_pack *p)
{
	mlx_destroy_image(p->mlx, p->img);
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
}

void	error_exit(int n)
{
	if (n == 0)
		ft_putstr_fd("Error allocating memory\n", 2);
	if (n == 1)
		ft_putstr_fd("Error creating thread\n", 2);
	if (n == 2)
		ft_putstr_fd("Error joining thread\n", 2);
	if (n == 3)
		ft_putstr_fd("Incorect fractal name\nusage: ./fractol [julia] \
			\n\t\t [mandelbrot]\n\t\t [mandelbrot_4th]\n\t\t [burning_ship] \
			\n\t\t [celtic_mandelbrot]\n\t\t [tricorn] \
			\n\t\t [heart_mandelbrot]\n\t\t [buffalo]\n", 2);
	if (n == 4)
		ft_putstr_fd("Error: no arguments\nusage: ./fractol [julia] \
			\n\t\t [mandelbrot]\n\t\t [mandelbrot_4th]\n\t\t [burning_ship] \
			\n\t\t [celtic_mandelbrot]\n\t\t [tricorn] \
			\n\t\t [heart_mandelbrot]\n\t\t [buffalo]\n", 2);
	if (n == 5)
		ft_putstr_fd("MLX error\n", 2);
	exit(-1);
}
