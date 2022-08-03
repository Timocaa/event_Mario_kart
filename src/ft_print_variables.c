/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:10:40 by tlafont           #+#    #+#             */
/*   Updated: 2022/08/03 11:26:02 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

/*
display of the digits of the current game number
*/
void	ft_print_nb_game(t_var *v)
{
	int	u;
	int	d;
	int	h;

	ft_calcul_nb_game(v->game.game, &u, &d, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->game.img[10], 591, 44);
	mlx_put_image_to_window(v->mlx, v->win, v->game.img[u], 568, 43);
	ft_print_nb_game_max(v);
	if (d != 0 || h != 0)
		mlx_put_image_to_window(v->mlx, v->win, v->game.img[d], 545, 43);
	if (h != 0)
		mlx_put_image_to_window(v->mlx, v->win, v->game.img[h], 522, 43);
}

/*
display of the tiers and their remaining values
*/
void	ft_print_targets(t_var *v)
{
	char	*nb;
	int		i;
	char	*name;
	char	*pts;

	i = -1;
	name = "Birdman";
	pts = "number of remaining points to be made :";
	mlx_string_put(v->mlx, v->win, 10, 10, 0xff0000, name);
	mlx_string_put(v->mlx, v->win, 10, 555, 0xffffff, pts);
	while (++i < 4)
	{
		nb = ft_itoa(v->tar[i] - v->res.total);
		if (v->tar[i] - v->res.total >= 0)
			mlx_string_put(v->mlx, v->win, 570 + (187 * i), 555, 0xffffff, nb);
		if (i == 0)
			ft_put_target(v, "BRONZE", i);
		else if (i == 1)
			ft_put_target(v, "SILVER", i);
		else if (i == 2)
			ft_put_target(v, "GOLD", i);
		else if (i == 3)
			ft_put_target(v, "PLATINUM", i);
		free(nb);
	}
}

/*
function to display the score entry window
*/
void	ft_put_scores(t_var *v)
{
	ft_print_achiev(v);
	mlx_put_image_to_window(v->mlx, v->win, v->back[1], 0, 0);
	ft_print_nb_game(v);
	ft_print_targets(v);
	ft_update_print_score(v);
	ft_put_arrow(v);
	ft_print_target_bar(v);
}

/*
input line indicator arrow display
*/
void	ft_put_arrow(t_var *v)
{
	if (v->cur == 1)
		mlx_put_image_to_window(v->mlx, v->win, v->back[2], 650, 164);
	else if (v->cur == 2)
		mlx_put_image_to_window(v->mlx, v->win, v->back[2], 650, 212);
	else if (v->cur == 3)
		mlx_put_image_to_window(v->mlx, v->win, v->back[2], 650, 258);
	else if (v->cur == 4)
		mlx_put_image_to_window(v->mlx, v->win, v->back[2], 650, 305);
}

/*
function that displays the progress window and/or the level reached
*/
void	ft_print_progress(t_var *v)
{
	v->cur = 0;
	ft_print_achiev(v);
	if (v->game.game > v->game.max)
	{
		ft_print_achiev(v);
		ft_print_end(v);
	}
	else
	{
		mlx_put_image_to_window(v->mlx, v->win, v->back[0], 0, 0);
		ft_print_nb_game(v);
		ft_print_targets(v);
		ft_print_target_bar(v);
	}
}
