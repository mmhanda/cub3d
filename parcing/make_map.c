/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:41:04 by mhanda            #+#    #+#             */
/*   Updated: 2022/09/17 02:45:14 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ra(t_map **node)
{
	int	verify;
	t_map	*tmp;

	verify = 0;
	tmp = (*node);
	while ((*node) && verify <= 6)
	{
		if (ft_strstr((*node)->line, "F"))
			verify ++;
		else if (ft_strstr((*node)->line, "C"))
			verify ++;
		else if (ft_strstr((*node)->line, "NO"))
			verify ++;
		else if (ft_strstr((*node)->line, "SO"))
			verify ++;
		else if (ft_strstr((*node)->line, "WE"))
			verify ++;
		else if (ft_strstr((*node)->line, "EA"))
			verify ++;
		else
			break;
		(*node) = (*node)->next;
	}
	(*node) = tmp;
	return (verify);
}

t_map	*tab_to_list(char **parced_map)
{
	t_map	*ptr;
	t_map	*node; 
	int		j;

	j = 0;
	node = malloc(sizeof(t_map));
	ptr = node;
	while (parced_map[j])
	{
		node->line = parced_map[j];
		node->next = NULL;
		j++;
		if (parced_map[j])
		{
			node->next = malloc(sizeof(t_map));
			node = node->next;
		}
	}
	node = ptr;
	j = 0;
	free(parced_map);
	return (node);
}

void	free_parced_map(t_map *ptr)
{
	t_map	*tmp;

	if(ptr)
	{
		if (ptr->next)
		{
			while (ptr)
			{
				tmp = ptr;
				ptr = ptr->next;
				free (tmp->line); 
				free(tmp);
			}
		}
		else
		{
			free(ptr->line);
			free(ptr);
		}
	}
	exit(0);
}

void	six_free(t_map **ptr)
{
	t_map	*tmp;
	int	i;

	i = 6;
	while (i)
	{
		tmp = (*ptr);
		(*ptr) = (*ptr)->next;
		free (tmp->line); 
		free(tmp);
		i --;
	}
}

char	**handl_map(char **parced_map, t_parce *paths_rgb)
{
	t_map	*node;
	int	verify;

	verify = 0;
	node = NULL;
    node = tab_to_list(parced_map);
	verify = ra(&node);
	if (verify != 6)
	{
		write(2, "unkown textur\n", 14);
		free_textur_paths(paths_rgb);
		free_parced_map(node);
	}
	if (verify == 6)
	 	six_free(&node);
	check_map_conditions(node, paths_rgb);
	check_map_conditions_two(node, paths_rgb);
	check_new_lines(node, paths_rgb);
	parced_map = check_map_holes(node, paths_rgb);
	return (parced_map);
}
