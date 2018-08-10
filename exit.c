/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 20:38:43 by afesyk            #+#    #+#             */
/*   Updated: 2018/06/03 14:05:33 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	free_everything(t_mlx *p)
{
	t_obj	*otmp;
	t_light	*ltmp;

	if (!p)
		return ;
	while (p->scene)
	{
		otmp = p->scene;
		p->scene = p->scene->next;
		ft_memdel((void**)&otmp);
	}
	while (p->light)
	{
		ltmp = p->light;
		p->light = p->light->next;
		ft_memdel((void**)&ltmp);
	}
	ft_memdel((void**)p);
}

int		just_exit(t_mlx *p)
{
	free_everything(p);
	exit(0);
}

void	error_exit(int n, t_mlx *p)
{
	if (n == 0)
		ft_putstr_fd("MLX error\n", 2);
	if (n == 1 && ++n)
		ft_putstr_fd("There's no such scene, you fool!\n", 2);
	if (n == 2)
		ft_putstr_fd("usage: ./RTv1\tscene1\n\t\tscene2"
							"\n\t\tscene3\n\t\tscene4\n", 2);
	if (n == 3)
		ft_putstr_fd("Error: invalid scene parameters\n", 2);
	if (n == 4)
		ft_putstr_fd("Error allocating memory\n", 2);
	if (n != 2)
		free_everything(p);
	exit(-1);
}
