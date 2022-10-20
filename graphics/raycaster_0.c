/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:23:43 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/20 11:09:23 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include <stdbool.h>
float	distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

static int	hit = 0;

int	check_wall_2(t_parce *game, double new_x, double new_y)
{
	int	map_index_x;
	int	map_index_y;

	map_index_x = floor(new_x);
	map_index_y = floor(new_y);
	if (map_index_x * TILE_SIZE > WIDTH || map_index_y * TILE_SIZE > HEIGHT
		|| new_x < 0 || new_y < 0 || new_x > WIDTH || new_y > WIDTH
		|| new_x > WIDTH || new_y > WIDTH)
		return (0);
	if (game->parced_map[map_index_y][map_index_x] == '1')
		return (1);
	return (0);
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

bool	is_right(double angle_in_radian)
{
	if (angle_in_radian < (M_PI / 2) || angle_in_radian > (1.5 * M_PI))
		return (true);
	return (false);
}
bool	is_down(double angle_in_radian)
{
	if (angle_in_radian > 0 && angle_in_radian < M_PI)
		return (true);
	return (false);
}

void	check_horizontal_intersections(t_mlx *mlx_srct, double x, double y,
		t_parce *game)
{
	double	tmpx;
	double	tmpy;
	int		mapindex_x;
	int		mapindex_y;

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
		mlx_srct->hited.ystep = -TILE_SIZE;
	}
	mlx_srct->hited.xstep = TILE_SIZE / tan(mlx_srct->rays.ray_angle);
	if (is_right(mlx_srct->rays.ray_angle) && mlx_srct->hited.xstep < 0)
	{
		mlx_srct->hited.xstep = -TILE_SIZE;
	}
	else if (!is_right(mlx_srct->rays.ray_angle) && mlx_srct->hited.xstep > 0)
	{
		mlx_srct->hited.xstep = -TILE_SIZE;
	}
	tmpx = mlx_srct->hited.xintercept;
	tmpy = mlx_srct->hited.yintercept;
	if (!is_down(mlx_srct->rays.ray_angle))
		tmpy -= 1;
	printf(" tmpx %f = tmpy %f\n", tmpx / 32, tmpy / 32);
	while (tmpx >= 0 && tmpx <= (15 * 32) && tmpy >= 0 && tmpy <= (11 * 32))
	{
		mapindex_x = tmpx / TILE_SIZE;
		mapindex_y = tmpy / TILE_SIZE;
		if (check_wall_2(game, mapindex_x, mapindex_y) == 1)
		{
			hit = 1;
			mlx_srct->hited.wallhitx = tmpx;
			mlx_srct->hited.wallhity = tmpy;
			mlx_srct->hited.horx = tmpx;
			mlx_srct->hited.hory = tmpy;
			break ;
		}
		else
		{
			tmpx += mlx_srct->hited.xstep;
			tmpy += mlx_srct->hited.ystep;
		}
	}
}

void	check_vertical_intersections(t_mlx *mlx_srct, double x, double y,
		t_parce *game)
{
	double	tmpx;
	double	tmpy;
	int		mapindex_x;
	int		mapindex_y;

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
	else if (is_down(mlx_srct->rays.ray_angle) && mlx_srct->hited.ystep < 0)
	{
		mlx_srct->hited.ystep *= -1;
	}
	tmpx = mlx_srct->hited.xintercept;
	tmpy = mlx_srct->hited.yintercept;
	if (!is_right(mlx_srct->rays.ray_angle))
	{
		tmpx -= 1;
	}
	while (tmpx >= 0 && tmpx <= (15 * 32) && tmpy >= 0 && tmpy <= (11 * 32))
	{
		mapindex_x = tmpx / TILE_SIZE;
		mapindex_y = tmpy / TILE_SIZE;
		if (check_wall_2(game, mapindex_x, mapindex_y) == 1)
		{
			hit = 1;
			mlx_srct->hited.wallhitx = tmpx;
			mlx_srct->hited.wallhity = tmpy;
			mlx_srct->hited.horx = tmpx;
			mlx_srct->hited.hory = tmpy;
			break ;
		}
		else
		{
			tmpx += mlx_srct->hited.xstep;
			tmpy += mlx_srct->hited.ystep;
		}
	}
}

void	put_rays(t_mlx *mlx_srct, double x, double y, t_parce *game)
{
	int	bb;
	int	bc;

	mlx_srct->hited.hit = 0;
	mlx_srct->hited.horx = WIDTH - (x * 32);
	mlx_srct->hited.hory = WIDTH - (y * 32);
	mlx_srct->hited.verx = WIDTH - (x * 32);
	mlx_srct->hited.very = WIDTH - (y * 32);
	hit = 0;
	check_horizontal_intersections(mlx_srct, x * 32, y * 32, game);
	check_vertical_intersections(mlx_srct, x * 32, y * 32, game);
	bb = distanceBetweenPoints(x * 32, y * 32, mlx_srct->hited.horx,
			mlx_srct->hited.hory);
	bc = distanceBetweenPoints(x * 32, y * 32, mlx_srct->hited.verx,
			mlx_srct->hited.verx);
	// if (bb < bc)
	// {
		dda(x * 32, y * 32, mlx_srct->hited.horx, mlx_srct->hited.hory,
				mlx_srct);
	// }
	// if (bc < bb)
	// {
		dda(x * 32, y * 32, mlx_srct->hited.verx, mlx_srct->hited.very,
				mlx_srct);
	// }
}
