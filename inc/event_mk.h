/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:53:50 by tlafont           #+#    #+#             */
/*   Updated: 2022/07/19 12:07:00 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_MK_H
# define EVENT_MK_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_res
{
	int		res[4];
	int		total;
	void	**img;
}	t_res;

typedef struct s_end
{
	void	**img;
}	t_end;

typedef struct s_game
{
	int		max;
	int		game;
	void	**img;
}	t_game;

typedef struct s_var
{
	int		nb_p;
	int		*tar;
	void	**img;
	t_res	res;
	t_game	game;
	t_end	end;
	int		cur;
	int		key;
	int		t;
	void	*mlx;
	void	*win;
	void	**back;
}	t_var;

//-------------------- fct end prog --------------------
void	ft_error(char *str);
int		ft_close(t_var *vars);
void	ft_destroy_img(t_var *v);

//-------------------- fct init pro --------------------
int		ft_check_arg(char *nb_p);
int		ft_init_variables(t_var *v, char *nb);
int		ft_init_img(t_var *v);
void	ft_put_target(t_var *v, char *lvl, int i);

//-------------------- fct open img --------------------
void	ft_open_img(t_var *v);
void	ft_open_game(t_var *v);
void	ft_open_res(t_var *v);
void	ft_open_tar(t_var *v);
void	ft_open_end(t_var *v);
//--------------------- fct print   ---------------------
void	ft_print_nb_game(t_var *v);
void	ft_print_targets(t_var *v);
void	ft_put_scores(t_var *v);
void	ft_print_progress(t_var *v);
void	ft_put_arrow(t_var *v);
//--------------------- fct print 2 ---------------------
void	ft_print_target_bar(t_var *v);
int		ft_calcul_x_max(t_var *v);
void	ft_print_achiev(t_var *v);
void	ft_put_img_tar(t_var *v, int t);
void	ft_print_end(t_var *v);
//--------------------- fct update  ---------------------
int		ft_update_game(int keycode, t_var *v);
void	ft_update_game_next(int keycode, t_var *v);
void	ft_recover_score(t_var *v, int nb, int i);
void	ft_update_print_score(t_var *v);
void	ft_update_total(t_var *v);

#endif
