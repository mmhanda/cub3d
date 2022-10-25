/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:33:21 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 17:10:34 by mhanda           ###   ########.fr       */
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

int	check_wall_2(t_parce *game, double new_x, double new_y)
{
	int	map_index_x;
	int	map_index_y;

	map_index_x = floor(new_x);
	map_index_y = floor(new_y);
	if (new_x < 0 || new_y < 0)
		return (0);
	if (game->parced_map[map_index_y][map_index_x] == '1')
		return (1);
	return (0);
}
