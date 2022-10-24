/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:42:28 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/24 05:41:39 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_arg(int ac,char **av)
{
	int		fd;
	char	*ret;

	if (ac != 2)
		exit(0);
	ret = ft_strstr(av[1], ".cub");
	if (ret == NULL)
			ft_put_error(".cub not find\n");
	else
		if (ft_strcmp(ret, ".cub") != 0)
			ft_put_error(".cub not match\n");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_put_error("file not found\n");
	return(fd);
}

int	main(int ac, char **av)
{
	t_parce	game;

	parce_map(read_map(check_arg(ac, av)), &game);
	graphics_handle(&game);
}
