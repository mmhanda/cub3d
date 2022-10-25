/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:23:15 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/25 23:39:34 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_b.h"

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

void	draw_ceilling(t_parce *game_map)
{
	int	y2;
	int	x2;

	y2 = 0;
	x2 = 0;
	while (y2 < 720 / 2)
	{
		x2 = 0;
		while (x2 < 1280)
		{
			img_pix_put(&game_map->mlx_srct.mlx_m, x2, y2, game_map->c_colo);
			x2++;
		}
		y2++;
	}
}

void	draw_floor(t_parce *game_map)
{
	int	y2;
	int	x2;

	y2 = HEIGHT / 2;
	x2 = 0;
	while (y2 < 720)
	{
		x2 = 0;
		while (x2 < 1280)
		{
			img_pix_put(&game_map->mlx_srct.mlx_m, x2, y2, game_map->f_colo);
			x2++;
		}
		y2++;
	}
}

void	init_them(t_mlx *mlx_srct)
{
	mlx_srct->r.nexthorztouchx = 0;
	mlx_srct->r.nexthorztouchy = 0;
	mlx_srct->r.yintercept = 0;
	mlx_srct->r.xintercept = 0;
	mlx_srct->r.wallhitx = 0;
	mlx_srct->r.wallhity = 0;
	mlx_srct->r.x_map_grid = 0;
	mlx_srct->r.y_map_grid = 0;
	mlx_srct->r.horx = 0;
	mlx_srct->r.hory = 0;
	mlx_srct->r.verx = 0;
	mlx_srct->r.very = 0;
	mlx_srct->r.ystep = 0;
	mlx_srct->r.xstep = 0;
	mlx_srct->r.wallbottom = 0;
	mlx_srct->r.walltop = 0;
}

void	make_them_false(t_parce *game)
{
	game->mlx_srct.r.horhit = false;
	game->mlx_srct.r.verhit = false;
	game->mlx_srct.r.wasverticallasttime = false;
	game->mlx_srct.r.hiitx = 0;
	game->mlx_srct.r.hiity = 0;
	game->mlx_srct.r.distance_to_wall = 0;
	game->mlx_srct.r.distbtwplr_and_plane = 0;
	game->mlx_srct.r.ofssety = 0;
	game->mlx_srct.r.y_wall = 0;
	put_rays(&game->mlx_srct, game->mlx_srct.plyr.x, game->mlx_srct.plyr.y,
		game);
	calculate_distances(&game->mlx_srct);
}
