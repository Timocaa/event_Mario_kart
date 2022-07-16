/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:18:26 by tlafont           #+#    #+#             */
/*   Updated: 2022/07/16 13:48:20 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

void	ft_open_img(t_var *v)
{
	int	pix;

	v->back[0] = mlx_xpm_file_to_image(v->mlx, "img/back.xpm", &pix, &pix);
	v->back[1] = mlx_xpm_file_to_image(v->mlx, "img/scores.xpm", &pix, &pix);
	v->back[2] = mlx_xpm_file_to_image(v->mlx, "img/arrow.xpm", &pix, &pix);
	v->back[3] = mlx_xpm_file_to_image(v->mlx, "img/fake.xpm", &pix, &pix);
	ft_open_game(v);
	ft_open_res(v);
	ft_open_tar(v);
	ft_open_end(v);
}

void	ft_open_game(t_var *v)
{
	int	pix;

	v->game.img[0] = mlx_xpm_file_to_image(v->mlx, "img/g_0.xpm", &pix, &pix);
	v->game.img[1] = mlx_xpm_file_to_image(v->mlx, "img/g_1.xpm", &pix, &pix);
	v->game.img[2] = mlx_xpm_file_to_image(v->mlx, "img/g_2.xpm", &pix, &pix);
	v->game.img[3] = mlx_xpm_file_to_image(v->mlx, "img/g_3.xpm", &pix, &pix);
	v->game.img[4] = mlx_xpm_file_to_image(v->mlx, "img/g_4.xpm", &pix, &pix);
	v->game.img[5] = mlx_xpm_file_to_image(v->mlx, "img/g_5.xpm", &pix, &pix);
	v->game.img[6] = mlx_xpm_file_to_image(v->mlx, "img/g_6.xpm", &pix, &pix);
	v->game.img[7] = mlx_xpm_file_to_image(v->mlx, "img/g_7.xpm", &pix, &pix);
	v->game.img[8] = mlx_xpm_file_to_image(v->mlx, "img/g_8.xpm", &pix, &pix);
	v->game.img[9] = mlx_xpm_file_to_image(v->mlx, "img/g_9.xpm", &pix, &pix);
}

void	ft_open_res(t_var *v)
{
	int	pix;

	v->res.img[0] = mlx_xpm_file_to_image(v->mlx, "img/s_0.xpm", &pix, &pix);
	v->res.img[1] = mlx_xpm_file_to_image(v->mlx, "img/s_1.xpm", &pix, &pix);
	v->res.img[2] = mlx_xpm_file_to_image(v->mlx, "img/s_2.xpm", &pix, &pix);
	v->res.img[3] = mlx_xpm_file_to_image(v->mlx, "img/s_3.xpm", &pix, &pix);
	v->res.img[4] = mlx_xpm_file_to_image(v->mlx, "img/s_4.xpm", &pix, &pix);
	v->res.img[5] = mlx_xpm_file_to_image(v->mlx, "img/s_5.xpm", &pix, &pix);
	v->res.img[6] = mlx_xpm_file_to_image(v->mlx, "img/s_6.xpm", &pix, &pix);
	v->res.img[7] = mlx_xpm_file_to_image(v->mlx, "img/s_7.xpm", &pix, &pix);
	v->res.img[8] = mlx_xpm_file_to_image(v->mlx, "img/s_8.xpm", &pix, &pix);
	v->res.img[9] = mlx_xpm_file_to_image(v->mlx, "img/s_9.xpm", &pix, &pix);
}

void	ft_open_tar(t_var *v)
{
	int	pix;

	v->img[0] = mlx_xpm_file_to_image(v->mlx, "img/tar0.xpm", &pix, &pix);
	v->img[1] = mlx_xpm_file_to_image(v->mlx, "img/tar1.xpm", &pix, &pix);
	v->img[2] = mlx_xpm_file_to_image(v->mlx, "img/tar2.xpm", &pix, &pix);
	v->img[3] = mlx_xpm_file_to_image(v->mlx, "img/tar3.xpm", &pix, &pix);
	v->img[4] = mlx_xpm_file_to_image(v->mlx, "img/tar4.xpm", &pix, &pix);
}

void	ft_open_end(t_var *v)
{
	int	pix;

	v->end.img[0] = mlx_xpm_file_to_image(v->mlx, "img/end.xpm", &pix, &pix);
	v->end.img[1] = mlx_xpm_file_to_image(v->mlx, "img/win_test.xpm",
			&pix, &pix);
	v->end.img[2] = mlx_xpm_file_to_image(v->mlx, "img/win_test.xpm",
			&pix, &pix);
	v->end.img[3] = mlx_xpm_file_to_image(v->mlx, "img/win_test.xpm",
			&pix, &pix);
	v->end.img[4] = mlx_xpm_file_to_image(v->mlx, "img/win_test.xpm",
			&pix, &pix);
}
