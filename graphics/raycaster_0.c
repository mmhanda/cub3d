/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:23:43 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/18 15:10:58 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
// check horizontal and vertical



void  check_horizontal_intersections()
{
	/* First intersection A */
	//get Ay coordinate  =  player y / 32 * 32
	// get Ax coordinate	 = player x  + ((Player y  - Ay) / tan())
	//addjecent  = (Py - Ay) / tan()
	/* Next intersection B : i should know  (dist_x_step) and (dist_y_step)*/
	//dist_x_step = dist_y_step / tan()
	/* dist_y_step = 32 because we are moving with the size of the tile up*/
	// convert  intersections Ax and Ay into map index
	//then check
	// if(intersections hits a wall)
	/* 
	//store horizontal distance 
	
	*/
//else check next horizontal intersection 
}
void  check_vertical_intersections()
{
	
}

void	put_rays(t_mlx *mlx_srct, double x, double y, t_parce *game)
{


	// double dist_y_step;
	// double dist_x_step;
	//long ax;
	// long ay;
	x *= TILE_SIZE;
	y *= TILE_SIZE;
	double x2 = 0, y2 = 0, dx = 0, dy = 0, step = 0, xin = 0, yin = 0, xx = 0, yy = 0, k = 0;
	x2 = x + cos(mlx_srct->rays.ray_angle)  * WIDTH;
	y2 = y + sin(mlx_srct->rays.ray_angle) * WIDTH;
    printf("x2 = %f   y2  = %f  \n", x / 32, y/32); // player x and y position 
	
	// x2 = x + cos(mlx_srct->rays.ray_angle)  * make_stop_point(1, mlx_srct, game);
	// y2 = y + sin(mlx_srct->rays.ray_angle) * make_stop_point(2, mlx_srct, game);
	game = NULL;
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
