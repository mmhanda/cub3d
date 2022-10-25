/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_parce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:44:51 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 23:39:34 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_b.h"

void	free_s_parced_map(t_map *ptr)
{
	t_map	*tmp;

	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}

int	count_list_len(t_map *node)
{
	int	i;

	i = 0;
	while (node)
	{
		i ++;
		node = node->next;
	}
	return (i);
}

int	count_tab_len(char **node)
{
	int	i;

	i = 0;
	while (node[i])
		i ++;
	return (i);
}

char	**list_to_tab(t_map *node)
{
	char	**tab;
	int		i;
	int		len;
	t_map	*tmp;

	i = 0;
	tmp = node;
	len = count_list_len(node);
	tab = malloc(sizeof(char *) * len + 1);
	if (!tab)
		return (NULL);
	while (node)
	{
		tab[i] = node->line;
		node = node->next;
		i++;
	}
	tab[i] = NULL;
	free_s_parced_map(tmp);
	return (tab);
}

void	handl_player_case(char **tab, int x, int y, t_parce *paths_rgb)
{
	if (x == (paths_rgb->mlx_srct.tab_len - 1) || x == 0)
	{
		write(2, "wrong player position\n", 22);
		map_error(tab, paths_rgb);
	}
	if ((tab[x][y + 1] != '1' && tab[x][y - 1] != '1')
		|| (tab[x + 1][y] != '1' && tab[x - 1][y] != '1')
		|| (tab[x + 1][y] != '0' && tab[x - 1][y] != '0')
		|| (tab[x][y + 1] != '0' && tab[x][y - 1] != '0'))
	{
		write(2, "unexpected character\n", 21);
		map_error(tab, paths_rgb);
	}
}
