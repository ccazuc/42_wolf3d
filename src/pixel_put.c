/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:25:23 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/13 15:50:18 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			draw_line(t_env *env, t_ray ray, int x, unsigned int color)
{
	int		i;

	i = ray.draw_start;
	while (++i < ray.draw_end)
		pixel_put(env, x, i, color);
}

unsigned int	conv_rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void			pixel_put(t_env *env, int x, int y, unsigned int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF);
	env->mlx_img_data[y * WINDOW_WIDTH * env->bpp / 8 + env->bpp
		/ 8 * x] = b;
	env->mlx_img_data[y * WINDOW_WIDTH * env->bpp / 8 + env->bpp
		/ 8 * x + 1] = g;
	env->mlx_img_data[y * WINDOW_WIDTH * env->bpp / 8 + env->bpp
		/ 8 * x + 2] = r;
}
