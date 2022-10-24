/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:15:18 by atabiti           #+#    #+#             */
/*   Updated: 2022/10/24 04:58:58 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"



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

bool	is_right(double angle_in_radian)
{
	if (angle_in_radian < (M_PI / 2) || angle_in_radian > (1.5 * M_PI))
		return (true);
	return (false);
}

bool	is_down(double angle_in_radian)
{
	if (angle_in_radian > 0 && angle_in_radian < M_PI)
		return (true);
	return (false);
}