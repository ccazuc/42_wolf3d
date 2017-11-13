/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:19:51 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/13 16:31:29 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calculate_step(t_ray *ray, int map_x, int map_y)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
	}
}

void	fill_ray(t_env *env, int x, t_ray *ray)
{
	double	camera_x;

	camera_x = 2 * x / WINDOW_WIDTH - 1;
	ray->pos_x = env->pos_x;
	ray->pos_y = env->pos_y;
	ray->dir_x = env->dir_x + env->plane_x * camera_x;
	ray->dir_y = env->dir_y + env->plane_y * camera_x;
	ray->delta_dist_x = sqrt(1 + (ray->dir_y * ray->dir_y) / (ray->dir_x * ray->dir_x));
	ray->delta_dist_y = sqrt(1 + (ray->dir_x * ray->dir_x) / (ray->dir_y * ray->dir_y));
	ray->hit = 0;
	ray->side = 0;
}

void	perform_dda(t_env *env, t_ray *ray, int *map_x, int *map_y)
{
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			*map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			*map_y += ray->step_y;
			ray->side = 1;
		}
		printf("map_x: %d, map_y: %d\n", *map_x, *map_y);
		if (env->grid[*map_x][*map_y] > '0')
		{
			ray->hit = 1;
			printf("RAY HIT, x: %d, y: %d\n", *map_x, *map_y);
		}
	}		
}

void	draw(t_env *env)
{
	int		x;
	int		map_x;
	int		map_y;
	t_ray	ray;

	x = -1;
	printf("draw start\n");
	while (++x < WINDOW_WIDTH)
	{
		//printf("fill ray start\n");
		fill_ray(env, x, &ray);
		//printf("fill ray end\n");
		map_x = ray.pos_x;
		map_y = ray.pos_y;
		//printf("calculate step start\n");
		calculate_step(&ray, map_x, map_y);
		//printf("calculate step end\n");
		//printf("perform dda start\n");
		perform_dda(env, &ray, &map_x, &map_y);
		//printf("perform dda end\n");
		if (ray.side == 0)
			ray.perp_wall_dist = (map_x - ray.pos_x + (1 - ray.step_x) / 2) / ray.dir_x;
		else
			ray.perp_wall_dist = (map_y - ray.pos_y + (1 - ray.step_y) / 2) / ray.dir_y;
		printf("perp_wall_dist: %f\n", ray.perp_wall_dist);
		ray.line_height = (int)(WINDOW_HEIGHT / ray.perp_wall_dist);
		ray.draw_start = -ray.line_height / 2 + WINDOW_HEIGHT / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = ray.line_height / 2 + WINDOW_HEIGHT / 2;
		if (ray.draw_end >= WINDOW_HEIGHT)
			ray.draw_end = WINDOW_HEIGHT - 1;
		//printf("ray.draw_start: %d, ray.draw_end: %d\n", ray.draw_start, ray.draw_end);
		draw_line(env, ray, x, 0xFF0000);
	}
}
