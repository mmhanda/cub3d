/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:25:53 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 16:56:03 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_strndup(char *src, int n)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	n += 1;
	i = n;
	while (src[size] && n)
	{
		++size;
		n --;
	}
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	n = i;
	i = 0;
	while (src[i] && n)
	{
		new[i] = src[i];
		i ++;
		n --;
	}
	new[i] = '\0';
	return (new);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (0);
	}
	return (1);
}

void	ft_free_leaked_parced_map(char **parced_map)
{
	int	i;

	i = 0;
	while (parced_map[i])
	{
		free (parced_map[i]);
		i ++;
	}
	free (parced_map);
}
