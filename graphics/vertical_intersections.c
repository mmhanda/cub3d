/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:23:09 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/21 08:37:49 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	y_x_vertical(t_mlx *mlx_srct, double x, double y, t_parce *game)
{
	mlx_srct->hited.xintercept = floor(x / TILE_SIZE) * TILE_SIZE;
	if (is_right(mlx_srct->rays.ray_angle))
		mlx_srct->hited.xintercept += TILE_SIZE;
	mlx_srct->hited.yintercept = y + (mlx_srct->hited.xintercept - x)
		* tan(mlx_srct->rays.ray_angle);
	mlx_srct->hited.xstep = TILE_SIZE;
	if (!is_right(mlx_srct->rays.ray_angle))
	{
		mlx_srct->hited.xstep *= -1;
	}
	mlx_srct->hited.ystep = TILE_SIZE * tan(mlx_srct->rays.ray_angle);
	if (!is_down(mlx_srct->rays.ray_angle) && mlx_srct->hited.ystep > 0)
	{
		mlx_srct->hited.ystep *= -1;
	}
	if (is_down(mlx_srct->rays.ray_angle) && mlx_srct->hited.ystep < 0)
	{
		mlx_srct->hited.ystep *= -1;
	}
	mlx_srct->hited.tmpx = mlx_srct->hited.xintercept;
	mlx_srct->hited.tmpy = mlx_srct->hited.yintercept;
}
