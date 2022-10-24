/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:57:08 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/24 18:36:47 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	compas(t_parce *game, double value, int set_compas)
{
	double  move_step;
	if (set_compas == 0)
	{
		move_step = (value * 2);
		game->mlx_srct.plyr.x += cos(game->mlx_srct.plyr.rotate) * move_step;
		game->mlx_srct.plyr.y += sin(game->mlx_srct.plyr.rotate) * move_step;
	}
	if (set_compas == 1)
	{
		game->mlx_srct.plyr.x -= value;
	}
}

int	check_wall(t_parce *game, double new_x, double new_y)
{
	int	map_index_x;
	int	map_index_y;	
	int	tmp_y = game->mlx_srct.plyr.y;
	int	tmp_x = game->mlx_srct.plyr.x;

	map_index_x = floor(new_x );
	map_index_y = floor(new_y );
	if (new_x < 0 || new_y < 0 || game->parced_map[tmp_y][map_index_x] == '1'
		|| game->parced_map[map_index_y][tmp_x] == '1')
		return (0);
	if (game->parced_map[map_index_y][map_index_x] == '0')
		return (1);
	return (0);
}

int	mlx_key_press(int preced_key, t_parce *game)
{


	/*linux */

	// if (preced_key == 65307)
	// {
	// 	printf("Quit !\n");
	// 	exit(0);
	// }
	// if (preced_key == 119)
	// 	game->mlx_srct.plyr.walk_direction = 1;
	// if (preced_key == 115)
	// 	game->mlx_srct.plyr.walk_direction = -1;
	// if (preced_key == 97)
	// 	game->mlx_srct.plyr.right_or_left = -1;
	// if (preced_key == 100)
	// 	game->mlx_srct.plyr.right_or_left = 1;
	// if(preced_key == 65363)
	// 	game->mlx_srct.plyr.turn_direction = 1;
	// if(preced_key == 65361)
	// 	game->mlx_srct.plyr.turn_direction = -1;
	// paint_mini_map(&game->mlx_srct, game);


	
	if (preced_key == 53)
	{
		printf("Quit !\n");
		exit(0);
	}
	if (preced_key == 13)
		game->mlx_srct.plyr.walk_direction = 1;
	if (preced_key == 1)
		game->mlx_srct.plyr.walk_direction = -1;
	if (preced_key == 0)
		game->mlx_srct.plyr.right_or_left = -1;
	if (preced_key == 2)
		game->mlx_srct.plyr.right_or_left = 1;
	if(preced_key == 124)
		game->mlx_srct.plyr.turn_direction = 1;
	if(preced_key == 123)
		game->mlx_srct.plyr.turn_direction = -1;
	paint_mini_map(&game->mlx_srct, game);
	return (0);
}

