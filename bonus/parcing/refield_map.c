/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refield_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:25:47 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 23:39:34 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_b.h"

int	count_max_len(char **tab)
{
	int	big_line;
	int	count;
	int	i;
	int	j;

	big_line = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		count = 0;
		while (tab[i][j])
		{
			count++;
			j++;
		}
		if (count > big_line)
			big_line = count;
		i++;
	}
	return (big_line);
}

void	continu_make_square_map(char ***new_tab, int xx, int y)
{
	int	j;
	int	i;

	i = 0;
	while (xx)
	{
		j = 0;
		while (j < y)
		{
			new_tab[0][i][j] = ' ';
			j++;
		}
		new_tab[0][i][j] = '\0';
		i++;
		xx--;
	}
	new_tab[1] = 0;
}

char	**make_square_map(int x, int y)
{
	char	**new_tab;
	int		j;
	int		i;
	int		xx;

	new_tab = NULL;
	xx = x;
	i = 0;
	j = 0;
	new_tab = (char **)malloc(sizeof(char *) * (x + 1));
	if (!new_tab)
		return (NULL);
	while (x)
	{
		new_tab[i] = malloc(sizeof(char) * (y + 1));
		i++;
		x--;
	}
	continu_make_square_map(&new_tab, xx, y);
	new_tab[xx] = NULL;
	return (new_tab);
}

void	convert_color_to_int(t_parce *paths_rgb, char ***c, char ***f)
{
	paths_rgb->check_min_max = 0;
	paths_rgb->c.r = ft_atoi(c[0][0], paths_rgb);
	paths_rgb->f.r = ft_atoi(f[0][0], paths_rgb);
	paths_rgb->c.g = ft_atoi(c[0][1], paths_rgb);
	paths_rgb->f.g = ft_atoi(f[0][1], paths_rgb);
	paths_rgb->c.b = ft_atoi(c[0][2], paths_rgb);
	paths_rgb->f.b = ft_atoi(f[0][2], paths_rgb);
}

void	check_xpm(t_parce *paths_rgb)
{
	char	*ret;

	ret = ft_strstr(paths_rgb->no_path, ".xpm");
	if (ret == NULL)
		ft_put_error(".xpm not find\n");
	ret = ft_strstr(paths_rgb->so_path, ".xpm");
	if (ret == NULL)
		ft_put_error(".xpm not find\n");
	ret = ft_strstr(paths_rgb->we_path, ".xpm");
	if (ret == NULL)
		ft_put_error(".xpm not find\n");
	ret = ft_strstr(paths_rgb->ea_path, ".xpm");
	if (ret == NULL)
		ft_put_error(".xpm not find\n");
}
