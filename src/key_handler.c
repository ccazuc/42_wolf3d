/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:57:39 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/13 16:24:20 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_up_handler(int keycode, void *datas)
{
	t_env	*env;

	env = datas;
	printf("Key Up: %d\n", keycode);
	if (keycode == 123 || keycode == 0)
		rotate_left(env);
	if (keycode == 124 || keycode == 2)
		//move_right(env);
		;
	if (keycode == 126 || keycode == 13)
		//move_forward(env);
		;
	if (keycode == 125 || keycode == 1)
		//move_backward(env);
		;
	if (keycode == 53)
		ft_exit("Exit requested.", 0);
	return (0);
}

int		key_down_handler(int keycode, void *datas)
{
	t_env	*env;

	env = datas;
	printf("Key Down: %d\n", keycode);
	return (0);
}
