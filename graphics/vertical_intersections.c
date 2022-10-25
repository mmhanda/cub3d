/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:23:09 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/25 16:01:12 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	y_x_vertical(t_mlx *mlx_srct, double x, double y)
{
	mlx_srct->r.xintercept = floor(x / TILE_SIZE) * TILE_SIZE;
	if (is_right(mlx_srct->rays.ray_angle))
		mlx_srct->r.xintercept += TILE_SIZE;
	mlx_srct->r.yintercept = y + (mlx_srct->r.xintercept - x)
		* tan(mlx_srct->rays.ray_angle);
	mlx_srct->r.xstep = TILE_SIZE;
	if (!is_right(mlx_srct->rays.ray_angle))
	{
		mlx_srct->r.xstep *= -1;
	}
	mlx_srct->r.ystep = TILE_SIZE * tan(mlx_srct->rays.ray_angle);
	if (!is_down(mlx_srct->rays.ray_angle) && mlx_srct->r.ystep > 0)
	{
		mlx_srct->r.ystep *= -1;
	}
	if (is_down(mlx_srct->rays.ray_angle) && mlx_srct->r.ystep < 0)
	{
		mlx_srct->r.ystep *= -1;
	}
	mlx_srct->r.tmpx = mlx_srct->r.xintercept;
	mlx_srct->r.tmpy = mlx_srct->r.yintercept;
}
