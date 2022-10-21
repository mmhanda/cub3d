/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distancebtwpts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:40:41 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/21 18:27:17 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	distancebetween2_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ver_vs_hor(t_mlx *mlx_srct, double x, double y, t_parce *game)
{
	if (mlx_srct->hited.hordistance < mlx_srct->hited.verdistance)
	{
		mlx_srct->hited.hiitx = mlx_srct->hited.horx;
		mlx_srct->hited.hiity = mlx_srct->hited.hory;
		mlx_srct->hited.distance_to_wall = mlx_srct->hited.hordistance;
	}
	 	if ( mlx_srct->hited.verdistance < mlx_srct->hited.hordistance )

	{
		mlx_srct->hited.hiitx = mlx_srct->hited.verx;
		mlx_srct->hited.hiity = mlx_srct->hited.very;
		mlx_srct->hited.distance_to_wall = mlx_srct->hited.verdistance;
		mlx_srct->hited.wasverticallasttime = true;
	}
}

void	nearest_point(t_mlx *mlx_srct, double x, double y, t_parce *game)
{
	
	if (mlx_srct->hited.horhit == true)
	{
		mlx_srct->hited.hordistance = distancebetween2_points(x * 32, y * 32,
				mlx_srct->hited.horx, mlx_srct->hited.hory);
	}
	if (mlx_srct->hited.verhit == true)
	{
		mlx_srct->hited.verdistance = distancebetween2_points(x * 32, y * 32,
				mlx_srct->hited.verx, mlx_srct->hited.very);
	}
	ver_vs_hor(mlx_srct, x, y, game);
}

