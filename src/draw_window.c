/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:10:34 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/13 15:38:00 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	reset_window(t_env *env)
{
	unsigned int	i;
	unsigned int	len;

	len = WINDOW_WIDTH * WINDOW_HEIGHT * env->bpp / 8;
	i = 0;
	while (i < len)
	{
		env->mlx_img_data[i] = 0;
		++i;
	}
}

void	draw_window(t_env *env)
{
	reset_window(env);
	draw(env);	
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img_ptr, 0, 0);
}
