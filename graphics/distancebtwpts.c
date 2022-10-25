/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distancebtwpts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:40:41 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/25 15:14:00 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	distancebetween2_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ver_vs_hor(t_mlx *mlx_srct, double x, double y, t_parce *game)
{
	if (mlx_srct->hited.hordistance < mlx_srct->hited.verdistance)
	{
		mlx_srct->hited.hiitx = mlx_srct->hited.horx;
		mlx_srct->hited.hiity = mlx_srct->hited.hory;
		mlx_srct->hited.distance_to_wall = mlx_srct->hited.hordistance;
	}
	if (mlx_srct->hited.verdistance < mlx_srct->hited.hordistance)
	{
		mlx_srct->hited.hiitx = mlx_srct->hited.verx;
		mlx_srct->hited.hiity = mlx_srct->hited.very;
		mlx_srct->hited.distance_to_wall = mlx_srct->hited.verdistance;
		mlx_srct->hited.wasverticallasttime = true;
	}
}

void	nearest_point(t_mlx *mlx_srct, double x, double y, t_parce *game)
{
	if (mlx_srct->hited.horhit == true)
	{
		mlx_srct->hited.hordistance = distancebetween2_points(x * TILE_SIZE, y
				* TILE_SIZE, mlx_srct->hited.horx, mlx_srct->hited.hory);
		mlx_srct->hited.hordistance += 4;
	}
	if (mlx_srct->hited.verhit == true)
	{
		mlx_srct->hited.verdistance = distancebetween2_points(x * TILE_SIZE, y
				* TILE_SIZE, mlx_srct->hited.verx, mlx_srct->hited.very);
		mlx_srct->hited.verdistance += 4;
	}
	ver_vs_hor(mlx_srct, x, y, game);
}
void	calculate_distances(t_mlx *mlx_srct, t_parce *game)
{
	double	correct_distance;

	correct_distance = mlx_srct->hited.distance_to_wall
		* cos(mlx_srct->rays.ray_angle - mlx_srct->plyr.rotate);
	mlx_srct->hited.distbtwplr_and_plane = ((WIDTH / 2) / tan(FOV_ANGLE
				/ 2.00));
	mlx_srct->hited.projectedWallHeight = (int)((TILE_SIZE / correct_distance)
			* mlx_srct->hited.distbtwplr_and_plane);
	mlx_srct->hited.bottomOfWall = ((HEIGHT / 2)
			+ (mlx_srct->hited.projectedWallHeight) / 2);
	mlx_srct->hited.topOfWall = ((HEIGHT / 2)
			- mlx_srct->hited.projectedWallHeight / 2);
	if (mlx_srct->hited.topOfWall < 0 || mlx_srct->hited.topOfWall > HEIGHT)
		mlx_srct->hited.topOfWall = 0;
	if (mlx_srct->hited.bottomOfWall < 0 || mlx_srct->hited.topOfWall > HEIGHT)
		mlx_srct->hited.topOfWall = HEIGHT;
}
