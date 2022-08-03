/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variables_next.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:29:15 by tlafont           #+#    #+#             */
/*   Updated: 2022/08/03 11:59:01 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

/*
display of the progress bar of the participants' points
*/
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

/*
determine the max value of the abscisses according
to the level to be reached
*/
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

/*
determination of the level reached during the game for its display
*/
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

/*
display of the level during the game
*/
void	ft_put_img_tar(t_var *v, int t)
{
	int	i;

	i = -1;
	while (++i < 5000)
		mlx_put_image_to_window(v->mlx, v->win, v->img[t], 0, 0);
	v->t++;
}

/*
display of the recapitulative end of program window
*/
void	ft_print_end(t_var *v)
{
	v->cur = 6;
	if (v->t == 0)
		mlx_put_image_to_window(v->mlx, v->win, v->img[0], 0, 0);
	else
	{
		mlx_put_image_to_window(v->mlx, v->win, v->end.img[0], 0, 0);
		mlx_put_image_to_window(v->mlx, v->win, v->end.img[1], 120, 200);
		if (v->t == 1)
			mlx_put_image_to_window(v->mlx, v->win, v->end.img[2],
				120, 240);
		else if (v->t == 2)
			mlx_put_image_to_window(v->mlx, v->win, v->end.img[3],
				120, 240);
		else if (v->t == 3)
			mlx_put_image_to_window(v->mlx, v->win, v->end.img[4],
				120, 240);
		else if (v->t == 4)
			mlx_put_image_to_window(v->mlx, v->win, v->end.img[5],
				120, 240);
	}
}
