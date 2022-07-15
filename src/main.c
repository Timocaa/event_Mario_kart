/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:59:04 by tlafont           #+#    #+#             */
/*   Updated: 2022/07/13 12:28:17 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

int	main(int ac, char **av)
{
	t_var	*v;

	if (ac != 2 || !ft_check_arg(av[1]))
		ft_error("Error: start with ./event_mk [nb_players] !\n");
	v = (t_var *)ft_calloc(sizeof(t_var), 1);
	if (!v)
		ft_error("Error: allocation variables !\n");
	if (ft_init_variables(v, av[1]))
	{
		mlx_key_hook(v->win, ft_update_game, v);
		mlx_hook(v->win, DestroyNotify, 0, ft_close, v);
		mlx_loop(v->mlx);
	}
	return (0);
}
