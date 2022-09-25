/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:42:28 by mhanda            #+#    #+#             */
/*   Updated: 2022/09/24 23:03:22 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


int	check_arg(int ac,char **av)
{
	int		fd;
	char	*ret;
	char	*path;

	if (ac != 2)
		exit(0);
	ret = ft_strstr(av[1], ".cub");
	if (ret == NULL)
			ft_put_error(".cub not find\n");
	else
		if (ft_strcmp(ret, ".cub") != 0)
			ft_put_error(".cub not match\n");
	path = ft_strjoin(ft_strdup("maps/"), av[1]);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 0)
		ft_put_error("file not found\n");
	return(fd);
}

int	main(int ac, char **av)
{
	t_parce	game;

	parce_map(read_map(check_arg(ac, av)), &game);
	graphics_handle(&game);
	//don't forget to handle no map case just paths ans colors
}
