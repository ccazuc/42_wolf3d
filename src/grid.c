/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:32:51 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/13 15:59:39 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	fill_grid(t_env *env)
{
	int		i;
	char	**grid;

	if (!(grid = malloc(MAP_HEIGHT * sizeof(*grid))))
		ft_exit("Error, out of memory.", -1);
	i = -1;
	grid[0] = ft_strdup("1111111111");
	grid[1] = ft_strdup("10011100001");
	grid[2] = ft_strdup("10000010001");
	grid[3] = ft_strdup("10111100001");
	grid[4] = ft_strdup("10000100001");
	grid[5] = ft_strdup("10111100001");
	grid[6] = ft_strdup("10111110001");
	grid[7] = ft_strdup("10111100001");
	grid[8] = ft_strdup("10111100001");
	grid[9] = ft_strdup("1111111111");
	env->grid = grid;
}
