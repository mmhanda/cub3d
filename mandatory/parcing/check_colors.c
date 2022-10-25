/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:06:35 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/24 05:39:11 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	continu_get_correct_number_c(t_parce *paths_rgb, int t)
{
	int	cama;

	cama = 0;
	while (paths_rgb->c_color[t])
	{
		if (ft_isdigit(paths_rgb->c_color[t]))
		{
			if (paths_rgb->c_color[t] != ',')
			{
				write(2, "color mixed char and number\n", 28);
				free_textur_paths(paths_rgb);
				ft_free_parced_map(paths_rgb->parced_map);
			}
			else
				cama ++;
		}
		t ++;
	}
	if (cama != 2)
	{
		write(2, "multi color number\n", 19);
		free_textur_paths(paths_rgb);
		ft_free_parced_map(paths_rgb->parced_map);
	}
}

void	get_correct_number_c(t_parce *paths_rgb)
{
	int	no;
	int	t;

	t = 0;
	if (paths_rgb->c_color[1] != ' ')
	{
		write(2, "error\n", 6);
		exit(0);
	}
	no = ft_strlen(paths_rgb->c_color);
	while (paths_rgb->c_color[no] == ' ' || paths_rgb->c_color[no] == '\t'
		|| paths_rgb->c_color[no] == '\0')
	{
		++ t;
		no --;
	}
	no = ft_strlen(paths_rgb->c_color) - (paths_rgb->compas_count.c_count + t);
	paths_rgb->c_color = ft_strndup(paths_rgb->c_color
			+ paths_rgb->compas_count.c_count, no);
	t = 0;
	continu_get_correct_number_c(paths_rgb, t);
}

void	continu_get_correct_number_f(t_parce *paths_rgb, int t)
{
	int	cama;

	cama = 0;
	while (paths_rgb->f_color[t])
	{
		if (ft_isdigit(paths_rgb->f_color[t]))
		{
			if (paths_rgb->f_color[t] != ',')
			{
				write(2, "color mixed char and number\n", 28);
				free_textur_paths(paths_rgb);
				ft_free_parced_map(paths_rgb->parced_map);
			}
			else
				cama ++;
		}
		t ++;
	}
	if (cama != 2)
	{
		write(2, "multi color number\n", 19);
		free_textur_paths(paths_rgb);
		ft_free_parced_map(paths_rgb->parced_map);
	}
}

void	get_correct_number_f(t_parce *paths_rgb)
{
	int	no;
	int	t;

	t = 0;
	if (paths_rgb->f_color[1] != ' ')
	{
		write(2, "error\n", 6);
		exit(0);
	}
	no = ft_strlen(paths_rgb->f_color);
	while (paths_rgb->f_color[no] == ' ' || paths_rgb->f_color[no] == '\t'
		|| paths_rgb->f_color[no] == '\0')
	{
		++ t;
		no --;
	}
	no = ft_strlen(paths_rgb->f_color) - (paths_rgb->compas_count.f_count + t);
	paths_rgb->f_color = ft_strndup(paths_rgb->f_color
			+ paths_rgb->compas_count.f_count, no);
	t = 0;
	continu_get_correct_number_f(paths_rgb, t);
}

void	check_digit(t_parce *paths_rgb)
{
	get_correct_number_c(paths_rgb);
	get_correct_number_f(paths_rgb);
}
