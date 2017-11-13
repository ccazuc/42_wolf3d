/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:13:13 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/13 16:23:52 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define FOV 60
# define PLAYER_HEIGHT 32
# define WALL_DIM 64
# define WINDOW_WIDTH 400
# define WINDOW_NAME "cc"
# define SCREEN_DIST 200
# define WINDOW_HEIGHT 400
# define MAP_WIDTH 10
# define MAP_HEIGHT 10

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_img_ptr;
	char			*mlx_img_data;
	int				bpp;
	char			**grid;
	float			angle;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_env;

typedef struct		s_ray
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			dx;
	double			dy;
	double			len;
	int				side;
	int				hit;
	double			perp_wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	double			side_dist_x;
	double			side_dist_y;
}					t_ray;

void				draw_line(t_env *env, t_ray ray, int x, unsigned int color);
void				pixel_put(t_env *env, int x, int y, unsigned int color);
void				fill_grid(t_env *env);
void				init_window(t_env *env);
void				draw_window(t_env *env);
void				draw(t_env *env);
int					key_up_handler(int keycode,  void *datas);
int					key_down_handler(int keycode, void *datas);
void				rotate_left(t_env *env);

#endif
