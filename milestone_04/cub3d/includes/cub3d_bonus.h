/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:17:10 by tjourdai          #+#    #+#             */
/*   Updated: 2026/05/08 14:38:50 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <libft.h>
# include <mathft.h>
# include <fcntl.h>
# include <mlx.h>
# include <mlx_extended.h>
# include <stdio.h>
# include <sys/time.h>

# define TEX_FL_ON "./textures/flashlight/flashlight_on.png"
# define TEX_FL_OFF "./textures/flashlight/flashlight_off.png"
# define TEX_REC_ON "./textures/ath/rec_on.png"
# define TEX_REC_OFF "./textures/ath/rec_off.png"
# define TEX_B_0 "./textures/ath/b_0.png"
# define TEX_B_1 "./textures/ath/b_1.png"
# define TEX_B_2 "./textures/ath/b_2.png"
# define TEX_B_3 "./textures/ath/b_3.png"
# define TEX_B_4 "./textures/ath/b_4.png"
# define TEX_B_5 "./textures/ath/b_5.png"
# define SPRITE_DELAY 500

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define INT_FONT "/usr/share/fonts/truetype/crosextra/Carlito-Bold.ttf"
# define INT_FONT_SIZE 32

# define M_PI 3.14159265358979323846
# define MOVE_SPEED 0.05
# define ROT_SPEED  0.03

# define MOUSE_SENS_MIN  0.0001
# define MOUSE_SENS_MAX  0.01

# define FOG_DIST 8.0

# define COLL_FREE			0
# define COLL_WALL			1
# define COLL_DOOR_CLOSED	2
# define COLL_DOOR_OPEN		3

# define MIN_FOV 50
# define MAX_FOV 130

# define MIN_BRIGHT 20

# define KEY_W 26
# define KEY_S 22
# define KEY_A 4
# define KEY_D 7
# define KEY_LEFT 80
# define KEY_RIGHT 79
# define KEY_TAB 43
# define KEY_F 9
# define KEY_Q 20
# define KEY_E 8
# define KEY_R 21
# define KEY_SHIFT 225
# define KEY_SPACE 44
# define KEY_CTRL 224

# define JUMP_CROUCH_GRAVITY 2.2

# define M_CELL_SIZE 8
# define M_MARGIN 10
# define M_SIZE 200
# define M_BORDER 2

typedef struct s_fps
{
	long	last_time_ms;
	int		frame_count;
	int		fps;
}	t_fps;

typedef struct s_minimap
{
	int	ox;
	int	oy;
	int	start_x;
	int	start_y;
	int	cells_x;
	int	cells_y;
	int	map_x;
	int	map_y;
}	t_minimap;

typedef enum e_button_type
{
	BUTTON_KEY,
	BUTTON_SLIDER
}	t_button_type;

typedef struct s_data	t_data;

typedef struct s_click_args
{
	void	*val;
	t_data	*data;
	int		index;
}	t_click_args;

typedef struct s_button
{
	int				x;
	int				y;
	int				w;
	int				h;
	char			*label;
	char			*key;
	t_button_type	type;
	int				index;
	float			value;
	void			(*on_click)(t_click_args *);
}	t_button;

typedef struct s_player
{
	t_vec3	pos;
	t_vec2	dir;
	t_vec2	plane;
	double	pitch;
	double	z;
	double	z_vel;
	int		jumping;
	double	bob_phase;
	double	bob_offset;
}	t_player;

typedef struct s_img_dt
{
	mlx_image	tex;
	int			w;
	int			h;
	int			has_transparency;
	uint32_t	*pixels;
}	t_img_dt;

typedef struct s_imgs_ref
{
	t_img_dt	wall_n;
	t_img_dt	wall_s;
	t_img_dt	wall_e;
	t_img_dt	wall_w;
	t_img_dt	door_c;
	t_img_dt	door_o;
	t_img_dt	fl_on;
	t_img_dt	fl_off;
	t_img_dt	rec_on;
	t_img_dt	rec_off;
	t_img_dt	b_0;
	t_img_dt	b_1;
	t_img_dt	b_2;
	t_img_dt	b_3;
	t_img_dt	b_4;
	t_img_dt	b_5;
}	t_imgs_ref;

typedef struct s_parse_map
{
	int	tex_n_view;
	int	tex_s_view;
	int	tex_e_view;
	int	tex_w_view;
	int	tex_do_view;
	int	tex_dc_view;
	int	cl_c_view;
	int	cl_f_view;
	int	cl_i_view;
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
	char	hit_tile;
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

typedef struct s_tile
{
	int		x;
	int		y;
	char	type;
}	t_tile;

typedef struct s_settings
{
	int		fov;
	float	mouse_sensitivity;
	int		brightness;
	int		key_forward;
	int		key_backward;
	int		key_left;
	int		key_right;
}	t_settings;

typedef struct s_set_color
{
	mlx_color	bg;
	mlx_color	key_bg;
	mlx_color	white;
	mlx_color	fill;
}	t_set_color;

struct s_data
{
	mlx_window		win;
	mlx_context		mlx;
	size_t			win_w;
	size_t			win_h;
	t_settings		settings;
	char			**map;
	size_t			map_cols;
	size_t			map_rows;
	t_player		player;
	char			*tex_n;
	char			*tex_s;
	char			*tex_e;
	char			*tex_w;
	char			*tex_do;
	char			*tex_dc;
	mlx_color		cl_ceiling;
	mlx_color		cl_floor;
	mlx_color		cl_interact;
	int				pause;
	t_imgs_ref		imgs;
	int				redraw;
	int				keys[512];
	int				old_keys[512];
	mlx_color		*framebuffer;
	char			*coll_map;
	int				draw_fps;
	int				interact_door;
	int				has_door;
	t_tile			tile_front;
	t_button		*buttons;
	int				buttons_count;
	t_fps			fps;
	int				dragging;
	int				drag_idx;
	int				change_key;
	mlx_image		global_img;
	int				flashlight;
	float			battery;
	t_set_color		colors;
};

void		init_player_plane(t_data *data, int fov);
void		init_window(t_data *data);
void		init_data(t_data *data);
void		init_imgs(t_data *dt);
void		init_sprites(t_data *dt);
void		init_collision(t_data *data);

void		check_map_format(char *map_path);
void		check_map(t_data *data);
int			check_img_format(char *key, char *img);
int			str_has_space(char *str);
void		free_get_next_line(char *line, int fd);
void		free_data_params(t_data *data);
int			file_exists(const char *path, int print_err);

void		check_transparency(t_data *dt, t_img_dt *img);

int			manage_param(t_data *data, t_parse_map *dt_parse,
				char **split_line);
int			parse_line(t_data *data, t_parse_map *dt_parse, char *line,
				char **map);
void		parse_map(t_data *data, char *map_path);
int			manage_color(t_data *data, t_parse_map *dt_parse,
				char **split_line);
char		**get_split_line(char *line);
int			handle_param_or_color(t_data *data, t_parse_map *dt_parse,
				char ***split_line);
int			handle_map_line(char **split_line, char **map,
				t_parse_map *dt_parse);
int			check_duplicated_color(int viewed, char color_char);

void		init_player(t_data *data);
void		init_mlx(t_data *data);
void		close_game(t_data *data, int status);
void		raycasting(t_data *data);
void		actions(t_data *data);
mlx_color	apply_fog(t_data *data, mlx_color color, double dist);
mlx_color	apply_brightness(t_data *data, mlx_color color);
mlx_color	get_pixel(t_img_dt img, int x, int y);
int			get_tex_x(t_data *data, t_ray *ray, t_img_dt img, t_draw *draw);

void		update_collision_tile(t_data *data, int x, int y);
int			is_blocked(t_data *data, double nx, double ny);

void		move_forward_back(t_data *data, int key);
void		move_strafe(t_data *data, int key);
void		rotate(t_data *data, double angle);
void		actions_jump_crouch(t_data *data);

double		calc_delta(double ray_dir);
void		calc_step_side(t_ray *ray, t_player *pl);
void		dda(t_ray *ray, char **map, int dda_continue);
t_img_dt	get_img(t_data *data, t_ray *ray);

void		draw_column_behind(t_data *data, t_draw *draw,
				t_ray *ray, size_t x);
void		draw_column(t_data *data, t_draw *draw, t_ray *ray, size_t x);

void		key_hook(int key, void *param);
void		key_up_hook(int key, void *param);
void		window_hook(int event, void *param);

void		register_sl_btn(t_data *data);
void		draw_button(t_data *data, t_button *btn);
void		draw_settings(t_data *data);
void		mouse_click_hook(int button, void *param);
void		mouse_release_hook(int button, void *param);
void		update_sliders(t_data *data);
int			key_is_bindable(t_data *data, int key);
const char	*mbx_key_from_id(int key);

void		fps_init(t_fps *fps);
void		fps_update(t_data *data);

void		draw_minimap(t_data *data);
void		draw_minimap_cells(t_data *data, t_minimap *m_dt);

void		manage_sprites(t_data *data);

long		get_time_ms(void);

void		cache_imgs(t_data *dt);
void		cache_sprites(t_data *dt);

void		change_key_bind(t_data *data, int key);
void		change_keys(t_click_args *element);
void		change_fov(t_click_args *element);
void		change_brightness(t_click_args *element);
void		change_mouse_sensitivity(t_click_args *element);

void		set_save_settings(t_data *data);
void		init_color(t_data *data);
void		draw_slider_button(t_data *data, t_button *btn);

void		save_settings_in_file(t_data *data);
void		apply_flashlight(t_data *data);

void		destroy_sprites(t_data *data);

void		set_saved_value(t_data *data, char *line);

#endif