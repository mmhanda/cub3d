/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:23:43 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/25 16:01:19 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	wall_found_hor(t_mlx *mlx_srct)
{
	mlx_srct->r.wallhitx = mlx_srct->r.tmpx;
	mlx_srct->r.wallhity = mlx_srct->r.tmpy;
	mlx_srct->r.horx = mlx_srct->r.tmpx;
	mlx_srct->r.hory = mlx_srct->r.tmpy;
	mlx_srct->r.horhit = true;
	mlx_srct->r.offset = (int)mlx_srct->r.wallhitx % TILE_SIZE;
}

void	check_horizontal_intersections(t_mlx *mlx_srct, double x, double y,
		t_parce *game)
{
	y_x_horizontal(mlx_srct, x, y);
	mlx_srct->r.tmpx = mlx_srct->r.xintercept;
	mlx_srct->r.tmpy = mlx_srct->r.yintercept;
	while (mlx_srct->r.tmpx >= 0
		&& mlx_srct->r.tmpx <= ((mlx_srct->longest_line - 1) * TILE_SIZE)
		&& mlx_srct->r.tmpy >= 0
		&& mlx_srct->r.tmpy <= ((mlx_srct->tab_len - 1) * TILE_SIZE))
	{
		mlx_srct->r.mapindex_x = mlx_srct->r.tmpx / TILE_SIZE;
		mlx_srct->r.mapindex_y = mlx_srct->r.tmpy / TILE_SIZE;
		if (!is_down(mlx_srct->rays.ray_angle))
			mlx_srct->r.mapindex_y -= 1;
		if (check_wall_2(game, mlx_srct->r.mapindex_x,
				mlx_srct->r.mapindex_y) == 1)
		{
			wall_found_hor(mlx_srct);
			break ;
		}
		else
		{
			mlx_srct->r.tmpx += mlx_srct->r.xstep;
			mlx_srct->r.tmpy += mlx_srct->r.ystep;
		}
	}
}

void	wall_found_ver(t_mlx *mlx_srct)
{
	mlx_srct->r.wallhitx = mlx_srct->r.tmpx;
	mlx_srct->r.wallhity = mlx_srct->r.tmpy;
	mlx_srct->r.verx = mlx_srct->r.tmpx;
	mlx_srct->r.very = mlx_srct->r.tmpy;
	mlx_srct->r.verhit = true;
	mlx_srct->r.offset = (int)mlx_srct->r.wallhity % TILE_SIZE;
}

void	check_vertical_intersections(t_mlx *mlx_srct, double x, double y,
		t_parce *game)
{
	y_x_vertical(mlx_srct, x, y);
	while (mlx_srct->r.tmpx >= 0
		&& mlx_srct->r.tmpx <= ((mlx_srct->longest_line - 1) * TILE_SIZE)
		&& mlx_srct->r.tmpy >= 0
		&& mlx_srct->r.tmpy <= ((mlx_srct->tab_len - 1) * TILE_SIZE))
	{
		mlx_srct->r.mapindex_x = mlx_srct->r.tmpx / TILE_SIZE;
		mlx_srct->r.mapindex_y = mlx_srct->r.tmpy / TILE_SIZE;
		if (!is_right(mlx_srct->rays.ray_angle))
			mlx_srct->r.mapindex_x -= 1;
		if (check_wall_2(game, mlx_srct->r.mapindex_x,
				mlx_srct->r.mapindex_y) == 1)
		{
			wall_found_ver(mlx_srct);
			break ;
		}
		else
		{
			mlx_srct->r.tmpx += mlx_srct->r.xstep;
			mlx_srct->r.tmpy += mlx_srct->r.ystep;
		}
	}
}

void	put_rays(t_mlx *mlx_srct, double x, double y, t_parce *game)
{
	mlx_srct->r.verdistance = 999999999;
	mlx_srct->r.hordistance = 999999999;
	mlx_srct->r.hiitx = 0;
	mlx_srct->r.hiity = 0;
	check_horizontal_intersections(mlx_srct, x * TILE_SIZE, y * TILE_SIZE,
		game);
	check_vertical_intersections(mlx_srct, x * TILE_SIZE, y * TILE_SIZE, game);
	nearest_point(mlx_srct, x, y);
}
