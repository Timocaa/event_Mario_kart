/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_ter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:12:45 by tlafont           #+#    #+#             */
/*   Updated: 2022/08/02 20:59:04 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

int	ft_check_nbp(t_var *v)
{
	if (v->nb_p < 4)
		return (ft_put_error(v, "nb of players must be up to 4 !"), 0);
	if (v->nb_p % 4 != 0)
		return (ft_put_error(v, "nb of players must be a multiple of 4 !"), 0);
	if (v->nb_p > 450)
		return (ft_put_error(v, "too many players !"), 0);
	return (1);
}

void	ft_put_error(t_var *v, char *err)
{
	int	i;

	i = -1;
	while (++i < 5000)
	{
		mlx_string_put(v->mlx, v->win, 350, 444, 0xff0000, err);
		usleep(400);
	}
	v->nb_p = 0;
	v->key = 0;
	ft_print_nbp(v);
}
