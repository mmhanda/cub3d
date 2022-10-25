/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:07:40 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 16:47:48 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(const char *s, const char *tofind)
{
	int	i;
	int	j;

	i = 0;
	if (tofind[0] == '\0')
	{
		return ((char *)(s));
	}
	while (s[i])
	{
		j = 0;
		while (s[i + j] == tofind[j])
		{
			if (tofind[j + 1] == '\0')
				return ((char *)(s + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (s1[j])
	{
		p[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		p[i++] = s2[j++];
	}
	p[i] = '\0';
	free (s1);
	s1 = NULL;
	return (p);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_put_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i += 1;
	}
	exit (0);
}
