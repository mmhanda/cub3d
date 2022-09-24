/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:56:52 by mhanda            #+#    #+#             */
/*   Updated: 2022/09/16 04:49:37 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	continu_get_correct_path(t_parce *paths_rgb)
{
	int	no;
	int t;

	t = 0;
	no = ft_strlen(paths_rgb->we_path);
	while(paths_rgb->we_path[no] == ' ' || paths_rgb->we_path[no] == '\t'
		|| paths_rgb->we_path[no] == '\0')
	{
		++ t;
		no --;
	}
	no = ft_strlen(paths_rgb->we_path) - (paths_rgb->compas_count.we_count + t);
	paths_rgb->we_path = ft_strndup(paths_rgb->we_path +
			paths_rgb->compas_count.we_count, no);
	t = 0;
	no = ft_strlen(paths_rgb->ea_path);
	while(paths_rgb->ea_path[no] == ' ' || paths_rgb->ea_path[no] == '\t'
			|| paths_rgb->ea_path[no] == '\0')
	{
		++ t;
		no --;
	}
	no = ft_strlen(paths_rgb->ea_path) - (paths_rgb->compas_count.ea_count + t);
	paths_rgb->ea_path = ft_strndup(paths_rgb->ea_path
			+ paths_rgb->compas_count.ea_count, no);
}

void	get_correct_path(t_parce *paths_rgb)
{
	int	no;
	int t;

	t = 0;
	no = ft_strlen(paths_rgb->no_path);
	while(paths_rgb->no_path[no] == ' ' || paths_rgb->no_path[no] == '\t'
		|| paths_rgb->no_path[no] == '\0')
	{
		++ t;
		no --;
	}
	no = ft_strlen(paths_rgb->no_path) - (paths_rgb->compas_count.no_count + t);
	paths_rgb->no_path = ft_strndup(paths_rgb->no_path +
			paths_rgb->compas_count.no_count, no);
	t = 0;
	no = ft_strlen(paths_rgb->so_path);
	while(paths_rgb->so_path[no] == ' ' || paths_rgb->so_path[no] == '\t'
			|| paths_rgb->so_path[no] == '\0')
	{
		++ t;
		no --;
	}
	no = ft_strlen(paths_rgb->so_path) - (paths_rgb->compas_count.so_count + t);
	paths_rgb->so_path = ft_strndup(paths_rgb->so_path
			+ paths_rgb->compas_count.so_count, no);
}

void	convert_color(t_parce *paths_rgb, char ***c, char ***f)
{
	int	i;

	i = 0;
	paths_rgb->check_min_max = 0;
	paths_rgb->c.r = ft_atoi(c[0][0], paths_rgb);
	paths_rgb->f.r = ft_atoi(f[0][0], paths_rgb);
	paths_rgb->c.g = ft_atoi(c[0][1], paths_rgb);
	paths_rgb->f.g = ft_atoi(f[0][1], paths_rgb);
	paths_rgb->c.b = ft_atoi(c[0][2], paths_rgb);
	paths_rgb->f.b = ft_atoi(f[0][2], paths_rgb);
	if (paths_rgb->check_min_max < 0)
	{
		write(2, "arg color problem\n", 18);
		exit(0);
		while (c[0][i] && f[0][i])
		{
			free (c[0][i]);
			free (f[0][i]);
			i ++;
		}
		free (c[0]);
		free (f[0]);
		free_textur_paths(paths_rgb);
		ft_free_parced_map(paths_rgb->parced_map);
	}
	while (c[0][i] && f[0][i])
	{
		free (c[0][i]);
		free (f[0][i]);
		i ++;
	}
	free (c[0]);
	free (f[0]);
}

void	get_colors(t_parce *paths_rgb)
{
	char	**c;
	char	**f;
	int		i;

	i = 0;
	check_digit(paths_rgb);
	c = ft_split(paths_rgb->c_color, ',');
	f = ft_split(paths_rgb->f_color, ',');
	while (f[i] || c[i])
		i ++;
	if (i != 3)
	{
		i = 0;
		write(2, "arg color problem !\n", 20);
		exit(0);
		// while (c[i] && f[i])
		// {
		// 	free (c[i]);
		// 	free (f[i]);
		// 	i ++;
		// }
		// free (c);
		// free (f);
		// free_textur_paths(paths_rgb);
		// ft_free_parced_map(paths_rgb->parced_map);
	}
	free (paths_rgb->c_color);
	free (paths_rgb->f_color);
	convert_color(paths_rgb, &c, &f);
}

void	check_valid_color(char **parced_map, t_parce *paths_rgb)
{
	int	f_count;
	int	c_count;
	
	parced_map = NULL;
	f_count = 0;
	c_count = 0;
	f_count = ft_strstr_custom(paths_rgb->f_color, "F");
	f_count += 1;
	c_count = ft_strstr_custom(paths_rgb->c_color, "C");
	c_count += 1;
	while (paths_rgb->f_color[f_count] == ' '
		|| paths_rgb->f_color[f_count] == '\t')
		f_count++;
	while (paths_rgb->c_color[c_count] == ' '
		|| paths_rgb->c_color[c_count] == '\t')
		c_count++;
	paths_rgb->compas_count.c_count = c_count;
	paths_rgb->compas_count.f_count = f_count;
	get_colors(paths_rgb);
}
