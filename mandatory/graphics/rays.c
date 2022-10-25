/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:57:23 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 17:07:06 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	load_xpm(t_parce *game)
{
	t_img	img;
	int		h;
	int		*h_ptr;

	h = 64;
	h_ptr = &h;
	game->mlx_srct.r.xpm_no = mlx_xpm_file_to_image(game->mlx_srct.mlx_ptr,
			game->no_path, h_ptr, h_ptr);
	game->mlx_srct.r.data_no = (int *)mlx_get_data_addr(game->mlx_srct.r.xpm_no,
			&img.bpp, &img.size_line, &img.endian);
	game->mlx_srct.r.xpm_so = mlx_xpm_file_to_image(game->mlx_srct.mlx_ptr,
			game->so_path, h_ptr, h_ptr);
	game->mlx_srct.r.data_so = (int *)mlx_get_data_addr(game->mlx_srct.r.xpm_so,
			&img.bpp, &img.size_line, &img.endian);
	game->mlx_srct.r.xpm_we = mlx_xpm_file_to_image(game->mlx_srct.mlx_ptr,
			game->we_path, h_ptr, h_ptr);
	game->mlx_srct.r.data_we = (int *)mlx_get_data_addr(game->mlx_srct.r.xpm_we,
			&img.bpp, &img.size_line, &img.endian);
	game->mlx_srct.r.xpm_ea = mlx_xpm_file_to_image(game->mlx_srct.mlx_ptr,
			game->ea_path, h_ptr, h_ptr);
	game->mlx_srct.r.data_ea = (int *)mlx_get_data_addr(game->mlx_srct.r.xpm_ea,
			&img.bpp, &img.size_line, &img.endian);
	init_them(&game->mlx_srct);
}

void	get_right_pixel_p2(t_mlx *mlx_srct, int ofssety)
{
	if ((is_down(mlx_srct->rays.ray_angle))
		&& mlx_srct->r.wasverticallasttime == false)
		mlx_srct->r.color = mlx_srct->r.data_no + ((64 * ofssety)
				+ mlx_srct->r.offset);
	else if ((is_down(mlx_srct->rays.ray_angle))
		&& mlx_srct->r.wasverticallasttime == true
		&& is_right(mlx_srct->rays.ray_angle))
		mlx_srct->r.color = mlx_srct->r.data_we + ((64 * ofssety)
				+ mlx_srct->r.offset);
	else if ((is_down(mlx_srct->rays.ray_angle))
		&& mlx_srct->r.wasverticallasttime == true
		&& !is_right(mlx_srct->rays.ray_angle))
		mlx_srct->r.color = mlx_srct->r.data_ea + ((64 * ofssety)
				+ mlx_srct->r.offset);
}

void	get_right_pixel(t_mlx *mlx_srct, int ofssety)
{
	if ((!is_down(mlx_srct->rays.ray_angle))
		&& mlx_srct->r.wasverticallasttime == false)
		mlx_srct->r.color = mlx_srct->r.data_so \
		+ ((64 * ofssety) + mlx_srct->r.offset);
	else if ((!is_down(mlx_srct->rays.ray_angle))
		&& mlx_srct->r.wasverticallasttime == true
		&& is_right(mlx_srct->rays.ray_angle))
		mlx_srct->r.color = mlx_srct->r.data_we + ((64 * ofssety)
				+ mlx_srct->r.offset);
	else if ((!is_down(mlx_srct->rays.ray_angle))
		&& mlx_srct->r.wasverticallasttime == true
		&& !is_right(mlx_srct->rays.ray_angle))
		mlx_srct->r.color = mlx_srct->r.data_ea + ((64 * ofssety)
				+ mlx_srct->r.offset);
	else
		get_right_pixel_p2(mlx_srct, ofssety);
}

void	calculate_ofsset(t_mlx *mlx_srct)
{
	mlx_srct->r.distancefromtop = (int)(mlx_srct->r.y_wall
			+ (mlx_srct->r.wall_height / 2) - (HEIGHT / 2));
	mlx_srct->r.ofssety = (int)(mlx_srct->r.distancefromtop * ((float)64
				/ mlx_srct->r.wall_height));
}

void	cast_rays(t_mlx *mlx_srct, t_parce *game)
{
	int		column_id;

	load_xpm(game);
	column_id = 0;
	mlx_srct->rays.ray_angle = mlx_srct->plyr.rotate - (FOV_ANGLE / 2);
	while (column_id < WIDTH)
	{
		mlx_srct->rays.ray_angle = fmod(mlx_srct->rays.ray_angle, 2 * M_PI);
		if (mlx_srct->rays.ray_angle < 0)
			mlx_srct->rays.ray_angle += (2 * M_PI);
		make_them_false(game);
		mlx_srct->r.y_wall = mlx_srct->r.walltop;
		while (mlx_srct->r.y_wall < mlx_srct->r.wallbottom)
		{
			calculate_ofsset(mlx_srct);
			get_right_pixel(mlx_srct, mlx_srct->r.ofssety);
			img_pix_put(&mlx_srct->mlx_m, column_id, mlx_srct->r.y_wall,
				*mlx_srct->r.color);
			mlx_srct->r.y_wall++;
		}
		column_id++;
		mlx_srct->rays.ray_angle += (FOV_ANGLE / WIDTH);
	}
}
