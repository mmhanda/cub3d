/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distancebtwpts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:40:41 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/25 17:06:07 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	distancebetween2_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ver_vs_hor(t_mlx *mlx_srct)
{
	if (mlx_srct->r.hordistance < mlx_srct->r.verdistance)
	{
		mlx_srct->r.hiitx = mlx_srct->r.horx;
		mlx_srct->r.hiity = mlx_srct->r.hory;
		mlx_srct->r.distance_to_wall = mlx_srct->r.hordistance;
	}
	if (mlx_srct->r.verdistance < mlx_srct->r.hordistance)
	{
		mlx_srct->r.hiitx = mlx_srct->r.verx;
		mlx_srct->r.hiity = mlx_srct->r.very;
		mlx_srct->r.distance_to_wall = mlx_srct->r.verdistance;
		mlx_srct->r.wasverticallasttime = true;
	}
}

void	nearest_point(t_mlx *mlx_srct, double x, double y)
{
	if (mlx_srct->r.horhit == true)
	{
		mlx_srct->r.hordistance = distancebetween2_points(x * TILE_SIZE, y
				* TILE_SIZE, mlx_srct->r.horx, mlx_srct->r.hory);
		mlx_srct->r.hordistance += 4;
	}
	if (mlx_srct->r.verhit == true)
	{
		mlx_srct->r.verdistance = distancebetween2_points(x * TILE_SIZE, y
				* TILE_SIZE, mlx_srct->r.verx, mlx_srct->r.very);
		mlx_srct->r.verdistance += 4;
	}
	ver_vs_hor(mlx_srct);
}

void	calculate_distances(t_mlx *mlx_srct)
{
	double	correct_distance;

	correct_distance = mlx_srct->r.distance_to_wall
		* cos(mlx_srct->rays.ray_angle - mlx_srct->plyr.rotate);
	mlx_srct->r.distbtwplr_and_plane = ((WIDTH / 2) / tan(FOV_ANGLE / 2.00));
	mlx_srct->r.wall_height = (int)((TILE_SIZE / correct_distance)
			* mlx_srct->r.distbtwplr_and_plane);
	mlx_srct->r.wallbottom = ((HEIGHT / 2) + (mlx_srct->r.wall_height)
			/ 2);
	mlx_srct->r.walltop = ((HEIGHT / 2) - mlx_srct->r.wall_height
			/ 2);
	if (mlx_srct->r.walltop < 0 || mlx_srct->r.walltop > HEIGHT)
		mlx_srct->r.walltop = 0;
	if (mlx_srct->r.wallbottom < 0 || mlx_srct->r.walltop > HEIGHT)
		mlx_srct->r.walltop = HEIGHT;
}

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
