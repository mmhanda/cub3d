/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:57:23 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/24 10:38:44 by atabiti          ###   ########.fr       */
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
void	paint_rays(t_mlx *mlx_srct, t_parce *game)
{
	int	column_id;
	int		color;
/********** texture **********/
t_img img;
img.endian = 0;
img.bpp = 32;
//read xpm file 
int h = 32;
int *h_ptr = & h;
//  img.addr =   mlx_get_data_addr( mlx_xpm_file_to_image(mlx_srct->mlx_ptr,"./textur/walld.xpm",h_ptr, h_ptr),&img.bpp,&img.size_line, &img.endian);
// void *img_xpm = mlx_xpm_file_to_image(mlx_srct->mlx_ptr,"./textur/wall2.xpm",h_ptr, h_ptr);
void *img_xpm = mlx_xpm_file_to_image(mlx_srct->mlx_ptr,"./textur/wall2.xpm",h_ptr, h_ptr);
img.addr= mlx_get_data_addr(img_xpm,&img.bpp, &img.size_line, &img.endian);
// printf("color  =  %x\n ",(int  )img.addr +1);

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
		color = game->c_colo + 0xCA8927;
		mlx_srct->hited.wasverticallasttime = false;
		mlx_srct->hited.hiitx = 0;
		mlx_srct->hited.hiity = 0;
		mlx_srct->hited.distance_to_wall = 0;
		put_rays(mlx_srct, mlx_srct->plyr.x, mlx_srct->plyr.y, game);
		// if (mlx_srct->hited.wasverticallasttime == true)
		// 	color = game->f_colo + 0x3916E6;
		calculate_distances(mlx_srct, game);
		int	ff;
		int *c;
		int iter = 0;
	// c =  (int*)(img.addr + (iter));
	ff =  mlx_srct->hited.topOfWall;
	int yy = 0;
	while (ff < (mlx_srct->hited.bottomOfWall) + 1)
	{
		c =  (int*)(img.addr + ((yy % 32 )) * column_id);
		img_pix_put(&mlx_srct->mlx_m, column_id, ff, *c);
		yy++;
		ff++;

	}
	printf("mlx_srct->hited.offset  %d \n",  mlx_srct->hited.offset );
		// draw_it(column_id * WALL_STRIP_THIKNES, mlx_srct->hited.topOfWall, 1,(mlx_srct->hited.bottomOfWall) + 1, color, mlx_srct);
		column_id++;
		mlx_srct->rays.ray_angle += (FOV_ANGLE / WIDTH);
	}
}
