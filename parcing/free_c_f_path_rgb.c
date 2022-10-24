/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_c_f_path_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:29:45 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/24 18:31:52 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	free_textur_paths(t_parce *paths_rgb)
{
	free(paths_rgb->no_path);
	free(paths_rgb->so_path);
	free(paths_rgb->we_path);
	free(paths_rgb->ea_path);
	free(paths_rgb->map_lin);
}

char	**check_map_holes(t_map *node, t_parce *paths_rgb)
{
	char	**tab;
	int		x;
	int		y;
	int		len;

	tab = list_to_tab(node);
	tab = field_by_space(tab, paths_rgb);
	paths_rgb->parced_map = tab;
	paths_rgb->mlx_srct.tab_len = count_tab_len(tab);
	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[x][y] == 'N' && tab[x][y] == 'S'
				&& tab[x][y] == 'W' && tab[x][y] == 'E')
				handl_player_case(tab, x, y, paths_rgb);
			else if (tab[x][y] == '0')
				handl_zero_case(tab, x, y, paths_rgb);
			y ++;
		}
		x ++;
	}
	return (tab);
}

void	continue_check_map_condi(int verify, t_map *node, t_parce *paths_rgb)
{
	if (verify)
	{
		write(2, "map conditions problem \n", 24);
		free_textur_paths(paths_rgb);
		free_parced_map(node);
	}
}

void	check_map_conditions(t_map *node, t_parce *paths_rgb)
{
	int		i;
	int		verify;
	t_map	*h_node;

	h_node = node;
	i = 0;
	verify = 0;
	while (node)
	{
		while (node->line[i])
		{
			if (node->line[i] != ' ' && node->line[i] != '1'
				&& node->line[i] != '0'
				&& node->line[i] != 'N' && node->line[i] != 'S'
				&& node->line[i] != 'W'
				&& node->line[i] != 'E' && node->line[i] != '\t')
				verify ++;
			i ++;
		}
		continue_check_map_condi(verify, h_node, paths_rgb);
		i = 0;
		node = node->next;
	}
}

void	check_new_lines(t_map *node, t_parce *paths_rgb)
{
	int	i;
	int	new_line;

	i = 1;
	while (paths_rgb->map_lin[i])
	{
		if (paths_rgb->map_lin[i - 1] == '1' && paths_rgb->map_lin[i] == '\n')
		{
			i ++;
			new_line = 0;
			while (paths_rgb->map_lin[i - 1] == '\n')
			{
				i ++;
				new_line ++;
				if (new_line > 1)
				{
					write(2, "map line problem\n", 17);
					free_textur_paths(paths_rgb);
					free_parced_map(node);
				}
			}
		}
		i ++;
	}
}
