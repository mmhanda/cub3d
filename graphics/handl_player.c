/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:39:16 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 14:04:26 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	mlx_x_key_han(void)
{
	exit(0);
}

void	make_texturs(t_parce *game_map)
{
	game_map->f_colo = (game_map->f.r << 16) + (game_map->f.g << 8)
		+ game_map->f.b;
	game_map->c_colo = (game_map->c.r << 16) + (game_map->c.g << 8)
		+ game_map->c.b;
}

int	set_direction(char p, t_mlx *mlx_srct)
{
	if (p == 'N')
	{
		mlx_srct->plyr.rotate = (3 * M_PI) / 2;
		return (1);
	}
	if (p == 'S')
	{
		mlx_srct->plyr.rotate = M_PI / 2;
		return (1);
	}
	if (p == 'W')
	{
		mlx_srct->plyr.rotate = M_PI;
		return (1);
	}
	if (p == 'E')
	{
		mlx_srct->plyr.rotate = 0;
		return (1);
	}
	return (0);
}

int	mlx_key_releas(int preced_key, t_parce *game)
{
	if (preced_key == 53)
	{
		printf("Quit !\n");
		exit(0);
	}
	if (preced_key == 13)
		game->mlx_srct.plyr.walk_direction = 0;
	if (preced_key == 1)
		game->mlx_srct.plyr.walk_direction = 0;
	if (preced_key == 0)
		game->mlx_srct.plyr.right_or_left = 0;
	if (preced_key == 2)
		game->mlx_srct.plyr.right_or_left = 0;
	if (preced_key == 124)
		game->mlx_srct.plyr.turn_direction = 0;
	if (preced_key == 123)
		game->mlx_srct.plyr.turn_direction = 0;
	paint_mini_map(&game->mlx_srct, game);
	return (0);
}

void	handl_player(t_parce *game_map, t_mlx *mlx_srct)
{
	int	i;
	int	j;

	i = 0;
	while (game_map->parced_map[i])
	{
		j = 0;
		while (game_map->parced_map[i][j])
		{
			if (set_direction(game_map->parced_map[i][j], mlx_srct) == 1)
			{
				mlx_srct->plyr.x = j;
				mlx_srct->plyr.y = i;
				game_map->parced_map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	mlx_srct->plyr.turn_direction = 0;
	mlx_srct->plyr.walk_direction = 0;
	mlx_srct->plyr.right_or_left = 0;
	mlx_srct->plyr.rotaion_speed = 8 * (M_PI / 180);
	mlx_srct->plyr.move_speed = MOVE_SPEED;
}
