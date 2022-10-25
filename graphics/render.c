/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:34:48 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 15:25:53 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_them(t_mlx *mlx_srct)
{
	mlx_srct->r.nextHorzTouchX = 0;
	mlx_srct->r.nextHorzTouchY = 0;
	mlx_srct->r.yintercept = 0;
	mlx_srct->r.xintercept = 0;
	mlx_srct->r.wallhitx = 0;
	mlx_srct->r.wallhity = 0;
	mlx_srct->r.x_map_grid = 0;
	mlx_srct->r.y_map_grid = 0;
	mlx_srct->r.horx = 0;
	mlx_srct->r.hory = 0;
	mlx_srct->r.verx = 0;
	mlx_srct->r.very = 0;
	mlx_srct->r.ystep = 0;
	mlx_srct->r.xstep = 0;
	mlx_srct->r.bottomOfWall = 0;
	mlx_srct->r.topOfWall = 0;
}

void	make_them_false(t_parce *game)
{
	game->mlx_srct.r.horhit = false;
	game->mlx_srct.r.verhit = false;
	game->mlx_srct.r.wasverticallasttime = false;
	game->mlx_srct.r.hiitx = 0;
	game->mlx_srct.r.hiity = 0;
	game->mlx_srct.r.distance_to_wall = 0;
	game->mlx_srct.r.distbtwplr_and_plane = 0;
	game->mlx_srct.r.ofssety = 0;
	game->mlx_srct.r.y_wall = 0;
	put_rays(&game->mlx_srct, game->mlx_srct.plyr.x, game->mlx_srct.plyr.y,
		game);
	calculate_distances(&game->mlx_srct, game);
}
