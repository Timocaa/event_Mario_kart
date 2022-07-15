/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variables_next.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:29:15 by tlafont           #+#    #+#             */
/*   Updated: 2022/07/15 17:54:14 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

void	ft_print_target_bar(t_var *v)
{
	int	x;
	int	y;
	int	x_max;
	if (v->res.total >= v->tar[3])
		x_max = 1160;
	else
		x_max = ft_calcul_x_max(v);
	x = 25;
	while (x < x_max)
	{
		y = 564;
		while (y < 584)
		{
			mlx_pixel_put(v->mlx, v->win, x, y, 0x359c01);
			y++;
		}
		x++;
	}
}

int	ft_calcul_x_max(t_var *v)
{
	int	perc;
	int	max;

	if (v->res.total <= v->tar[0])
	{
		perc = (100 * v->res.total) / v->tar[0];
		max = 600;
	}
	else if (v->res.total > v->tar[0] && v->res.total <= v->tar[1])
	{
		perc = (100 * v->res.total) / v->tar[1];
		max = 786;
	}
	else if (v->res.total > v->tar[1] && v->res.total <= v->tar[2])
	{
		perc = (100 * v->res.total) / v->tar[2];
		max = 972;
	}
	else if (v->res.total > v->tar[2])
	{
		perc = (100 * v->res.total) / v->tar[3];
		max = 1160;
	}
	return ((max * perc) / 100);
}

void	ft_print_achiev(t_var *v)
{
	if (v->res.total >= v->tar[0] && v->t == 0)
		ft_put_img_tar(v, 1);
	else if (v->res.total >= v->tar[1] && v->t == 1)
		ft_put_img_tar(v, 2);
	else if (v->res.total >= v->tar[2] && v->t == 2)
		ft_put_img_tar(v, 3);
	else if (v->res.total >= v->tar[3] && v->t == 3)
		ft_put_img_tar(v, 4);
}

void	ft_put_img_tar(t_var *v , int t)
{
	int	i;

	i = -1;
	while (++i < 5000)
		mlx_put_image_to_window(v->mlx, v->win, v->img[t], 0, 0);
	v->t++;
}
