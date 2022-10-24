/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:33:21 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/24 05:15:58 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	if (y >= HEIGHT || x >= WIDTH || x < 0 || y < 0)
		return ;
	char    *pixel;

	pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	paint_p_line(t_mlx *mlx_srct, double x, double y)
{
	x *= 15;
	y *= 15;
	double x2 = 0, y2 = 0, dx = 0, dy = 0, step = 0, xin = 0, yin = 0, xx = 0, yy = 0, k = 0;
	x2 = x + cos(mlx_srct->plyr.rotate) * 30;
	y2 = y + sin(mlx_srct->plyr.rotate) * 30;
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
		img_pix_put(&mlx_srct->mlx_m, round(xx), round(yy), 0x00FF00);
		k ++;
	}
}

void	paint_ground(t_mlx *mlx_srct, t_parce *game_map, double x, double y)
{
	mlx_srct->mini.j = 0;
	y *= 6;
	x *= 6;
	mlx_srct->mini.var_1 = mlx_srct->mini.p_y;
	mlx_srct->mini.var_2 = mlx_srct->mini.p_x;
	mlx_srct->mini.var_1 = y - mlx_srct->mini.var_1;
	mlx_srct->mini.var_2 = x - mlx_srct->mini.var_2;
	y = y - (mlx_srct->mini.var_1 * -1);
	x = x - (mlx_srct->mini.var_2 * -1);
	if (y > 12 * 15 || x > 16 * 15)
		return ;
	mlx_srct->mini.weigth = 10;
	mlx_srct->mini.high = 10;
	while (mlx_srct->mini.j < mlx_srct->mini.weigth)
	{
		mlx_srct->mini.i = 0;
		while (mlx_srct->mini.i < mlx_srct->mini.high)
		{
			img_pix_put(&mlx_srct->mlx_m, (x + mlx_srct->mini.i), (y + mlx_srct->mini.j), game_map->f_colo + 0x964B00);
			mlx_srct->mini.i ++;
		}
		mlx_srct->mini.j ++;
	}
}

void	paint_walls(t_mlx *mlx_srct, t_parce *game_map, double x, double y)
{
	mlx_srct->mini.j = 0;
	y *= 6;
	x *= 6;
	mlx_srct->mini.var_1 = mlx_srct->mini.p_y;
	mlx_srct->mini.var_2 = mlx_srct->mini.p_x;
	mlx_srct->mini.var_1 = y - mlx_srct->mini.var_1;
	mlx_srct->mini.var_2 = x - mlx_srct->mini.var_2;
	y = y - (mlx_srct->mini.var_1 * -1);
	x = x - (mlx_srct->mini.var_2 * -1);
	if (y > 12 * 15 || x > 16 * 15)
		return ;
	mlx_srct->mini.weigth = 10;
	mlx_srct->mini.high = 10;
	while (mlx_srct->mini.j < mlx_srct->mini.weigth)
	{
		mlx_srct->mini.i = 0;
		while (mlx_srct->mini.i < mlx_srct->mini.high)
		{
			img_pix_put(&mlx_srct->mlx_m, (x + mlx_srct->mini.i), (y + mlx_srct->mini.j), game_map->f_colo + 0x473223);
			mlx_srct->mini.i ++;
		}
		mlx_srct->mini.j ++;
	}
}

void	paint_player(t_mlx *mlx_srct, double x, double y)
{
	mlx_srct->mini.j = 0;
	y *= 12;
	x *= 12;
	mlx_srct->mini.weigth = 5;
	mlx_srct->mini.high = 5;
	mlx_srct->mini.var_1 = 83;
	mlx_srct->mini.var_2 = 125;
	mlx_srct->mini.var_1 = y - mlx_srct->mini.var_1;
	mlx_srct->mini.var_2 = x - mlx_srct->mini.var_2;
	mlx_srct->mini.p_y = mlx_srct->mini.var_1;
	mlx_srct->mini.p_x = mlx_srct->mini.var_2;
	y = y - mlx_srct->mini.var_1;
	x = x - mlx_srct->mini.var_2;
	if (y > 12 * 15 || x > 16 * 15)
		return ;
	while (mlx_srct->mini.j < mlx_srct->mini.weigth)
	{
		mlx_srct->mini.i = 0;
		while (mlx_srct->mini.i < mlx_srct->mini.high)
		{
			img_pix_put(&mlx_srct->mlx_m, (x + mlx_srct->mini.i), (y + mlx_srct->mini.j), 0xFFA500);
			mlx_srct->mini.i ++;
		}
		mlx_srct->mini.j ++;
	}
}
