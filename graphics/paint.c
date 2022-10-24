/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:33:21 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/24 18:22:36 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (y >= HEIGHT || x >= WIDTH || x < 0 || y < 0)
		return ;
	pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
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
	mlx_srct->hited.bottomOfWall = 0;
	mlx_srct->hited.topOfWall = 0;
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
			img_pix_put(&mlx_srct->mlx_m, (x + mlx_srct->mini.i),
				(y + mlx_srct->mini.j), game_map->f_colo + 0x964B00);
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
			img_pix_put(&mlx_srct->mlx_m, (x + mlx_srct->mini.i),
				(y + mlx_srct->mini.j), game_map->f_colo + 0x473223);
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
		while (mlx_srct->mini.i ++ < mlx_srct->mini.high)
		{
			img_pix_put(&mlx_srct->mlx_m, (x + mlx_srct->mini.i),
				(y + mlx_srct->mini.j), 0xFFA500);
		}
		mlx_srct->mini.j ++;
	}
}
