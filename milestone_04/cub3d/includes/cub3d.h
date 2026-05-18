/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:17:10 by tjourdai          #+#    #+#             */
/*   Updated: 2026/05/07 10:23:10 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <mathft.h>
# include <fcntl.h>
# include <mlx.h>
# include <mlx_extended.h>
# include <stdio.h>

# define FOV 90
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

# define M_PI 3.14159265358979323846
# define MOVE_SPEED 0.05
# define ROT_SPEED  0.03

# define KEY_W 26
# define KEY_S 22
# define KEY_A 4
# define KEY_D 7
# define KEY_LEFT 80
# define KEY_RIGHT 79

typedef struct s_player
{
	t_vec3	pos;
	t_vec2	dir;
	t_vec2	plane;
}	t_player;

typedef struct s_img_dt
{
	mlx_image	tex;
	int			w;
	int			h;
}	t_img_dt;

typedef struct s_imgs_ref
{
	t_img_dt	wall_n;
	t_img_dt	wall_s;
	t_img_dt	wall_e;
	t_img_dt	wall_w;
}	t_imgs_ref;

typedef struct s_parse_map
{
	int	tex_n_view;
	int	tex_s_view;
	int	tex_e_view;
	int	tex_w_view;
	int	cl_c_view;
	int	cl_f_view;
}	t_parse_map;

typedef struct s_ray
{
	t_vec2	dir;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_draw
{
	double	perp_wall_dist;
	int		line_h;
	int		start;
	int		end;
}	t_draw;

typedef struct s_draw_w
{
	t_img_dt	img;
	int			tex_x;
	double		step;
}	t_draw_w;

typedef struct s_data
{
	mlx_window	win;
	mlx_context	mlx;
	size_t		win_w;
	size_t		win_h;
	int			fov;
	char		**map;
	size_t		map_cols;
	size_t		map_rows;
	t_player	player;
	char		*tex_n;
	char		*tex_s;
	char		*tex_e;
	char		*tex_w;
	mlx_color	cl_ceiling;
	mlx_color	cl_floor;
	t_imgs_ref	imgs;
	int			redraw;
	int			keys[512];
	int			old_keys[512];
	mlx_color	*framebuffer;
}	t_data;

void		init_window(t_data *data);
void		init_data(t_data *data);
void		init_imgs(t_data *dt);

void		check_map_format(char *map_path);
void		check_map(t_data *data);
int			check_img_format(char *key, char *img);
int			str_has_space(char *str);
void		free_get_next_line(char *line, int fd);
void		free_data_params(t_data *data);

int			manage_param(t_data *data, t_parse_map *dt_parse,
				char **split_line);
void		parse_map(t_data *data, char *map_path);
int			manage_color(t_data *data, t_parse_map *dt_parse,
				char **split_line);
char		**get_split_line(char *line);
int			handle_param_or_color(t_data *data, t_parse_map *dt_parse,
				char ***split_line);
int			handle_map_line(char **split_line, char **map,
				t_parse_map *dt_parse);

void		init_player(t_data *data);
void		init_mlx(t_data *data);
void		close_game(t_data *data, int status);
void		raycasting(t_data *data);
void		actions(t_data *data);

double		calc_delta(double ray_dir);
void		calc_step_side(t_ray *ray, t_player *pl);
void		dda(t_ray *ray, char **map);
t_img_dt	get_img(t_data *data, t_ray *ray);

void		draw_column(t_data *data, t_draw *draw, t_ray *ray, size_t x);

#endif
