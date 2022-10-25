/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distancebtwpts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:40:41 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/25 15:25:33 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	distancebetween2_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ver_vs_hor(t_mlx *mlx_srct, double x, double y, t_parce *game)
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

void	nearest_point(t_mlx *mlx_srct, double x, double y, t_parce *game)
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
	ver_vs_hor(mlx_srct, x, y, game);
}

void	calculate_distances(t_mlx *mlx_srct, t_parce *game)
{
	double	correct_distance;

	correct_distance = mlx_srct->r.distance_to_wall
		* cos(mlx_srct->rays.ray_angle - mlx_srct->plyr.rotate);
	mlx_srct->r.distbtwplr_and_plane = ((WIDTH / 2) / tan(FOV_ANGLE / 2.00));
	mlx_srct->r.projectedWallHeight = (int)((TILE_SIZE / correct_distance)
			* mlx_srct->r.distbtwplr_and_plane);
	mlx_srct->r.bottomOfWall = ((HEIGHT / 2) + (mlx_srct->r.projectedWallHeight)
			/ 2);
	mlx_srct->r.topOfWall = ((HEIGHT / 2) - mlx_srct->r.projectedWallHeight
			/ 2);
	if (mlx_srct->r.topOfWall < 0 || mlx_srct->r.topOfWall > HEIGHT)
		mlx_srct->r.topOfWall = 0;
	if (mlx_srct->r.bottomOfWall < 0 || mlx_srct->r.topOfWall > HEIGHT)
		mlx_srct->r.topOfWall = HEIGHT;
}
