/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:10:30 by mhanda            #+#    #+#             */
/*   Updated: 2022/09/14 20:02:05 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_strdup(char *s1)
{
	char	*tab;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	tab = (char *)malloc(sizeof(char) * i + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	while (s[start] != '\0' && start < ft_strlen(s) && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

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
