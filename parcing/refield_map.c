/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refield_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:25:47 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/16 19:17:25 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
			count ++;
			j ++;
		}
		if(count > big_line)
			big_line = count;
		i ++;
	}
	return (big_line);
}

void	continu_make_square_map(char ***new_tab, int xx, int y)
{
	int	j;
	int i;

	i = 0;
	while (xx)
	{
		j = 0;
		while (j < y)
		{
			new_tab[0][i][j] = ' ';
			j ++;
		}
		new_tab[0][i][j] = '\0';
		i ++;
		xx --;
	}
	new_tab[1] = 0;
}

char	**make_square_map(int x, int y)
{
	char	**new_tab;
	int j;
	int i;
	int xx;

	xx = x;
	i = 0;
	j = 0;
	if (!(new_tab = malloc(sizeof(char *) * x + 1)))
		return(NULL);
	while (x)
	{
		new_tab[i] = malloc(sizeof(char) * y + 1);
		i ++;
		x --;
	}
	continu_make_square_map(&new_tab, xx, y);
	new_tab[xx] = NULL;
	return (new_tab);
}
