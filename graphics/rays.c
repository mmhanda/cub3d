/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:56:48 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/16 20:43:55 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	make_stop_point(int x_y, t_mlx *mlx_srct, t_parce *game)
{
	int	y;
	int	x;
	int	wid;

	x = 0;
	y = 0;
	wid = WIDTH;
	// if (x_y == 1)
	// {
		while (wid < 510)
		{
			// if (check_wall(game, mlx_srct->plyr.x + x, mlx_srct->plyr.y + y) == 0)
			// 	return(y);
		printf ("%f\n", mlx_srct->plyr.y);
			check_wall(game, mlx_srct->plyr.x, mlx_srct->plyr.y);
			x ++;
			y ++;
			wid ++;
		}
	// }
	// if (x_y == 2)
	// {
	// 	while (i < 30)
	// 	{
	// 		if (check_wall(game, mlx_srct->plyr.x, mlx_srct->plyr.y + i) == 0)
	// 			return(i);
	// 		i ++;
	// 	}
	// }
	return (0);
}

void	put_rays(t_mlx *mlx_srct, double x, double y, t_parce *game)
{
	make_stop_point(1, mlx_srct, game);
	x *= TILE_SIZE;
	y *= TILE_SIZE;
	double x2 = 0, y2 = 0, dx = 0, dy = 0, step = 0, xin = 0, yin = 0, xx = 0, yy = 0, k = 0;
	x2 = x + cos(mlx_srct->rays.ray_angle)  * WIDTH;
	y2 = y + sin(mlx_srct->rays.ray_angle) * WIDTH;
	// x2 = x + cos(mlx_srct->rays.ray_angle)  * make_stop_point(1, mlx_srct, game);
	// y2 = y + sin(mlx_srct->rays.ray_angle) * make_stop_point(2, mlx_srct, game);
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
		put_rays(mlx_srct, mlx_srct->plyr.x, mlx_srct->plyr.y, game);
		mlx_srct->rays.ray_angle += FOV_ANGLE / NUM_RAYS;
		column_id ++;
	}
	// printf("%f\n", column_id);
}
