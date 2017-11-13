/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:53:35 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/13 15:36:12 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_window(t_env *env)
{
	int		line_size;
	int		bpp;
	int		order;

	if (!(env->mlx_ptr = mlx_init()))
		ft_exit("Error, failed to inti connection.", -1);
	if (!(env->mlx_win = mlx_new_window(env->mlx_ptr, WINDOW_WIDTH,
		WINDOW_HEIGHT, WINDOW_NAME)))
		ft_exit("Error, failed to create window.", -1);
	if (!(env->mlx_img_ptr = mlx_new_image(env->mlx_ptr, WINDOW_WIDTH,
		WINDOW_HEIGHT)))
		ft_exit("Error, failed to create image.", -1);
	line_size = WINDOW_WIDTH * 3;
	bpp = 24;
	order = 1;
	if (!(env->mlx_img_data = mlx_get_data_addr(env->mlx_img_ptr, &bpp,
		&line_size, &order)))
		ft_exit("Error, failed to load image datas.", -1);
	env->bpp = bpp;
	mlx_hook(env->mlx_win, 2, 1, key_down_handler, env);
	mlx_hook(env->mlx_win, 3, 2, key_up_handler, env);
}
