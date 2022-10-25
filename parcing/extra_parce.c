/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_parce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:52 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 12:44:29 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	map_error(char **tab, t_parce *paths_rgb)
{
	free_textur_paths(paths_rgb);
	ft_free_parced_map(tab);
}

void	handl_zero_case(char **tab, int x, int y, t_parce *paths_rgb)
{
	if (x == (paths_rgb->mlx_srct.tab_len - 1) || x == 0)
	{
		write(2, "wrong space position\n", 21);
		map_error(tab, paths_rgb);
	}
	else if (tab[x - 1][y] <= 32 || tab[x + 1][y] <= 32 \
			|| tab[x][y - 1] <= 32 || tab[x][y + 1] <= 32)
	{
		write(2, "unexpected space\n", 17);
		map_error(tab, paths_rgb);
	}
}

void	continue_check_map_condion(int verify, t_map *node, t_parce *paths_rgb)
{
	if (verify != 1)
	{
		write(2, "many less player\n", 17);
		free_textur_paths(paths_rgb);
		free_parced_map(node);
	}
}

void	check_map_conditions_two(t_map *node, t_parce *paths_rgb)
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
			if (node->line[i] == 'N' || node->line[i] == 'S'
				|| node->line[i] == 'W' || node->line[i] == 'E')
			verify ++;
			i ++;
		}
		i = 0;
		node = node->next;
	}
	continue_check_map_condion(verify, h_node, paths_rgb);
}

char	**field_by_space(char **tab, t_parce *paths_rgb)
{
	int		tab_len;
	int		bige_line;
	char	**squar_tab;

	tab_len = 0;
	tab_len = count_tab_len(tab);
	bige_line = count_max_len(tab);
	paths_rgb->mlx_srct.tab_len = tab_len;
	paths_rgb->mlx_srct.longest_line = bige_line;
	squar_tab = make_square_map(tab_len, bige_line);
	tab_len = 0;
	bige_line = 0;
	while (squar_tab[tab_len])
	{
		while (tab[tab_len][bige_line])
		{
			squar_tab[tab_len][bige_line] = tab[tab_len][bige_line];
			bige_line ++;
		}
		bige_line = 0;
		tab_len ++;
	}
	ft_free_leaked_parced_map(tab);
	return (squar_tab);
}
