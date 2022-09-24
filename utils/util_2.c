/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:50:45 by mhanda            #+#    #+#             */
/*   Updated: 2022/09/14 06:54:16 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	*ft_memset(void *str, int c, size_t len)
{
	char	*p;

	p = str;
	while (len-- > 0)
	{
		*p = c;
		p++;
	}
	return (str);
}

int	wdc(char const *s, char c)
{
	int	wdc;
	int	i;

	i = 0;
	wdc = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wdc++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (wdc);
}

void	ft_free_parced_map(char **parced_map)
{
	int	i;

	i = 0;
	while (parced_map[i])
	{
		free (parced_map[i]);
		i ++;
	}
	free (parced_map);
	exit(0);
}

int	ft_strstr_custom(const char *s, const char *tofind)
{
	int	i;
	int	j;

	i = 0;
	if (tofind[0] == '\0')
	{
		return (i);
	}
	while (s[i])
	{
		j = 0;
		while (s[i + j] == tofind[j])
		{
			if (tofind[j + 1] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_atoi(char *str, t_parce *paths_rgb)
{
	int	sing;
	int	ok;
	int	i;

	ok = 0;
	i = 0;
	sing = 1;
	if (str[i] == '-')
		sing = -1;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '0'
			|| str[i + 1] == '1' || str[i + 1] == '2' || str[i + 1] == '3'
			|| str[i + 1] == '4' || str[i + 1] == '5' || str[i + 1] == '6'
			|| str[i + 1] == '7' || str[i + 1] == '8' || str[i + 1] == '9'))
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ok = (ok * 10) + str[i] - 48;
		i++;
	}
	if ((ok * sing) > 255 || (ok * sing) < 0)
		paths_rgb->check_min_max += -1;
	return (ok * sing);
}
