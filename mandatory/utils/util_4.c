/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:25:14 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 16:51:12 by mhanda           ###   ########.fr       */
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
	int		i;

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
