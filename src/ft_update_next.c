/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:23:46 by tlafont           #+#    #+#             */
/*   Updated: 2022/07/26 10:11:57 by tlafont          ###   ########.fr       */
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
