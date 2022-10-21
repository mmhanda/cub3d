/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:23:43 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/21 08:59:04 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include <stdbool.h>

bool	horhit = false;
bool	verhit = false;

void	draw_it(int x, int y, int width, int height, int color, t_mlx *mlx_srct)
{
	int	ff;

	ff = y;
	while (ff < height)
	{
		// mlx_pixel_put(mlx_ptr, mlx_win, x, ff, color);
		// img_pix_put(&mlx_srct->mlx_m, x, ff, 0xFFFFFF);
		mlx_pixel_put(mlx_srct->hited.mlx_ptr, mlx_srct->hited.mlx_win, x, ff,
				color);
		ff++;
	}
}

void	dda(int a, int b, int c, int d, t_mlx *mlx_srct)
{
	int		dx;
	int		dy;
	int		steps;
	float	Xinc;
	float	Yinc;
	float	X;
	float	Y;

	dx = c - a;
	dy = d - b;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	Xinc = dx / (float)steps;
	Yinc = dy / (float)steps;
	X = a;
	Y = b;
	for (int i = 0; i <= steps; i++)
	{
		img_pix_put(&mlx_srct->mlx_m, round(X), round(Y), 0xF02B79);
		X += Xinc;
		Y += Yinc;
	}
}

void	check_horizontal_intersections(t_mlx *mlx_srct, double x, double y,
		t_parce *game)
{
	y_x_horizontal(mlx_srct, x, y, game);
	mlx_srct->hited.tmpx = mlx_srct->hited.xintercept;
	mlx_srct->hited.tmpy = mlx_srct->hited.yintercept;
	while (mlx_srct->hited.tmpx >= 0 && mlx_srct->hited.tmpx <= WIDTH
		&& mlx_srct->hited.tmpy >= 0 && mlx_srct->hited.tmpy <= HEIGHT)
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
			horhit = true;
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
	while (mlx_srct->hited.tmpx >= 0 && mlx_srct->hited.tmpx <= WIDTH
		&& mlx_srct->hited.tmpy >= 0 && mlx_srct->hited.tmpy <= HEIGHT)
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
			verhit = true;
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
	int		bb;
	int		bc;
	double	hordistance;
	double	verdistance;
	double	hiitx;
	double	hiity;
	double	distance;

	horhit = false;
	verhit = false;
	check_horizontal_intersections(mlx_srct, x * 32, y * 32, game);
	mlx_srct->rays.ray_angle = fmod(mlx_srct->rays.ray_angle, 2 * M_PI);
	if (mlx_srct->rays.ray_angle < 0)
		mlx_srct->rays.ray_angle += (2 * M_PI);
	check_vertical_intersections(mlx_srct, x * 32, y * 32, game);
	hordistance = 999999999;
	verdistance = 999999999;
	hiitx = 0;
	hiity = 0;
	distance = 0;
	if (horhit == true)
	{
		hordistance = distancebetween2_points(x * 32, x * 32,
				mlx_srct->hited.horx, mlx_srct->hited.hory);
	}
	if (verhit == true)
	{
		verdistance = distancebetween2_points(x * 32, x * 32,
				mlx_srct->hited.verx, mlx_srct->hited.very);
	}
	if (hordistance < verdistance)
	{
		hiitx = mlx_srct->hited.horx;
		hiity = mlx_srct->hited.hory;
		distance = hordistance;
		mlx_srct->hited.distance_to_wall = hordistance;
	}
	else
	{
		hiitx = mlx_srct->hited.verx;
		hiity = mlx_srct->hited.very;
		distance = verdistance;
		mlx_srct->hited.distance_to_wall = verdistance;
		mlx_srct->hited.wasverticallasttime = true;
	}
	dda(x * 32, y * 32, hiitx, hiity, mlx_srct);
	//init
	mlx_srct->hited.projectedWallHeight = 0;
	mlx_srct->hited.bottomOfWall = 0;
	//project it  " cub3d"
	// mlx_srct->hited.projectedWallHeight = (32 / distance) * 55;
	mlx_srct->hited.projectedWallHeight = distance;
	// printf("distance is  = %f   \n", distance);
	mlx_srct->hited.bottomOfWall = (WIDTH / 2)
		+ (mlx_srct->hited.projectedWallHeight * 0.5);
	mlx_srct->hited.topOfWall = (WIDTH / 2)
		- (mlx_srct->hited.projectedWallHeight * 0.5);
	if (mlx_srct->hited.topOfWall < 0)
		mlx_srct->hited.topOfWall = 0;
	if (mlx_srct->hited.bottomOfWall >= HEIGHT)
		mlx_srct->hited.bottomOfWall = HEIGHT - 1;
}
