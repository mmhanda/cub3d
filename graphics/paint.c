/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:33:21 by mhanda            #+#    #+#             */
/*   Updated: 2022/09/26 04:40:50 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	if (y >= HEIGHT || x >= WIDTH)
		return ;
	char    *pixel;

	pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	paint_p_line(t_mlx *mlx_srct, double x, double y)
{
	x *= TILE_SIZE;
	y *= TILE_SIZE;
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

void	paint_player(t_mlx *mlx_srct, double x, double y)
{
	int	j;
	int	i;
	int	weigth;
	int	high;

	j = 0;
	y *= TILE_SIZE;
	x *= TILE_SIZE;
	weigth = 10;
	high = 10;
	while (j < weigth)
	{
		i = 0;
		while (i < high)
		{
			img_pix_put(&mlx_srct->mlx_m, (x + i), (y + j), 0xFFA500);
			i ++;
		}
		j ++;
	}
}

void	paint_ground(t_mlx *mlx_srct, t_parce *game_map, double x, double y)
{
	int	j;
	int	i;
	int	weigth;
	int	high;

	j = 0;
	y *= TILE_SIZE;
	x *= TILE_SIZE;
	weigth = TILE_SIZE;
	high = TILE_SIZE;
	while (j < weigth)
	{
		i = 0;
		while (i < high)
		{
			img_pix_put(&mlx_srct->mlx_m, (x + i), (y + j), game_map->c_colo + 0x964B00);
			i ++;
		}
		j ++;
	}
}

void	paint_walls(t_mlx *mlx_srct, t_parce *game_map, double x, double y)
{
	int	j;
	int	i;
	int	weigth;
	int	high;

	j = 0;
	y *= TILE_SIZE;
	x *= TILE_SIZE;
	weigth = TILE_SIZE;
	high = TILE_SIZE;
	while (j < weigth)
	{
		i = 0;
		while (i < high)
		{
			img_pix_put(&mlx_srct->mlx_m, (x + i), (y + j), game_map->f_colo + 0x473223);
			i ++;
		}
		j ++;
	}
}
