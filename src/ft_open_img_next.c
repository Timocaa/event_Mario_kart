/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_img_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:49:48 by tlafont           #+#    #+#             */
/*   Updated: 2022/08/03 11:17:03 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/event_mk.h"

/*
loading sprites for participant numbers and background image
*/
void	ft_open_nbp(t_var *v)
{
	int	pix;

	v->nbp.img[0] = mlx_xpm_file_to_image(v->mlx, "img/p0.xpm", &pix, &pix);
	v->nbp.img[1] = mlx_xpm_file_to_image(v->mlx, "img/p1.xpm", &pix, &pix);
	v->nbp.img[2] = mlx_xpm_file_to_image(v->mlx, "img/p2.xpm", &pix, &pix);
	v->nbp.img[3] = mlx_xpm_file_to_image(v->mlx, "img/p3.xpm", &pix, &pix);
	v->nbp.img[4] = mlx_xpm_file_to_image(v->mlx, "img/p4.xpm", &pix, &pix);
	v->nbp.img[5] = mlx_xpm_file_to_image(v->mlx, "img/p5.xpm", &pix, &pix);
	v->nbp.img[6] = mlx_xpm_file_to_image(v->mlx, "img/p6.xpm", &pix, &pix);
	v->nbp.img[7] = mlx_xpm_file_to_image(v->mlx, "img/p7.xpm", &pix, &pix);
	v->nbp.img[8] = mlx_xpm_file_to_image(v->mlx, "img/p8.xpm", &pix, &pix);
	v->nbp.img[9] = mlx_xpm_file_to_image(v->mlx, "img/p9.xpm", &pix, &pix);
	v->nbp.img[10] = mlx_xpm_file_to_image(v->mlx, "img/nbj.xpm", &pix, &pix);
}
