/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:34:44 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/16 20:05:22 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	continu_update_pos(t_mlx *mlx_srct, t_parce *game)
{
	double	new_x;
	double	new_y;

	if(mlx_srct->plyr.right_or_left != 0)
	{
		new_y = game->mlx_srct.plyr.y + cos(game->mlx_srct.plyr.rotate)\
		*(mlx_srct->plyr.right_or_left * MOVE_SPEED);
		new_x = game->mlx_srct.plyr.x - sin(game->mlx_srct.plyr.rotate)\
		*(mlx_srct->plyr.right_or_left * MOVE_SPEED);
		if (check_wall(game, new_x, new_y) == 1)
		{
			game->mlx_srct.plyr.y += cos(game->mlx_srct.plyr.rotate) * (mlx_srct->plyr.right_or_left * MOVE_SPEED);
			game->mlx_srct.plyr.x -= sin(game->mlx_srct.plyr.rotate) * (mlx_srct->plyr.right_or_left * MOVE_SPEED);
		}
	}
}

void	update_pos(t_mlx *mlx_srct, t_parce *game)
{
	double	move_step;
	double	new_x;
	double	new_y;

	mlx_srct->plyr.rotate += mlx_srct->plyr.rotaion_speed * mlx_srct->plyr.turn_direction;
	mlx_srct->plyr.rotate = fmod(mlx_srct->plyr.rotate, 2 * M_PI);
	if (mlx_srct->plyr.rotate < 0)
		mlx_srct->plyr.rotate += (2 * M_PI);
	move_step = mlx_srct->plyr.walk_direction * mlx_srct->plyr.move_speed;
	new_x = mlx_srct->plyr.x + (cos(mlx_srct->plyr.rotate) * move_step);
	new_y = mlx_srct->plyr.y + (sin(mlx_srct->plyr.rotate) * move_step);
	if (mlx_srct->plyr.right_or_left == 0)
	{
		if (check_wall(game, new_x, new_y) == 1)
		{
			mlx_srct->plyr.x += cos(mlx_srct->plyr.rotate) * move_step;
			mlx_srct->plyr.y += sin(mlx_srct->plyr.rotate) * move_step;
		}
	}
	continu_update_pos(mlx_srct, game);
}

void	continu_paint_mini_map(t_mlx *mlx_srct, t_parce *game_map)
{
	int	i;
	int	j;

	i = 0;
		while (game_map->parced_map[i])
	{
		j = 0;
		while (game_map->parced_map[i][j])
		{
			if (game_map->parced_map[i][j] == '1')
				paint_walls(mlx_srct, game_map, j, i);
			if (game_map->parced_map[i][j] == '0')
				paint_ground(mlx_srct, game_map, j, i);
			j ++;
		}
		i ++;
	}
}

void	paint_mini_map(t_mlx *mlx_srct, t_parce *game_map)
{
	if (mlx_srct->des_remind == 1)
	{
		mlx_clear_window(game_map->mlx_srct.mlx_ptr, game_map->mlx_srct.win_ptr);
		mlx_destroy_image(game_map->mlx_srct.mlx_ptr, game_map->mlx_srct.mlx_m.mlx_img);
	}
	update_pos(mlx_srct, game_map);
	mlx_srct->mlx_m.mlx_img = mlx_new_image(mlx_srct->mlx_ptr, WIDTH, HEIGHT);
	mlx_srct->mlx_m.addr = mlx_get_data_addr(mlx_srct->mlx_m.mlx_img, &mlx_srct->mlx_m.bpp,
	&mlx_srct->mlx_m.size_line, &mlx_srct->mlx_m.endian);
	continu_paint_mini_map(mlx_srct, game_map);
	// paint_player(mlx_srct, mlx_srct->plyr.x, mlx_srct->plyr.y);
	paint_p_line(mlx_srct, mlx_srct->plyr.x, mlx_srct->plyr.y);
	paint_rays(mlx_srct, game_map);
	mlx_srct->des_remind = 1;
	mlx_put_image_to_window(mlx_srct->mlx_ptr, mlx_srct->win_ptr, mlx_srct->mlx_m.mlx_img, 0, 0);
}

void	graphics_handle(t_parce *game_map)
{
	int	reload;

	reload = -1;
	make_texturs(game_map);
	handl_player(game_map, &game_map->mlx_srct);
	game_map->mlx_srct.mlx_ptr = mlx_init();
	game_map->mlx_srct.win_ptr = mlx_new_window(game_map->mlx_srct.mlx_ptr, WIDTH, HEIGHT, "mhanda");
	if (++reload == 0)
		paint_mini_map(&game_map->mlx_srct, game_map);
	mlx_hook(game_map->mlx_srct.win_ptr, 2, (1L << 0), mlx_key_press, game_map);
	mlx_hook(game_map->mlx_srct.win_ptr, 3, (1L << 1), mlx_key_releas, game_map);
	mlx_hook(game_map->mlx_srct.win_ptr, 17, 0, mlx_x_key_han, game_map);
	mlx_loop(game_map->mlx_srct.mlx_ptr);
}
