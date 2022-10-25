/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:23:43 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/25 14:14:15 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_horizontal_intersections(t_mlx *mlx_srct, double x, double y,
		t_parce *game)
{
	y_x_horizontal(mlx_srct, x, y, game);
	mlx_srct->hited.tmpx = mlx_srct->hited.xintercept;
	mlx_srct->hited.tmpy = mlx_srct->hited.yintercept;
	while (mlx_srct->hited.tmpx >= 0
		&& mlx_srct->hited.tmpx <= ((mlx_srct->longest_line - 1) * TILE_SIZE)
		&& mlx_srct->hited.tmpy >= 0
		&& mlx_srct->hited.tmpy <= ((mlx_srct->tab_len - 1) * TILE_SIZE))
	{
		mlx_srct->hited.mapindex_x = mlx_srct->hited.tmpx / TILE_SIZE;
		mlx_srct->hited.mapindex_y = mlx_srct->hited.tmpy / TILE_SIZE;
		if (!is_down(mlx_srct->rays.ray_angle))
			mlx_srct->hited.mapindex_y -= 1;
		if (check_wall_2(game, mlx_srct->hited.mapindex_x,
				mlx_srct->hited.mapindex_y) == 1)
		{
			mlx_srct->hited.wallhitx = mlx_srct->hited.tmpx;
			mlx_srct->hited.wallhity = mlx_srct->hited.tmpy;
			mlx_srct->hited.horx = mlx_srct->hited.tmpx;
			mlx_srct->hited.hory = mlx_srct->hited.tmpy;
			mlx_srct->hited.horhit = true;
			mlx_srct->hited.offset = (int)mlx_srct->hited.wallhitx % TILE_SIZE;
			break ;
		}
		else
		{
			mlx_srct->hited.tmpx += mlx_srct->hited.xstep;
			mlx_srct->hited.tmpy += mlx_srct->hited.ystep;
		}
	}
}

void	check_vertical_intersections(t_mlx *mlx_srct, double x, double y,
		t_parce *game)
{
	y_x_vertical(mlx_srct, x, y, game);
	while (mlx_srct->hited.tmpx >= 0
		&& mlx_srct->hited.tmpx <= ((mlx_srct->longest_line - 1) * TILE_SIZE)
		&& mlx_srct->hited.tmpy >= 0
		&& mlx_srct->hited.tmpy <= ((mlx_srct->tab_len - 1) * TILE_SIZE))
	{
		mlx_srct->hited.mapindex_x = mlx_srct->hited.tmpx / TILE_SIZE;
		mlx_srct->hited.mapindex_y = mlx_srct->hited.tmpy / TILE_SIZE;
		if (!is_right(mlx_srct->rays.ray_angle))
			mlx_srct->hited.mapindex_x -= 1;
		if (check_wall_2(game, mlx_srct->hited.mapindex_x,
				mlx_srct->hited.mapindex_y) == 1)
		{
			mlx_srct->hited.wallhitx = mlx_srct->hited.tmpx;
			mlx_srct->hited.wallhity = mlx_srct->hited.tmpy;
			mlx_srct->hited.verx = mlx_srct->hited.tmpx;
			mlx_srct->hited.very = mlx_srct->hited.tmpy;
			mlx_srct->hited.verhit = true;
			mlx_srct->hited.offset = (int)mlx_srct->hited.wallhity % TILE_SIZE;
			break ;
		}
		else
		{
			mlx_srct->hited.tmpx += mlx_srct->hited.xstep;
			mlx_srct->hited.tmpy += mlx_srct->hited.ystep;
		}
	}
}

void	put_rays(t_mlx *mlx_srct, double x, double y, t_parce *game)
{
	int	bb;
	int	bc;

	mlx_srct->hited.verdistance = 999999999;
	mlx_srct->hited.hordistance = 999999999;
	mlx_srct->hited.hiitx = 0;
	mlx_srct->hited.hiity = 0;
	check_horizontal_intersections(mlx_srct, x * TILE_SIZE, y * TILE_SIZE,
			game);
	check_vertical_intersections(mlx_srct, x * TILE_SIZE, y * TILE_SIZE, game);
	nearest_point(mlx_srct, x, y, game);
}
