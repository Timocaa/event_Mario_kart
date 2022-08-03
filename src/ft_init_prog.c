/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:27:31 by tlafont           #+#    #+#             */
/*   Updated: 2022/08/03 11:08:26 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

/*
initialization of the var structure
and allocation of the tier table to be achieved
*/
int	ft_init_variables(t_var *v, char *nb)
{
	(void)nb;
	v->nb_p = 0;
	v->game.game = 1;
	v->tar = (int *)malloc(sizeof(int) * 4);
	if (!v->tar)
		return (ft_error("Error: alloc targets failed !\n"), 0);
	v->cur = -1;
	v->mlx = mlx_init();
	if (!ft_init_img(v))
		return (ft_error("Error: initialisation img failed !\n"), 0);
	v->win = mlx_new_window(v->mlx, 1200, 600, "event Mario Kart 8");
	ft_print_nbp(v);
	return (1);
}

/*
allocation of tables for program sprites
*/
int	ft_init_img(t_var *v)
{
	v->back = (void **)malloc(sizeof(void *) * 4);
	if (!v->back)
		return (free(v->mlx), free(v->tar), free(v), 0);
	v->img = (void **)malloc(sizeof(void *) * 5);
	if (!v->img)
		return (free(v->mlx), free(v->tar), free(v->back), free(v), 0);
	v->game.img = (void **)malloc(sizeof(void *) * 11);
	if (!v->game.img)
		return (free(v->mlx), free(v->back), free(v->tar), free(v->img),
			free(v), 0);
	v->res.img = (void **)malloc(sizeof(void *) * 10);
	if (!v->res.img)
		return (free(v->mlx), free(v->back), free(v->game.img), free(v->tar),
			free(v->img), free(v), 0);
	v->end.img = (void **)malloc(sizeof(void *) * 6);
	if (!v->end.img)
		return (free(v->mlx), free(v->back), free(v->game.img), free(v->tar),
			free(v->img), free(v->res.img), free(v), 0);
	v->nbp.img = (void **)malloc(sizeof(void *) * 11);
	if (!v->nbp.img)
		return (free(v->mlx), free(v->back), free(v->game.img), free(v->tar),
			free(v->img), free(v->res.img), free(v->end.img), free(v), 0);
	ft_open_img(v);
	return (1);
}

/*
display of the number of points to reach the levels
*/
void	ft_put_target(t_var *v, char *lvl, int i)
{
	int	j;
	int	k;

	j = 569 + (185 * i);
	while (++j < 630 + (185 * i))
	{
		k = 509;
		while (++k < 539)
		{
			if (i == 0)
				mlx_pixel_put(v->mlx, v->win, j, k, 0x614e1a);
			else if (i == 1)
				mlx_pixel_put(v->mlx, v->win, j, k, 0xc0c0c0);
			else if (i == 2)
				mlx_pixel_put(v->mlx, v->win, j, k, 0xd4af37);
			else if (i == 3)
				mlx_pixel_put(v->mlx, v->win, j, k, 0xa8a7ae);
		}
	}
	if (i < 3)
		mlx_string_put(v->mlx, v->win, 580 + (187 * i), 530, 0xffffff, lvl);
	else
		mlx_string_put(v->mlx, v->win, 580 + (183 * i), 530, 0xffffff, lvl);
}

/*
initialization of the step values and variables
for the beginning of the program
*/
void	ft_init_vars_game(t_var *v)
{
	v->tar[0] = 23 * v->nb_p;
	v->tar[3] = 46 * v->nb_p;
	v->tar[1] = v->tar[0] + (v->tar[0] / 3);
	v->tar[2] = v->tar[1] + (v->tar[0] / 3);
	v->game.max = v->nb_p / 4;
	v->cur++;
	v->key = 0;
	ft_print_progress(v);
}
