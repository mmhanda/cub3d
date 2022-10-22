/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceilling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:55:12 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/22 10:20:58 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_floor(t_parce *game_map)
{
	int	y2;
	int	x2;
	int	color;

	y2 = 0;
	x2 = 0;
	printf( "| %d |    \n",  game_map->f_colo);
	while (y2 < 720 / 2)
	{
		x2 = 0;
		while (x2 < 1280)
		{
			img_pix_put(&game_map->mlx_srct.mlx_m, x2, y2, game_map->f_colo);
			x2++;
		}
		y2++;
	}
}

void	draw_ceilling(t_parce *game_map)
{
	int y2;
	int x2;
	y2 = HEIGHT / 2;
	x2 = 0;
	while (y2 < 720)
	{
		x2 = 0;
		while (x2 < 1280)
		{
			img_pix_put(&game_map->mlx_srct.mlx_m, x2, y2,  game_map->c_colo);

			x2++;
		}
		y2++;
	}
}