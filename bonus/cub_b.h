/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_b.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:43:45 by mhanda            #+#    #+#             */
/*   Updated: 2022/10/25 23:58:33 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_B_H
# define CUB_B_H

# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define TILE_SIZE 64
# define WIDTH 1080
# define HEIGHT 720
# define MOVE_SPEED 0.3
# define FOV_ANGLE 1.04719755

typedef struct s_hit
{
	double			yintercept;
	double			xintercept;
	double			ystep;
	double			xstep;
	double			y_map_grid;
	double			x_map_grid;
	double			wallhitx;
	double			wallhity;
	double			x_to_check;
	double			y_to_check;
	double			nexthorztouchx;
	double			nexthorztouchy;
	double			horx;
	double			hory;
	double			verx;
	double			very;
	double			tmpx;
	double			tmpy;
	int				mapindex_x;
	int				mapindex_y;
	void			*mlx_ptr;
	void			*mlx_win;
	int				walltop;
	int				wallbottom;
	double			planeycenter;
	double			distance_to_wall;
	int				wall_height;
	bool			wasverticallasttime;
	double			hordistance;
	double			verdistance;
	double			hiitx;
	double			hiity;
	bool			horhit;
	double			distbtwplr_and_plane;
	bool			verhit;
	int				*data_no;
	int				*data_so;
	int				*data_we;
	int				*data_ea;
	int				distancefromtop;
	void			*xpm_no;
	void			*xpm_so;
	void			*xpm_we;
	void			*xpm_ea;
	int				*color;
	int				offset;
	int				ofssety;
	int				y_wall;
}					t_hit;

typedef struct s_ray
{
	double			ray_angle;
}					t_ray;

typedef struct s_player
{
	double			x;
	double			y;
	double			rotate;
	double			right_or_left;
	double			walk_direction;
	double			turn_direction;
	double			rotaion_speed;
	double			move_speed;
}					t_player;

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_mini_map
{
	double			p_x;
	double			p_y;
	double			var_1;
	double			var_2;
	int				weigth;
	int				high;
	int				j;
	int				i;
}					t_mini_map;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				des_remind;
	int				tab_len;
	int				longest_line;
	t_ray			rays;
	t_player		plyr;
	t_img			mlx_m;
	t_hit			r;
	t_mini_map		mini;
	t_img			*img;

}					t_mlx;

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

typedef struct s_norm_help
{
	int				no_count;
	int				so_count;
	int				ea_count;
	int				we_count;
	int				no_index;
	int				so_index;
	int				ea_index;
	int				we_index;
	int				f_count;
	int				f_index;
	int				c_count;
	int				c_index;
}					t_norm_help;

typedef struct s_rbg
{
	int				r;
	int				b;
	int				g;
}					t_rgb;

typedef struct s_parce
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*c_color;
	char			*f_color;
	char			**parced_map;
	char			*map_lin;
	int				c_colo;
	int				f_colo;
	t_rgb			f;
	t_rgb			c;
	t_norm_help		compas_count;
	t_mlx			mlx_srct;
	int				check_min_max;
}					t_parce;
double				distancebetween2_points(float x1, float y1, float x2,
						float y2);
void				check_horizontal_intersections(t_mlx *mlx_srct, double x,
						double y, t_parce *game);
bool				is_right(double angle_in_radian);
bool				is_down(double angle_in_radian);
void				y_x_horizontal(t_mlx *mlx_srct, double x, double y);
void				y_x_vertical(t_mlx *mlx_srct, double x, double y);
int					check_wall_2(t_parce *game, double new_x, double new_y);
void				nearest_point(t_mlx *mlx_srct, double x, double y);
void				draw_floor(t_parce *game_map);
void				draw_ceilling(t_parce *game_map);
void				init_them(t_mlx *mlx_srct);
void				wall_found_hor(t_mlx *mlx_srct);
void				wall_found_ver(t_mlx *mlx_srct);
void				load_xpm(t_parce *game);
void				get_right_pixel(t_mlx *mlx_srct, int ofssety);
void				get_right_pixel_p2(t_mlx *mlx_srct, int ofssety);
void				make_them_false(t_parce *game);
void				calculate_ofsset(t_mlx *mlx_srct);
void				calculate_distances(t_mlx *mlx_srct);
void				check_xpm(t_parce *paths_rgb);
void				convert_color_to_int(t_parce *paths_rgb, char ***c,
						char ***f);
void				put_rays(t_mlx *mlx_srct, double x, double y,
						t_parce *game);
void				cast_rays(t_mlx *mlx_srct, t_parce *game);
void				img_pix_put(t_img *img, int x, int y, int color);
void				paint_player(t_mlx *mlx_srct, double x, double y);
void				make_texturs(t_parce *game_map);
void				paint_mini_map(t_mlx *mlx_srct, t_parce *game_map);
void				paint_ground(t_mlx *mlx_srct, t_parce *game_map, double x,
						double y);
void				paint_walls(t_mlx *mlx_srct, t_parce *game_map, double x,
						double y);
void				handl_player(t_parce *game_map, t_mlx *mlx_srct);
void				graphics_handle(t_parce *game_map);
void				parce_map(char *map_line, t_parce *paths_rgb);
void				map_error(char **tab, t_parce *paths_rgb);
void				free_s_parced_map(t_map *ptr);
void				check_map_conditions(t_map *node, t_parce *paths_rgb);
void				check_map_conditions_two(t_map *node, t_parce *paths_rgb);
void				free_parced_map(t_map *ptr);
void				check_new_lines(t_map *node, t_parce *paths_rgb);
void				ft_free_leaked_parced_map(char **parced_map);
void				free_textur_paths(t_parce *paths_rgb);
void				check_digit(t_parce *paths_rgb);
void				continu_get_correct_path(t_parce *paths_rgb);
void				get_correct_path(t_parce *paths_rgb);
void				check_valid_color(char **parced_map, t_parce *paths_rgb);
void				handl_color(char **parced_map, t_parce *paths_rgb);
void				extract_check_path(t_parce *paths_rgb);
void				ft_free_parced_map(char **parced_map);
void				init_map_struct(t_parce *paths_rgb);
void				*ft_memset(void *str, int c, size_t len);
void				ft_put_error(char *str);
void				handl_player_case(char **tab, int x, int y,
						t_parce *paths_rgb);
void				handl_zero_case(char **tab, int x, int y,
						t_parce *paths_rgb);
char				*ft_strdup(char *s1);
char				*ft_substr(char *s, int start, int len);
char				**check_map_holes(t_map *node, t_parce *paths_rgb);
char				**field_by_space(char **tab, t_parce *paths_rgb);
char				**make_square_map(int x, int y);
char				**list_to_tab(t_map *node);
char				*ft_strndup(char *src, int n);
char				**ft_split(char *s, char c);
char				*read_map(int fd);
char				*ft_strdup(char *str);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strstr(const char *s, const char *tofind);
char				**handl_map(char **parced_map, t_parce *paths_rgb);
int					mlx_key_press(int preced_key, t_parce *game);
int					check_wall(t_parce *game, double new_x, double new_y);
int					mlx_key_releas(int preced_key, t_parce *game);
int					mlx_x_key_han(void);
int					count_max_len(char **tab);
int					count_tab_len(char **node);
int					ft_isdigit(int c);
int					ft_atoi(char *str, t_parce *paths_rgb);
int					ft_strstr_cust(const char *s, const char *tofind);
int					wdc(char const *s, char c);
int					ft_strlen(char *c);
int					ft_strcmp(char *s1, char *s2);

#endif
