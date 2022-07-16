/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:18:44 by tlafont           #+#    #+#             */
/*   Updated: 2022/07/16 11:03:17 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

int	ft_update_game(int keycode, t_var *v)
{
	if (keycode == XK_Escape)
		ft_close(v);
	if ((v->cur >= 0  && v->cur <= 4) && keycode == XK_Return)
	{
		v->cur++;
		v->key = 0;
		ft_put_scores(v);
	}
	if (v->cur > 0 && v->cur <= 4)
		ft_update_game_next(keycode, v);
	if (v->cur == 5 && keycode == XK_Return)
	{
		ft_update_total(v);
		v->game.game++;
		ft_print_progress(v);
	}
	return (1);
}

void	ft_update_game_next(int keycode, t_var *v)
{
	if ((v->cur > 0 && v->cur < 5) && v->key < 2)
	{
		if (keycode == XK_0)
			ft_recover_score(v, 0, v->cur - 1);
		if (keycode == XK_1)
			ft_recover_score(v, 1, v->cur - 1);
		if (keycode == XK_2)
			ft_recover_score(v, 2, v->cur - 1);
		if (keycode == XK_3)
			ft_recover_score(v, 3, v->cur - 1);
		if (keycode == XK_4)
			ft_recover_score(v, 4, v->cur - 1);
		if (keycode == XK_5)
			ft_recover_score(v, 5, v->cur - 1);
		if (keycode == XK_6)
			ft_recover_score(v, 6, v->cur - 1);
		if (keycode == XK_7)
			ft_recover_score(v, 7, v->cur - 1);
		if (keycode == XK_8)
			ft_recover_score(v, 8, v->cur - 1);
		if (keycode == XK_9)
			ft_recover_score(v, 9, v->cur - 1);
	}
}

void	ft_recover_score(t_var *v, int nb, int i)
{
	if (v->key == 0)
		v->res.res[i] = nb;
	if (v->key == 1)
		v->res.res[i] = (v->res.res[i] * 10) + nb;
	v->key++;
	ft_put_scores(v);
}

void	ft_update_print_score(t_var *v)
{
	int	x;
	int	y;
	int	i;

	x = 600;
	y = 170;
	i = -1;
	while (++i < 4)
	{
		if (v->res.res[i] < 10)
			mlx_put_image_to_window(v->mlx, v->win, v->res.img[v->res.res[i]], x, y + (i * 47));
		else
		{
			mlx_put_image_to_window(v->mlx, v->win, v->res.img[v->res.res[i] / 10], x - 10, y + (i * 47));
			mlx_put_image_to_window(v->mlx, v->win, v->res.img[v->res.res[i] % 10], x, y + (i * 47));
		}
	}
}

void	ft_update_total(t_var *v)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = v->res.total;
	while (++i < 4)
	{
		v->res.total = v->res.total + v->res.res[i];
		v->res.res[i] = 0;
	}
	if (v->res.total > (tmp + 184))
	{
		v->game.game--;
		v->cur = 0;
		v->res.total = tmp;
		while (++i < 5000)
			mlx_put_image_to_window(v->mlx, v->win, v->back[3], 0, 0);
	}
}
