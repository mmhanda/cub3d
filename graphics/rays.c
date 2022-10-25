/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:57:23 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 15:15:26 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

/*
							Actual Slice Height
Projected Slice Height= --------------------- * Distance to Projection Plane
                        Distance to the Slice  

						//bottomOfWall  = plane center  + projected Wall Height
//topOfWall  = plane center   - projected Wall Height
						// printf("mlx_srct->hited.distance_to_wall fasle= 
								%f\n",mlx_srct->hited.distance_to_wall);
						
// printf("mlx_srct->hited.distance_to_wall correct   = 
		%f\n",mlx_srct->hited.distance_to_wall);


// printf(" mlx_srct->hited.projectedWallHeight is %f\n",
		mlx_srct->hited.projectedWallHeight);
// printf(" mlx_srct->hited.distbtwplr_and_plane is %f\n",
		mlx_srct->hited.distbtwplr_and_plane );
// printf("mlx_srct->hited.bottomOfWall t is
		%d\n",mlx_srct->hited.bottomOfWall );
// printf(" mlx_srct->hited.topOfWall %d\n", mlx_srct->hited.topOfWall  );
*/

void	load_xpm(t_img img, t_parce *game)
{
	int	h;
	int	*h_ptr;

	h = 64;
	h_ptr = &h;
	game->mlx_srct.hited.xpm_no = mlx_xpm_file_to_image(game->mlx_srct.mlx_ptr,
														game->no_path,
														h_ptr,
														h_ptr);
	game->mlx_srct.hited.data_no = (int *)mlx_get_data_addr(game->mlx_srct.hited.xpm_no,
															&img.bpp,
															&img.size_line,
															&img.endian);
	game->mlx_srct.hited.xpm_so = mlx_xpm_file_to_image(game->mlx_srct.mlx_ptr,
														game->so_path,
														h_ptr,
														h_ptr);
	game->mlx_srct.hited.data_so = (int *)mlx_get_data_addr(game->mlx_srct.hited.xpm_so,
															&img.bpp,
															&img.size_line,
															&img.endian);
	game->mlx_srct.hited.xpm_we = mlx_xpm_file_to_image(game->mlx_srct.mlx_ptr,
														game->we_path,
														h_ptr,
														h_ptr);
	game->mlx_srct.hited.data_we = (int *)mlx_get_data_addr(game->mlx_srct.hited.xpm_we,
															&img.bpp,
															&img.size_line,
															&img.endian);
	game->mlx_srct.hited.xpm_ea = mlx_xpm_file_to_image(game->mlx_srct.mlx_ptr,
														game->ea_path,
														h_ptr,
														h_ptr);
	game->mlx_srct.hited.data_ea = (int *)mlx_get_data_addr(game->mlx_srct.hited.xpm_ea,
															&img.bpp,
															&img.size_line,
															&img.endian);
	init_them(&game->mlx_srct);
}

void	get_right_pixel_p2(t_mlx *mlx_srct, t_parce *game, int ofssety)
{
	if ((is_down(mlx_srct->rays.ray_angle))
		&& mlx_srct->hited.wasverticallasttime == false)
		mlx_srct->hited.color = mlx_srct->hited.data_no + ((64 * ofssety)
				+ mlx_srct->hited.offset);
	else if ((is_down(mlx_srct->rays.ray_angle))
			&& mlx_srct->hited.wasverticallasttime == true
			&& is_right(mlx_srct->rays.ray_angle))
		mlx_srct->hited.color = mlx_srct->hited.data_we + ((64 * ofssety)
				+ mlx_srct->hited.offset);
	else if ((is_down(mlx_srct->rays.ray_angle))
			&& mlx_srct->hited.wasverticallasttime == true
			&& !is_right(mlx_srct->rays.ray_angle))
		mlx_srct->hited.color = mlx_srct->hited.data_ea + ((64 * ofssety)
				+ mlx_srct->hited.offset);
}

void	get_right_pixel(t_mlx *mlx_srct, t_parce *game, int ofssety)
{
	if ((!is_down(mlx_srct->rays.ray_angle))
		&& mlx_srct->hited.wasverticallasttime == false)
		mlx_srct->hited.color = mlx_srct->hited.data_so + ((64 * ofssety)
				+ mlx_srct->hited.offset);
	else if ((!is_down(mlx_srct->rays.ray_angle))
			&& mlx_srct->hited.wasverticallasttime == true
			&& is_right(mlx_srct->rays.ray_angle))
		mlx_srct->hited.color = mlx_srct->hited.data_we + ((64 * ofssety)
				+ mlx_srct->hited.offset);
	else if ((!is_down(mlx_srct->rays.ray_angle))
			&& mlx_srct->hited.wasverticallasttime == true
			&& !is_right(mlx_srct->rays.ray_angle))
		mlx_srct->hited.color = mlx_srct->hited.data_ea + ((64 * ofssety)
				+ mlx_srct->hited.offset);
	else
		get_right_pixel_p2(mlx_srct, game, ofssety);
}

void	calculate_ofsset(t_mlx *mlx_srct)
{
	mlx_srct->hited.distanceFromTop = (int)(mlx_srct->hited.y_wall
			+ (mlx_srct->hited.projectedWallHeight / 2) - (HEIGHT / 2));
	mlx_srct->hited.ofssety = (int)(mlx_srct->hited.distanceFromTop * ((float)64
				/ mlx_srct->hited.projectedWallHeight));
}

void	cast_rays(t_mlx *mlx_srct, t_parce *game)
{
	int		column_id;
	t_img	img;

	load_xpm(img, game);
	column_id = 0;
	mlx_srct->rays.ray_angle = mlx_srct->plyr.rotate - (FOV_ANGLE / 2);
	while (column_id < WIDTH)
	{
		mlx_srct->rays.ray_angle = fmod(mlx_srct->rays.ray_angle, 2 * M_PI);
		if (mlx_srct->rays.ray_angle < 0)
			mlx_srct->rays.ray_angle += (2 * M_PI);
		make_them_false(game);
		mlx_srct->hited.y_wall = mlx_srct->hited.topOfWall;
		while (mlx_srct->hited.y_wall < mlx_srct->hited.bottomOfWall)
		{
			calculate_ofsset(mlx_srct);
			get_right_pixel(mlx_srct, game, mlx_srct->hited.ofssety);
			img_pix_put(&mlx_srct->mlx_m, column_id, mlx_srct->hited.y_wall,
					*mlx_srct->hited.color);
			mlx_srct->hited.y_wall++;
		}
		column_id++;
		mlx_srct->rays.ray_angle += (FOV_ANGLE / WIDTH);
	}
}
