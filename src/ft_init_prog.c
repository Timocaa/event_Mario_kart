/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:27:31 by tlafont           #+#    #+#             */
/*   Updated: 2022/07/16 13:45:51 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

int	ft_check_arg(char *nb_p)
{
	int	i;

	i = -1;
	while (nb_p[++i])
		if (nb_p[i] < '0' || nb_p[i] > '9')
			return (0);
	if (ft_atoi(nb_p) < 4)
		ft_error("Error: nb of players must be up to 4 !\n");
	if (ft_atoi(nb_p) % 4 != 0)
		ft_error("Error: nb of players must be a multiple of 4 !\n");
	if (ft_atoi(nb_p) / 4 > 999)
		ft_error("Error: too many players !\n");
	return (1);
}

int	ft_init_variables(t_var *v, char *nb)
{
	v->nb_p = ft_atoi(nb);
	v->game.game = 1;
	v->game.max = v->nb_p / 4;
	v->tar = (int *)malloc(sizeof(int) * 4);
	v->tar[0] = 23 * v->nb_p;
	v->tar[3] = 46 * v->nb_p;
	v->tar[1] = v->tar[0] + (v->tar[0] / 3);
	v->tar[2] = v->tar[1] + (v->tar[0] / 3);
	v->mlx = mlx_init();
	if (!ft_init_img(v))
		ft_error("Error: initialisation img failed !\n");
	v->win = mlx_new_window(v->mlx, 1200, 600, "event Mario Kart 8");
	mlx_put_image_to_window(v->mlx, v->win, v->back[0], 0, 0);
	ft_print_nb_game(v);
	ft_print_targets(v);
	return (1);
}

int	ft_init_img(t_var *v)
{
	v->back = (void **)malloc(sizeof(void *) * 4);
	if (!v->back)
		return (free(v->mlx), free(v->tar), free(v), 0);
	v->img = (void **)malloc(sizeof(void *) * 5);
	if (!v->img)
		return (free(v->mlx), free(v->tar), free(v->back), free(v), 0);
	v->game.img = (void **)malloc(sizeof(void *) * 10);
	if (!v->game.img)
		return (free(v->mlx), free(v->back), free(v->tar), free(v->img),
			free(v), 0);
	v->res.img = (void **)malloc(sizeof(void *) * 10);
	if (!v->res.img)
		return (free(v->mlx), free(v->back), free(v->game.img), free(v->tar),
			free(v->img), free(v), 0);
	v->end.img = (void **)malloc(sizeof(void *) * 5);
	if (!v->end.img)
		return (free(v->mlx), free(v->back), free(v->game.img), free(v->tar),
			free(v->img), free(v->end.img), free(v), 0);
	ft_open_img(v);
	return (1);
}
/*
void	ft_update_nb_t(t_var *v)
{
	if (v->res.total < v->tar[0])
		v->end.nb_t = 0;
	else if (v->res.total >= v->tar[0])
		v->end.nb_t = 1;
	else if (v->res.total >= v->tar[1])
		v->end.nb_t = 2;
	else if (v->res.total >= v->tar[2])
		v->end.nb_t = 3;
	else if (v->res.total >= v->tar[3])
		v->end.nb_t = 4;
	ft_printf("%d\n", v->end.nb_t);
}*/
