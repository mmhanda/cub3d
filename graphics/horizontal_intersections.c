/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:23:15 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/25 16:00:10 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	y_x_horizontal(t_mlx *mlx_srct, double x, double y)
{
	mlx_srct->r.yintercept = floor(y / TILE_SIZE) * TILE_SIZE;
	if (is_down(mlx_srct->rays.ray_angle))
	{
		mlx_srct->r.yintercept += TILE_SIZE;
	}
	mlx_srct->r.xintercept = x + ((mlx_srct->r.yintercept - y)
			/ tan(mlx_srct->rays.ray_angle));
	mlx_srct->r.ystep = TILE_SIZE;
	if (!is_down(mlx_srct->rays.ray_angle))
	{
		mlx_srct->r.ystep *= -1;
	}
	mlx_srct->r.xstep = TILE_SIZE / tan(mlx_srct->rays.ray_angle);
	if (is_right(mlx_srct->rays.ray_angle) && mlx_srct->r.xstep < 0)
	{
		mlx_srct->r.xstep *= -1;
	}
	if (!is_right(mlx_srct->rays.ray_angle) && mlx_srct->r.xstep > 0)
	{
		mlx_srct->r.xstep *= -1;
	}
}
