/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:39:29 by afesyk            #+#    #+#             */
/*   Updated: 2018/04/23 20:39:31 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw_image(t_pack *p)
{
	mlx_clear_window(p->mlx, p->win);
	make_threads(p);
	put_description(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 400, 0);
}

void	init_process(t_pack *p, char *argv)
{
	if (!(p->mlx = mlx_init()))
		error_exit(5);
	if (!(p->win = mlx_new_window(p->mlx, DWIDTH, HEIGHT, argv)))
		error_exit(5);
	if (!(p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT)))
		error_exit(5);
	if (!(p->data_addr = mlx_get_data_addr(p->img, &p->bits_per_pixel, \
		&p->size_line, &p->endian)))
		error_exit(5);
	make_threads(p);
	put_description(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 400, 0);
	mlx_hook(p->win, 2, 5, deal_key, p);
	mlx_hook(p->win, 6, 0, mouse_motion_julia, p);
	mlx_hook(p->win, 4, 1L << 2, mouse_buttons, p);
	mlx_hook(p->win, 17, 1L << 17, just_exit, p);
	mlx_loop(p->mlx);
}

int		main(int ac, char **av)
{
	t_pack	*p;
	int		i;
	char	*avv[3];

	if (ac == 1)
		error_exit(4);
	i = 0;
	while (ac > 2 && ++i < ac)
	{
		if (fork() == 0)
		{
			avv[0] = av[0];
			avv[1] = av[i];
			avv[2] = NULL;
			execve(av[0], avv, NULL);
			return (0);
		}
	}
	if (ac == 2)
	{
		p = create_pack(av[1]);
		init_process(p, av[1]);
	}
	return (0);
}
