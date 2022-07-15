/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:11:53 by tlafont           #+#    #+#             */
/*   Updated: 2022/07/15 17:01:13 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

void	ft_error(char *str)
{
	write(2, "\033[31m   ", 8);
	write(2, str, ft_strlen(str));
	write(2, "\033[0m", 4);
	exit (1);
}

int	ft_close(t_var *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	ft_destroy_img(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->back);
	free(vars->game.img);
	free(vars->res.img);
	free(vars->tar);
	free(vars->img);
	free(vars);
	exit(1);
	return (0);
}

void	ft_destroy_img(t_var *v)
{
	int	i;

	i = -1;
	while (++i < 10)
	{
		if (i <= 3)
			mlx_destroy_image(v->mlx, v->back[i]);
		if (i <= 4)
			mlx_destroy_image(v->mlx, v->img[i]);
		mlx_destroy_image(v->mlx, v->game.img[i]);
		mlx_destroy_image(v->mlx, v->res.img[i]);
	}
}
