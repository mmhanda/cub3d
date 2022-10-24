/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:41:48 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/24 19:08:20 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*read_map(int fd)
{
	int		checker;
	char	*buffer;
	char	*map_line;

	checker = 1;
	map_line = ft_strdup("");
	buffer = malloc(2);
	if (!buffer)
		return (NULL);
	while (checker)
	{
		checker = read(fd, buffer, 1);
		if (checker == -1)
		{
			free(buffer);
			free(map_line);
			return (NULL);
		}
		buffer[checker] = '\0';
		map_line = ft_strjoin(map_line, buffer);
	}
	return (free(buffer), map_line);
}

void	check_valid_path(char **parced_map, t_parce *paths_rgb)
{
	int	verify;

	verify = 0;
	if (paths_rgb->compas_count.no_count == 1)
		paths_rgb->no_path = parced_map[paths_rgb->compas_count.no_index];
	else
		verify = -1;
	if (paths_rgb->compas_count.so_count == 1)
		paths_rgb->so_path = parced_map[paths_rgb->compas_count.so_index];
	else
		verify = -1;
	if (paths_rgb->compas_count.we_count == 1)
		paths_rgb->we_path = parced_map[paths_rgb->compas_count.we_index];
	else
		verify = -1;
	if (paths_rgb->compas_count.ea_count == 1)
		paths_rgb->ea_path = parced_map[paths_rgb->compas_count.ea_index];
	else
		verify = -1;
	if (verify == -1)
	{
		write(2, "coupl paths\n", 12);
		ft_free_parced_map(parced_map);
	}
}

void	conti_handle_textur_path(char **parced_map, t_parce *paths_rgb, int *i)
{
	if (ft_strstr(parced_map[*i], "NO "))
	{
		paths_rgb->compas_count.no_index = *i;
		paths_rgb->compas_count.no_count++;
	}
	if (ft_strstr(parced_map[*i], "SO "))
	{
		paths_rgb->compas_count.so_index = *i;
		paths_rgb->compas_count.so_count++;
	}
	if (ft_strstr(parced_map[*i], "EA "))
	{
		paths_rgb->compas_count.ea_index = *i;
		paths_rgb->compas_count.ea_count++;
	}
	if (ft_strstr(parced_map[*i], "WE "))
	{
		paths_rgb->compas_count.we_index = *i;
		paths_rgb->compas_count.we_count++;
	}
}

void	handle_textur_path(char **parced_map, t_parce *paths_rgb)
{
	int	i;

	i = 0;
	init_map_struct(paths_rgb);
	while (parced_map[i])
	{
		conti_handle_textur_path(parced_map, paths_rgb, &i);
		i ++;
	}
	check_valid_path(parced_map, paths_rgb);
	paths_rgb->parced_map = parced_map;
	extract_check_path(paths_rgb);
	handl_color(parced_map, paths_rgb);
}

void	parce_map(char *map_line, t_parce *paths_rgb)
{
	int		i;
	char	**parced_map;

	i = 0;
	parced_map = ft_split(map_line, '\n');
	handle_textur_path(parced_map, paths_rgb);
	paths_rgb->map_lin = map_line;
	parced_map = handl_map(parced_map, paths_rgb);
	paths_rgb->parced_map = parced_map;
}
