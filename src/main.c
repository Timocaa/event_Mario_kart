/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:59:04 by tlafont           #+#    #+#             */
/*   Updated: 2022/08/02 21:03:30 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

int	main(int ac, char **av)
{
	t_var	*v;

	if (ac == 1)
	{
		v = (t_var *)ft_calloc(sizeof(t_var), 1);
		if (!v)
			ft_error("Error: allocation variables !\n");
		if (ft_init_variables(v, av[1]))
		{
			mlx_key_hook(v->win, ft_update_game, v);
			mlx_hook(v->win, DestroyNotify, 0, ft_close, v);
			mlx_loop(v->mlx);
		}
	}
	else
		ft_error("Error: start with [./event_mk] !\n");
	return (0);
}
