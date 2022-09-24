/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:43:45 by mhanda            #+#    #+#             */
/*   Updated: 2022/09/24 05:31:56 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "mlx.h"
# include <math.h>
# define TILE_SIZE 32
# define WIDTH 480
# define HEIGHT 352
# define MOVE_SPEED 0.1
# define FOV_ANGLE 60 * (M_PI / 180)
# define WALL_STRIP_THIKNES 1
# define NUM_RAYS (WIDTH / WALL_STRIP_THIKNES)

typedef struct s_ray
{
	double	ray_angle;
} t_ray;


typedef struct s_player
{
	double	x;
	double	y;
	double	rotate;
	double	right_or_left;
	double	walk_direction;
	double	turn_direction;
	double	rotaion_speed;
	double	move_speed;
} t_player;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			des_remind;
	t_ray		rays;
	t_player	plyr;
	t_img		mlx_m;
} t_mlx;

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
} t_map;

typedef struct s_norm_help
{
  int	no_count;
  int	so_count;
  int	ea_count;
  int	we_count;
  int	no_index;
  int	so_index;
  int	ea_index;
  int	we_index;
  int	f_count;
  int	f_index;
  int	c_count;
  int	c_index;
} t_norm_help;

typedef struct s_rbg
{
	int r;
	int b;
	int g;
} t_rgb;
 
typedef struct s_parce
{
	char    *no_path;
	char    *so_path;
	char    *we_path;
	char    *ea_path;
	char	*c_color;
	char	*f_color;
	char	**parced_map;
	char	*map_lin;
	int		c_colo;
	int		f_colo;
	t_rgb     f;
	t_rgb     c;
	t_norm_help compas_count;
	t_mlx 		mlx_srct;
	int		check_min_max;
} t_parce;

void	paint_rays(t_mlx *mlx_srct, t_parce *game);
void	img_pix_put(t_img *img, int x, int y, int color);
void	paint_p_line(t_mlx *mlx_srct, double x, double y);
void	paint_player(t_mlx *mlx_srct, double x, double y);
void    make_texturs(t_parce *game_map);
void	paint_mini_map(t_mlx *mlx_srct, t_parce *game_map);
void	paint_garound(t_mlx *mlx_srct, t_parce *game_map, double x, double y);
void	paint_walls(t_mlx *mlx_srct, t_parce *game_map, double x, double y);
void	handl_player(t_parce *game_map, t_mlx *mlx_srct);
void	graphics_handle(t_parce *game_map);
void	parce_map(char *map_line, t_parce *paths_rgb);
void    map_error(char **tab, t_parce *paths_rgb);
void	free_s_parced_map(t_map *ptr);
void	check_map_conditions(t_map *node, t_parce *paths_rgb);
void	check_map_conditions_two(t_map *node, t_parce *paths_rgb);
void	free_parced_map(t_map *ptr);
void	check_new_lines(t_map *node, t_parce *paths_rgb);
void	ft_free_leaked_parced_map(char **parced_map);
void    free_textur_paths(t_parce *paths_rgb);
void	check_digit(t_parce *paths_rgb);
void	continu_get_correct_path(t_parce *paths_rgb);
void	get_correct_path(t_parce *paths_rgb);
void	check_valid_color(char **parced_map, t_parce *paths_rgb);
void	handl_color(char **parced_map, t_parce *paths_rgb);
void    extract_check_path(t_parce *paths_rgb);
void	ft_free_parced_map(char **parced_map);
void    init_map_struct(t_parce *paths_rgb);
void	*ft_memset(void *str, int c, size_t len);
void    ft_put_error(char *str);
void	handl_player_case(char **tab, int x, int y, int len, t_parce *paths_rgb);
void	handl_zero_case(char **tab, int x, int y, int len, t_parce *paths_rgb);
char	**check_map_holes(t_map *node, t_parce *paths_rgb);
char	**field_by_space(char **tab);
char	**make_square_map(int x, int y);
char	**list_to_tab(t_map *node);
char	*ft_strndup(char *src, int n);
char	**ft_split(char *s, char c);
char    *read_map(int fd);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strstr(const char *s, const char *tofind);
char	**handl_map(char **parced_map, t_parce *paths_rgb);
int		mlx_key_press(int preced_key, t_parce *game);
int		check_wall(t_parce *game, double new_x, double new_y);
int		mlx_key_releas(int preced_key, t_parce *game);
int		mlx_x_key_han();
int		count_max_len(char **tab);
int		count_tab_len(char **node);
int		ft_isdigit(int c);
int		ft_atoi(char *str, t_parce *paths_rgb);
int		ft_strstr_custom(const char *s, const char *tofind);
int	    wdc(char const *s, char c);
int     ft_strlen(char *c);
int     ft_strcmp(char *s1, char *s2);

#endif
