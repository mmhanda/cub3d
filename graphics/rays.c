/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:56:48 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/21 11:24:49 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

#include "../cub.h"
void	draw_floor(t_mlx *mlx_srct)
{
	int	y2;
	int	x2;
	int	color;

	y2 = 0;
	x2 = 0;
	color = 0xFFFFFF;
	while (y2 < 720 / 2)
	{
		x2 = 0;
		while (x2 < 1280)
		{
			mlx_pixel_put(mlx_srct->hited.mlx_ptr, mlx_srct->hited.mlx_win, x2,
					y2, color);
			x2++;
		}
		y2++;
	}
}
void	draw_ceilling(t_mlx *mlx_srct)
{
	int	y2;
	int	x2;
	int	color;

	y2 = 0;
	x2 = 0;
	color = 0xFFFFFF;
	color = 0x796554;
	x2 = 0;
	y2 = 720 / 2;
	while (y2 < 720)
	{
		x2 = 0;
		while (x2 < 1280)
		{
			mlx_pixel_put(mlx_srct->hited.mlx_ptr, mlx_srct->hited.mlx_win, x2,
					y2, color);
			x2++;
		}
		y2++;
	}
}
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
	while (column_id < WIDTH)
	{
		color = 0xFFFFFF;
		mlx_srct->hited.wasverticallasttime = false;
		mlx_srct->rays.ray_angle += FOV_ANGLE / WIDTH;
		mlx_srct->rays.ray_angle = fmod(mlx_srct->rays.ray_angle, 2 * M_PI);
		if (mlx_srct->rays.ray_angle < 0)
			mlx_srct->rays.ray_angle += (2 * M_PI);
		put_rays(mlx_srct, mlx_srct->plyr.x, mlx_srct->plyr.y, game);
		if (mlx_srct->hited.wasverticallasttime == true)
			color = 0xF5643F;
		else
			color = 0xF5871F;
// draw_it(column_id, mlx_srct->hited.topOfWall, 1,(	mlx_srct->hited.bottomOfWall - mlx_srct->hited.topOfWall)+ 1,color,  mlx_srct);
		column_id++;
	}
}

