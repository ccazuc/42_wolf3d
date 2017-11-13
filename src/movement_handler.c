/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:20:12 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/13 16:27:29 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	rotate_left(t_env *env)
{
	double	old_dir_x;
	double	old_plane_x;
	int		speed = 1;

	old_dir_x = env->dir_x;
	old_plane_x = env->plane_x;
	env->dir_x = env->dir_x * cos(-speed) - env->dir_y * sin(-speed);
	env->dir_y = old_dir_x * sin(-speed) + env->dir_y * cos(-speed);
	env->plane_x = env->plane_x * cos(-speed) - env->plane_y * sin(-speed);
	env->plane_y = old_plane_x * sin(-speed) + env->plane_y * cos(-speed);
	draw_window(env);
}
