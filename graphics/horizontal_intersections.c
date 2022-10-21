/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:23:15 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/21 12:47:13 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	y_x_horizontal(t_mlx *mlx_srct, double x, double y, t_parce *game)
{
	mlx_srct->hited.yintercept = floor(y / TILE_SIZE) * TILE_SIZE;
	if (is_down(mlx_srct->rays.ray_angle))
	{
		mlx_srct->hited.yintercept += TILE_SIZE;
	}
	mlx_srct->hited.xintercept = x + ((mlx_srct->hited.yintercept - y)
			/ tan(mlx_srct->rays.ray_angle));
	mlx_srct->hited.ystep = TILE_SIZE;
	if (!is_down(mlx_srct->rays.ray_angle))
	{
		mlx_srct->hited.ystep *= -1;
	}
	mlx_srct->hited.xstep = TILE_SIZE / tan(mlx_srct->rays.ray_angle);
	if (is_right(mlx_srct->rays.ray_angle) && mlx_srct->hited.xstep < 0)
	{
		mlx_srct->hited.xstep *= -1;
	}
	if (!is_right(mlx_srct->rays.ray_angle) && mlx_srct->hited.xstep > 0)
	{
		mlx_srct->hited.xstep *= -1;
	}
}
