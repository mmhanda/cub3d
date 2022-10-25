/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:10:30 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 16:50:53 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	ft_wordlen(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_wordcount(const char *s, char spl)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == spl)
			i++;
		if (s[i] != '\0')
			k++;
		while (s[i] && s[i] != spl)
			i++;
	}
	return (k);
}

static void	ft_inits(int *i, int *k)
{
	*i = -1;
	*k = -1;
}

static void	ft_free(char **spl)
{
	int	j;

	j = -1;
	while (spl[++j])
		free(spl[j]);
	free(spl);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**spl;
	int		k;

	ft_inits(&i, &k);
	if (!s)
		return (NULL);
	spl = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!spl)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			spl[++k] = ft_substr(s, i, ft_wordlen(s + i, c));
			if (!spl[k])
			{
				ft_free(spl);
				return (NULL);
			}
			i = i + ft_wordlen(s + i, c) - 1;
		}
	}
	spl[++k] = NULL;
	return (spl);
}
