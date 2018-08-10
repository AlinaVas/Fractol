/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 20:06:24 by afesyk            #+#    #+#             */
/*   Updated: 2018/06/03 14:06:11 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mlx	*create_struct(char *av)
{
	t_mlx	*p;

	if (!(p = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		error_exit(4, p);
	p->cam = (t_xyz){0, 0, 0};
	p->camdir = (t_xyz){0, 0, 0};
	p->d = 1;
	p->viewport_x = 0.5;
	p->viewport_y = 0.5;
	if (!ft_strcmp("scene1", av))
		get_scene1(p);
	else if (!ft_strcmp("scene2", av))
		get_scene2(p);
	else if (!ft_strcmp("scene3", av))
		get_scene3(p);
	else if (!ft_strcmp("scene4", av))
		get_scene4(p);
	else
		error_exit(1, p);
	validate_scene(p->scene, p->light, p);
	return (p);
}

void	render_img(t_mlx *p)
{
	double	x;
	double	y;
	int		color;

	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			p->rd = ray_direction(x, y, p);
			if (trace_viewing_ray(p))
				color = compute_lighting(p);
			else
				color = BACKGROUND_COLOR;
			*(int *)(p->data_addr + (((int)x + (int)y * WIN_X) * 4)) = color;
		}
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	redraw_image(t_mlx *p)
{
	mlx_clear_window(p->mlx, p->win);
	render_img(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

int		main(int ac, char **av)
{
	t_mlx	*p;

	p = NULL;
	if (ac < 2)
		error_exit(2, p);
	p = create_struct(av[1]);
	if (!(p->mlx = mlx_init()))
		error_exit(0, p);
	if (!(p->win = mlx_new_window(p->mlx, WIN_X, WIN_Y, av[0])))
		error_exit(0, p);
	if (!(p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y)))
		error_exit(0, p);
	if (!(p->data_addr = mlx_get_data_addr(p->img, &p->bits_per_pixel,
		&p->size_line, &p->endian)))
		error_exit(0, p);
	render_img(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_hook(p->win, 4, 1L << 2, mouse_zoom, p);
	mlx_hook(p->win, 17, 1L << 17, just_exit, p);
	mlx_hook(p->win, 2, 5, deal_key, p);
	mlx_loop(p->mlx);
	return (0);
}
