/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:34:48 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 14:57:19 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


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

void make_them_false(t_mlx *mlx_srct)
{
    mlx_srct->hited.horhit = false;
		mlx_srct->hited.verhit = false;
		mlx_srct->hited.wasverticallasttime = false;
		mlx_srct->hited.hiitx = 0;
		mlx_srct->hited.hiity = 0;
		mlx_srct->hited.distance_to_wall = 0;
        	mlx_srct->hited.distbtwplr_and_plane = 0;
                mlx_srct->hited.ofssety = 0;
                  mlx_srct->hited.y_wall = 0 ;

}