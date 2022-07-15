/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:10:40 by tlafont           #+#    #+#             */
/*   Updated: 2022/07/15 17:59:39 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

void	ft_print_nb_game(t_var *v)
{
	int	u;
	int	d;
	int	h;

	if (v->game.game < 10)
	{
		u = v->game.game;
		d = 0;
		h = 0;
	}
	else
	{
		u = v->game.game % 10;
		d = (v->game.game / 10) % 10;
		h = v->game.game / 100;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->game.img[u], 620, 43);
	if (d != 0 || h != 0)
		mlx_put_image_to_window(v->mlx, v->win, v->game.img[d], 595, 43);
	if (h != 0)
		mlx_put_image_to_window(v->mlx, v->win, v->game.img[h], 570, 43);
}

void	ft_print_targets(t_var *v)
{
	char	*nb;
	int		i;

	i = -1;
	while (++i < 4)
	{
		nb = ft_itoa(v->tar[i]);
		mlx_string_put(v->mlx, v->win, 590 + (185 * i), 540, 0xffffff, nb);
		free(nb);
	}
}

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

void	ft_print_progress(t_var *v)
{
	v->cur = 0;
	ft_print_achiev(v);
	mlx_put_image_to_window(v->mlx, v->win, v->back[0], 0, 0);
	ft_print_nb_game(v);
	ft_print_targets(v);
	ft_print_target_bar(v);
}
