/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:57:23 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 10:48:38 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

/*
           https://opengameart.org/content/64x-textures-an-overlays           
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
void	calculate_distances(t_mlx *mlx_srct, t_parce *game)
{
	double	correct_distance;

	correct_distance = mlx_srct->hited.distance_to_wall
		* cos(mlx_srct->rays.ray_angle - mlx_srct->plyr.rotate);
	// mlx_srct->hited.distance_to_wall = correct_distance;
	mlx_srct->hited.distbtwplr_and_plane = ((WIDTH / 2) / tan(FOV_ANGLE
				/ 2.00));
	mlx_srct->hited.projectedWallHeight = (int)((TILE_SIZE / correct_distance)
			* mlx_srct->hited.distbtwplr_and_plane);
	mlx_srct->hited.bottomOfWall = ((HEIGHT / 2)
			+ (mlx_srct->hited.projectedWallHeight) / 2);
	mlx_srct->hited.topOfWall = ((HEIGHT / 2)
			- mlx_srct->hited.projectedWallHeight / 2);
	if (mlx_srct->hited.topOfWall < 0 || mlx_srct->hited.topOfWall > HEIGHT)
		mlx_srct->hited.topOfWall = 0;
	if (mlx_srct->hited.bottomOfWall < 0 || mlx_srct->hited.topOfWall > HEIGHT)
		mlx_srct->hited.topOfWall = HEIGHT;
}
void	cast_rays(t_mlx *mlx_srct, t_parce *game)
{
	int		column_id;
	int		color;
	t_img	img;
	int		h;
	int		*h_ptr;
		int *c;
	int		y;
	int		distanceFromTop;
	int		ofssety;

	/********** texture **********/
	//read xpm file
	h = 64;
	h_ptr = &h;
	/* NORTH*/
	mlx_srct->hited.xpm_no = mlx_xpm_file_to_image(mlx_srct->mlx_ptr,game->no_path, h_ptr, h_ptr);
	mlx_srct->hited.data_no = (int *)mlx_get_data_addr(mlx_srct->hited.xpm_no,&img.bpp, &img.size_line, &img.endian);
	/* SOUTH*/
	mlx_srct->hited.xpm_so = mlx_xpm_file_to_image(mlx_srct->mlx_ptr,game->so_path, h_ptr, h_ptr);
	mlx_srct->hited.data_so = (int *)mlx_get_data_addr(mlx_srct->hited.xpm_so,&img.bpp, &img.size_line, &img.endian);
	/* WEST*/
	mlx_srct->hited.xpm_we = mlx_xpm_file_to_image(mlx_srct->mlx_ptr,game->we_path, h_ptr, h_ptr);
	mlx_srct->hited.data_we = (int *)mlx_get_data_addr(mlx_srct->hited.xpm_we,&img.bpp, &img.size_line, &img.endian);
	/* EAST*/
	mlx_srct->hited.xpm_ea = mlx_xpm_file_to_image(mlx_srct->mlx_ptr,game->ea_path, h_ptr, h_ptr);
	mlx_srct->hited.data_ea = (int *)mlx_get_data_addr(mlx_srct->hited.xpm_ea,&img.bpp, &img.size_line, &img.endian);
	/****************************/
	init_them(mlx_srct);
	mlx_srct->hited.distbtwplr_and_plane = 0;
	column_id = 0;
	mlx_srct->rays.ray_angle = mlx_srct->plyr.rotate - (FOV_ANGLE / 2);
	while (column_id < WIDTH)
	{
		mlx_srct->rays.ray_angle = fmod(mlx_srct->rays.ray_angle, 2 * M_PI);
		if (mlx_srct->rays.ray_angle < 0)
			mlx_srct->rays.ray_angle += (2 * M_PI);
		mlx_srct->hited.horhit = false;
		mlx_srct->hited.verhit = false;
		color = 0xCA8927;
		mlx_srct->hited.wasverticallasttime = false;
		mlx_srct->hited.hiitx = 0;
		mlx_srct->hited.hiity = 0;
		mlx_srct->hited.distance_to_wall = 0;
		put_rays(mlx_srct, mlx_srct->plyr.x, mlx_srct->plyr.y, game);
		// if (mlx_srct->hited.wasverticallasttime == true)
			// color = game->f_colo + 0x3916E6;
		calculate_distances(mlx_srct, game);
		y = mlx_srct->hited.topOfWall;
		while (y < mlx_srct->hited.bottomOfWall)
		{
			distanceFromTop = (int)(y + (mlx_srct->hited.projectedWallHeight	/ 2) - (HEIGHT / 2));
			ofssety = (int)(distanceFromTop * ((float)64/ mlx_srct->hited.projectedWallHeight));
			// printf("  offset x = %d ofssety = %d \n", mlx_srct->hited.offset, ofssety);
			if((!is_down(mlx_srct->rays.ray_angle )) &&  mlx_srct->hited.wasverticallasttime == false)
			{
				mlx_srct->hited.color = mlx_srct->hited.data_so + ((64 * ofssety)		+ mlx_srct->hited.offset);
				
			}
			else if((!is_down(mlx_srct->rays.ray_angle )) &&  mlx_srct->hited.wasverticallasttime == true && !is_right(mlx_srct->rays.ray_angle ))
			{
				mlx_srct->hited.color = mlx_srct->hited.data_we + ((64 * ofssety)		+ mlx_srct->hited.offset);
				
			}
			else if((!is_down(mlx_srct->rays.ray_angle )) &&  mlx_srct->hited.wasverticallasttime == true && is_right(mlx_srct->rays.ray_angle ))
			{
				mlx_srct->hited.color = mlx_srct->hited.data_ea + ((64 * ofssety)		+ mlx_srct->hited.offset);
				
			}
			else if((is_down(mlx_srct->rays.ray_angle )) &&  mlx_srct->hited.wasverticallasttime == false)
			{
				mlx_srct->hited.color = mlx_srct->hited.data_no + ((64 * ofssety)		+ mlx_srct->hited.offset);
				
			}
			// if(is_right(mlx_srct->rays.ray_angle ) && mlx_srct->hited.verhit == true)
			// {
			// 	colo = mlx_srct->hited.data_we + ((64 * ofssety)		+ mlx_srct->hited.offset);
				
			// }
			// else if(is_down(mlx_srct->rays.ray_angle ) && mlx_srct->hited.horhit == true)
			// {
			// 	colo = mlx_srct->hited.data_we + ((64 * ofssety)		+ mlx_srct->hited.offset);
				
			// }
			// else if(is_right(mlx_srct->rays.ray_angle ) && mlx_srct->hited.horhit == true)
			// {
			// 	colo = mlx_srct->hited.data_ea + ((64 * ofssety)		+ mlx_srct->hited.offset);	
			// }
			else
			mlx_srct->hited.color  = &color;
			img_pix_put(&mlx_srct->mlx_m, column_id, y, *mlx_srct->hited.color);
			y++;
		}
		// draw_it(column_id * WALL_STRIP_THIKNES, mlx_srct->hited.topOfWall,1,(mlx_srct->hited.bottomOfWall) + 1, color, mlx_srct);
		column_id++;
		mlx_srct->rays.ray_angle += (FOV_ANGLE / WIDTH);
	}
}
