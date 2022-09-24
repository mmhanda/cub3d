/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:56:48 by mhanda            #+#    #+#             */
/*   Updated: 2022/09/24 05:29:51 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	put_rays(t_mlx *mlx_srct, double x, double y)
{
	x *= TILE_SIZE;
	y *= TILE_SIZE;
	double x2 = 0, y2 = 0, dx = 0, dy = 0, step = 0, xin = 0, yin = 0, xx = 0, yy = 0, k = 0;
	x2 = x + cos(mlx_srct->rays.ray_angle) * 30;
	y2 = y + sin(mlx_srct->rays.ray_angle) * 30;
	dx = x2 - x;
	dy = y2 - y;
	if (dx >= dy)
		step = fabs(dx);
	else
		step = fabs(dy);
	xin = dx / step;
	yin = dy / step;
	xx = x + 0.5;
	yy = y + 0.5;
	while (k <= step)
	{
		xx += xin;
		yy += yin;
		img_pix_put(&mlx_srct->mlx_m, round(xx), round(yy), 0xF02B79);
		k ++;
	}
}

void	paint_rays(t_mlx *mlx_srct, t_parce *game)
{
	double	column_id;
	// double	ray_angle;
	game = NULL;

	column_id = 0;
	mlx_srct->rays.ray_angle = mlx_srct->plyr.rotate - (FOV_ANGLE / 2);
	while (column_id < NUM_RAYS)
	{
		put_rays(mlx_srct, mlx_srct->plyr.x, mlx_srct->plyr.y);
		mlx_srct->rays.ray_angle += FOV_ANGLE / NUM_RAYS;
		column_id ++;
	}
	printf("%f\n", column_id);
}
