/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:12:40 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/13 16:25:06 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(void)
{
	t_env	*env;

	if (!(env = malloc(sizeof(*env))))
		ft_exit("Error, out of memory.", -1);
	env->pos_x = 5;
	env->pos_y = 7;
	env->dir_x = .5;
	env->dir_y = 0;
	printf("fill grid start\n");
	fill_grid(env);
	printf("fill grid end\n");
	printf("init window start\n");
	init_window(env);
	printf("init window end\n");
	printf("draw window start\n");
	draw_window(env);
	printf("draw window end\n");
	mlx_loop(env->mlx_ptr);
	return (0);
}
