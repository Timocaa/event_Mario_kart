/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variables_ter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:18:44 by tlafont           #+#    #+#             */
/*   Updated: 2022/08/03 12:04:19 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

/*
display of the maximum number of games to play
*/
void	ft_print_nb_game_max(t_var *v)
{
	int	u;
	int	d;
	int	h;

	ft_calcul_nb_game(v->game.max, &u, &d, &h);
	if (!d && !h)
		mlx_put_image_to_window(v->mlx, v->win, v->game.img[u], 614, 43);
	else if (d && !h)
		mlx_put_image_to_window(v->mlx, v->win, v->game.img[u], 637, 43);
	else
		mlx_put_image_to_window(v->mlx, v->win, v->game.img[u], 660, 43);
	if (d && !h)
		mlx_put_image_to_window(v->mlx, v->win, v->game.img[d], 614, 43);
	else if ((!d && h) || (d && h))
		mlx_put_image_to_window(v->mlx, v->win, v->game.img[d], 637, 43);
	if (h != 0)
		mlx_put_image_to_window(v->mlx, v->win, v->game.img[h], 614, 43);
}

/*
determine the units, ten and hundreds of a number
*/
void	ft_calcul_nb_game(int nb_g, int *u, int *d, int *h)
{
	if (nb_g < 10)
	{
		*u = nb_g;
		*d = 0;
		*h = 0;
	}
	else
	{
		*u = nb_g % 10;
		*d = (nb_g / 10) % 10;
		*h = nb_g / 100;
	}
}

/*
displays the number of participants when entering
*/
void	ft_print_nbp(t_var *v)
{
	int	u;
	int	d;
	int	h;

	mlx_put_image_to_window(v->mlx, v->win, v->nbp.img[10], 0, 0);
	ft_calcul_nb_game(v->nb_p, &u, &d, &h);
	if (!d && !h)
		mlx_put_image_to_window(v->mlx, v->win, v->nbp.img[u], 440, 409);
	else if (d && !h)
		mlx_put_image_to_window(v->mlx, v->win, v->nbp.img[u], 455, 409);
	else
		mlx_put_image_to_window(v->mlx, v->win, v->nbp.img[u], 470, 409);
	if (d && !h)
		mlx_put_image_to_window(v->mlx, v->win, v->nbp.img[d], 440, 409);
	else if ((!d && h) || (d && h))
		mlx_put_image_to_window(v->mlx, v->win, v->nbp.img[d], 455, 409);
	if (h != 0)
		mlx_put_image_to_window(v->mlx, v->win, v->nbp.img[h], 440, 409);
}
