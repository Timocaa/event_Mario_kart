/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:23:46 by tlafont           #+#    #+#             */
/*   Updated: 2022/08/02 16:12:25 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

void	ft_delete_score(t_var *v, int i)
{
	if (v->res.res[i] < 10)
		v->res.res[i] = 0;
	else
		v->res.res[i] = v->res.res[i] / 10;
	if (v->key)
		v->key--;
	if (v->key == 0 && v->cur > 1)
	{
		v->cur--;
		if (v->res.res[i - 1] < 10)
			v->key = 1;
		else
			v->key = 2;
	}
	ft_put_scores(v);
}

void	ft_check_score(t_var *v, int i)
{
	int	max;

	if (i == 0)
		max = 60;
	else if (i == 1)
		max = 48;
	else if (i == 2)
		max = 40;
	else if (i == 3)
		max = 36;
	if (v->res.res[i] > max)
	{
		v->res.res[i] = 0;
		v->key = -1;
		while (++i < 5000)
			mlx_put_image_to_window(v->mlx, v->win, v->back[3], 0, 0);
	}
}

void	ft_update_nbp(int keycode, t_var *v)
{
	if (v->cur == -1 && v->key <= 3)
	{
		if (keycode == XK_0)
			ft_recover_nbp(v, 0);
		if (keycode == XK_1)
			ft_recover_nbp(v, 1);
		if (keycode == XK_2)
			ft_recover_nbp(v, 2);
		if (keycode == XK_3)
			ft_recover_nbp(v, 3);
		if (keycode == XK_4)
			ft_recover_nbp(v, 4);
		if (keycode == XK_5)
			ft_recover_nbp(v, 5);
		if (keycode == XK_6)
			ft_recover_nbp(v, 6);
		if (keycode == XK_7)
			ft_recover_nbp(v, 7);
		if (keycode == XK_8)
			ft_recover_nbp(v, 8);
		if (keycode == XK_9)
			ft_recover_nbp(v, 9);
		if (keycode == XK_BackSpace)
			ft_delete_nbp(v);
	}
}

void	ft_recover_nbp(t_var *v, int nb)
{
	if (v->key == 0)
		v->nb_p = nb;
	if (v->key > 0 && v->key < 3)
		v->nb_p = (v->nb_p * 10) + nb;
	if (v->key < 3)
		v->key++;
	ft_print_nbp(v);
}

void	ft_delete_nbp(t_var *v)
{
	if (v->nb_p < 10)
		v->nb_p = 0;
	else
		v->nb_p = v->nb_p / 10;
	if (v->key)
		v->key--;
	ft_print_nbp(v);
}
