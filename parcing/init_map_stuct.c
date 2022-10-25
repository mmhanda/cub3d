/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_stuct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:20:07 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 13:51:29 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_map_struct(t_parce *paths_rgb)
{
	paths_rgb->no_path = NULL;
	paths_rgb->ea_path = NULL;
	paths_rgb->we_path = NULL;
	paths_rgb->so_path = NULL;
	paths_rgb->c_color = NULL;
	paths_rgb->f_color = NULL;
	paths_rgb->compas_count.no_count = 0;
	paths_rgb->compas_count.ea_count = 0;
	paths_rgb->compas_count.we_count = 0;
	paths_rgb->compas_count.so_count = 0;
	paths_rgb->compas_count.no_index = 0;
	paths_rgb->compas_count.ea_index = 0;
	paths_rgb->compas_count.we_index = 0;
	paths_rgb->compas_count.so_index = 0;
	paths_rgb->compas_count.c_count = 0;
	paths_rgb->compas_count.c_index = 0;
	paths_rgb->compas_count.f_count = 0;
	paths_rgb->compas_count.f_index = 0;
	paths_rgb->c.g = 0;
	paths_rgb->c.b = 0;
	paths_rgb->c.r = 0;
	paths_rgb->f.g = 0;
	paths_rgb->f.b = 0;
	paths_rgb->f.r = 0;
}

void	check_valid_file(t_parce *paths_rgb)
{
	int	no;
	int	so;
	int	we;
	int	ea;

	check_xpm(paths_rgb);
	no = open(paths_rgb->no_path, O_RDWR);
	so = open(paths_rgb->so_path, O_RDWR);
	we = open(paths_rgb->we_path, O_RDWR);
	ea = open(paths_rgb->ea_path, O_RDWR);
	close(no);
	close(so);
	close(we);
	close(ea);
	if (no < 0 || so < 0 || we < 0 || ea < 0)
	{
		write(2, "textur file error\n", 18);
		free_textur_paths(paths_rgb);
		ft_free_parced_map(paths_rgb->parced_map);
	}
}

void	extract_check_path(t_parce *paths_rgb)
{
	paths_rgb->compas_count.no_count = ft_strstr_cust(paths_rgb->no_path, "NO");
	paths_rgb->compas_count.no_count += 2;
	paths_rgb->compas_count.so_count = ft_strstr_cust(paths_rgb->so_path, "SO");
	paths_rgb->compas_count.so_count += 2;
	paths_rgb->compas_count.we_count = ft_strstr_cust(paths_rgb->we_path, "WE");
	paths_rgb->compas_count.we_count += 2;
	paths_rgb->compas_count.ea_count = ft_strstr_cust(paths_rgb->ea_path, "EA");
	paths_rgb->compas_count.ea_count += 2;
	while (paths_rgb->no_path[paths_rgb->compas_count.no_count] == ' '
		|| paths_rgb->no_path[paths_rgb->compas_count.no_count] == '\t')
			paths_rgb->compas_count.no_count ++;
	while (paths_rgb->so_path[paths_rgb->compas_count.so_count] == ' '
		|| paths_rgb->so_path[paths_rgb->compas_count.so_count] == '\t')
			paths_rgb->compas_count.so_count ++;
	while (paths_rgb->we_path[paths_rgb->compas_count.we_count] == ' '
		|| paths_rgb->we_path[paths_rgb->compas_count.we_count] == '\t')
			paths_rgb->compas_count.we_count ++;
	while (paths_rgb->ea_path[paths_rgb->compas_count.ea_count] == ' '
		|| paths_rgb->ea_path[paths_rgb->compas_count.ea_count] == '\t')
			paths_rgb->compas_count.ea_count ++;
	get_correct_path(paths_rgb);
	continu_get_correct_path(paths_rgb);
	check_valid_file(paths_rgb);
}

void	check_valid_path_color(char **parced_map, t_parce *paths_rgb)
{
	int	verify;

	verify = 0;
	if (paths_rgb->compas_count.c_count == 1)
		paths_rgb->c_color = parced_map[paths_rgb->compas_count.c_index];
	else
		verify = -1;
	if (paths_rgb->compas_count.f_count == 1)
		paths_rgb->f_color = parced_map[paths_rgb->compas_count.f_index];
	else
		verify = -1;
	if (verify == -1)
	{
		write(2, "color problem \n", 15);
		free_textur_paths(paths_rgb);
		ft_free_parced_map(parced_map);
	}
}

void	handl_color(char **parced_map, t_parce *paths_rgb)
{
	int	i;

	i = 0;
	while (parced_map[i])
	{
		if (ft_strstr(parced_map[i], "F"))
		{
			paths_rgb->compas_count.f_index = i;
			paths_rgb->compas_count.f_count ++;
		}
		if (ft_strstr(parced_map[i], "C"))
		{
			paths_rgb->compas_count.c_index = i;
			paths_rgb->compas_count.c_count ++;
		}
		i ++;
	}
	check_valid_path_color(parced_map, paths_rgb);
	check_valid_color(parced_map, paths_rgb);
}
