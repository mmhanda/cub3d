/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:56:48 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/22 10:44:16 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_them(t_mlx *mlx_srct)
{
	mlx_srct->hited.nextHorzTouchX = 0;
	mlx_srct->hited.nextHorzTouchY = 0;
	mlx_srct->hited.yintercept = 0;
	mlx_srct->hited.xintercept = 0;
	mlx_srct->hited.wallhitx = 0;
	mlx_srct->hited.wallhity = 0;
	mlx_srct->hited.x_map_grid = 0;
	mlx_srct->hited.y_map_grid = 0;
	mlx_srct->hited.horx = 0;
	mlx_srct->hited.hory = 0;
	mlx_srct->hited.verx = 0;
	mlx_srct->hited.very = 0;
	mlx_srct->hited.ystep = 0;
	mlx_srct->hited.xstep = 0;
	mlx_srct->hited.bottomOfWall = 0;
	mlx_srct->hited.topOfWall = 0;
}

/*
                      
						   Actual Slice Height
Projected Slice Height= --------------------- * Distance to Projection Plane
                        Distance to the Slice  

						//bottomOfWall  = plane center  + projected Wall Height
//topOfWall  = plane center   - projected Wall Height
						// printf("mlx_srct->hited.distance_to_wall fasle= 
								%f\n",mlx_srct->hited.distance_to_wall);
						
// printf("mlx_srct->hited.distance_to_wall correct   = 
		%f\n",mlx_srct->hited.distance_to_wall);


// printf(" mlx_srct->hited.projectedWallHeight is %f\n",
		mlx_srct->hited.projectedWallHeight);
// printf(" mlx_srct->hited.distbtwplr_and_plane is %f\n",
		mlx_srct->hited.distbtwplr_and_plane );
// printf("mlx_srct->hited.bottomOfWall t is
		%d\n",mlx_srct->hited.bottomOfWall );
// printf(" mlx_srct->hited.topOfWall %d\n", mlx_srct->hited.topOfWall  );
*/
void	calculate_distances(t_mlx *mlx_srct, t_parce *game)
{
	double	correct_distance;

	correct_distance = mlx_srct->hited.distance_to_wall * cos(mlx_srct->rays.ray_angle - mlx_srct->plyr.rotate) * 0.5;
	mlx_srct->hited.distance_to_wall = correct_distance;
	mlx_srct->hited.distbtwplr_and_plane = (1080 / 2) / tan(FOV_ANGLE / 2);
	mlx_srct->hited.projectedWallHeight = ((TILE_SIZE / mlx_srct->hited.distance_to_wall) * mlx_srct->hited.distbtwplr_and_plane) * 0.5;
	mlx_srct->hited.bottomOfWall = ((1080 / 2) + (mlx_srct->hited.projectedWallHeight / 2));
	mlx_srct->hited.topOfWall = ((1080 / 2)	- mlx_srct->hited.projectedWallHeight / 2) ;




	
	if (mlx_srct->hited.topOfWall < 0 || mlx_srct->hited.topOfWall > HEIGHT)
		mlx_srct->hited.topOfWall = 0;
	if (mlx_srct->hited.bottomOfWall < 0 || mlx_srct->hited.topOfWall > HEIGHT)
		mlx_srct->hited.topOfWall = HEIGHT;
}
void	paint_rays(t_mlx *mlx_srct, t_parce *game)
{
	double	column_id;
	int		color;

	init_them(mlx_srct);
	column_id = 0;
	mlx_srct->rays.ray_angle = mlx_srct->plyr.rotate - (FOV_ANGLE / 2);
	mlx_srct->rays.ray_angle = fmod(mlx_srct->rays.ray_angle, 2 * M_PI);
	if (mlx_srct->rays.ray_angle < 0)
		mlx_srct->rays.ray_angle += (2 * M_PI);
	while (column_id < 1080)
	{
		mlx_srct->hited.horhit = false;
		mlx_srct->hited.verhit = false;
		color = 0xCA8927;
		mlx_srct->hited.wasverticallasttime = false;
		mlx_srct->rays.ray_angle += FOV_ANGLE / 1080;
		mlx_srct->rays.ray_angle = fmod(mlx_srct->rays.ray_angle, 2 * M_PI);
		if (mlx_srct->rays.ray_angle < 0)
			mlx_srct->rays.ray_angle += (2 * M_PI);
		mlx_srct->hited.hiitx = 0;
		mlx_srct->hited.hiity = 0;
		mlx_srct->hited.distance_to_wall = 0;
		put_rays(mlx_srct, mlx_srct->plyr.x, mlx_srct->plyr.y, game);
		if (mlx_srct->hited.wasverticallasttime == true)
			color = 0x3916E6;
		mlx_srct->hited.distbtwplr_and_plane = 0;
		calculate_distances(mlx_srct, game);
		draw_it(column_id, mlx_srct->hited.topOfWall, 1,
				(mlx_srct->hited.bottomOfWall - mlx_srct->hited.topOfWall) + 1,
				color, mlx_srct);
		column_id++;
	}
}
