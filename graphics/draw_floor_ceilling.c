/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceilling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:55:12 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/22 08:56:58 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_floor(t_mlx *mlx_srct)
{
	int	y2;
	int	x2;
	int	color;

	y2 = 0;
	x2 = 0;
	color = 0x16EEC7;
	while (y2 < 720 / 2)
	{
		x2 = 0;
		while (x2 < 1280)
		{
			img_pix_put(&mlx_srct->mlx_m, x2, y2, color);
			x2++;
		}
		y2++;
	}
}

void	draw_ceilling(t_mlx *mlx_srct)
{
	int y2;
	int x2;
	y2 = HEIGHT / 2;
	x2 = 0;
	int color = 0xCD7D0E;
	while (y2 < 720)
	{
		x2 = 0;
		while (x2 < 1280)
		{
			img_pix_put(&mlx_srct->mlx_m, x2, y2, color);

			x2++;
		}
		y2++;
	}
}