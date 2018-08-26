/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:17:02 by afesyk            #+#    #+#             */
/*   Updated: 2018/04/23 20:17:05 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_color(int i, t_pack *p)
{
	int col;
	int red;
	int green;

	if (i == p->max_iter)
		return (0);
	if (i >= 0 && i < p->max_iter / 2)
	{
		red = 255 / (p->max_iter / 2) * i;
		col = red << 16 | 0 << 8 | 0;
	}
	else if (i >= p->max_iter / 2)
	{
		green = 255 / (p->max_iter / 2) * (i - p->max_iter / 2);
		col = 255 << 16 | green << 8 | 0;
	}
	else
		return (0);
	return ((double)col);
}

void	*iterator(void *ptr)
{
	int		x;
	int		y;
	double	col;
	int		i;
	t_args	*as;

	as = (t_args *)ptr;
	y = -1;
	while (++y < HEIGHT)
	{
		x = as->start - 1;
		while (++x < as->end)
		{
			i = as->p->func[as->p->fractol_type](x, y, (void*)as);
			col = get_color(i, as->p);
			*(unsigned int *)(as->p->data_addr + ((x + y * WIDTH) * 4)) = col;
		}
	}
	pthread_exit(NULL);
}

void	make_threads(t_pack *p)
{
	pthread_t	t[THREAD_NUM];
	t_args		argset[THREAD_NUM];
	int			i;

	i = -1;
	while (++i < THREAD_NUM)
	{
		argset[i].start = (WIDTH / THREAD_NUM) * i;
		argset[i].end = WIDTH / THREAD_NUM + (WIDTH / THREAD_NUM) * i;
		argset[i].p = p;
		argset[i].c_re = p->c_real;
		argset[i].c_im = p->c_imaginary;
		if (pthread_create(&t[i], NULL, iterator, (void *)&argset[i]))
			error_exit(1);
	}
	i = -1;
	while (++i < THREAD_NUM)
	{
		if (pthread_join(t[i], NULL))
			error_exit(2);
	}
}
