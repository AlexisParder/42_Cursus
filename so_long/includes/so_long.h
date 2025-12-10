/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:10:01 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/10 10:46:38 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include <mlx.h>
# include <mlx_extended.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef TXT_PLAYER_R
#  define TXT_PLAYER_R "./textures/player/player_r.png"
# endif
# ifndef TXT_PLAYER_L
#  define TXT_PLAYER_L "./textures/player/player_l.png"
# endif
# ifndef TXT_PLAYER_T
#  define TXT_PLAYER_T "./textures/player/player_t.png"
# endif
# ifndef TXT_PLAYER_D
#  define TXT_PLAYER_D "./textures/player/player_d.png"
# endif
# ifndef TXT_PATH
#  define TXT_PATH "./textures/path.png"
# endif
# ifndef TXT_WALL
#  define TXT_WALL "./textures/wall.png"
# endif
# ifndef TXT_LOOT
#  define TXT_LOOT "./textures/loot.png"
# endif
# ifndef TXT_EXIT
#  define TXT_EXIT "./textures/exit.png"
# endif
# ifndef IMG_SIZE
#  define IMG_SIZE 64
# endif

typedef struct s_player_dt
{
	int			size;
	size_t		pos_x;
	size_t		pos_y;
	size_t		loot_collected;
	size_t		nb_move;
	char		last_move;
}	t_player_dt;

typedef struct s_map_dt
{
	char	**map;
	size_t	x_max;
	size_t	y_max;
	size_t	x_exit;
	size_t	y_exit;
	size_t	total_loots;
}	t_map_dt;

typedef struct s_map_ck
{
	char	**map;
	int		exit_found;
	size_t	loot_found;
}	t_map_ck;

typedef struct s_imgs_ref
{
	mlx_image	pl_d;
	mlx_image	pl_l;
	mlx_image	pl_r;
	mlx_image	pl_t;
	mlx_image	exit;
	mlx_image	loot;
	mlx_image	path;
	mlx_image	wall;
}	t_imgs_ref;

typedef struct s_mlx_dt
{
	mlx_window		win;
	mlx_context		mlx;
	int				key_pressed;
	t_imgs_ref		img_ref;
	t_player_dt		*player;
	t_map_dt		map;
}	t_mlx_dt;

int			check_move(t_mlx_dt *mlx_data, char move);
int			check_map(t_map_dt *map);
int			check_map_path(t_map_dt *map);
int			is_search(char c, char *search);

void		add_img_pl(t_mlx_dt *dt, mlx_image img, size_t pos_x, size_t pos_y);
void		add_image(t_mlx_dt *dt, mlx_image img, size_t pos_x, size_t pos_y);
void		make_move(t_mlx_dt *mlx_data, char move);
void		redraw_window(t_mlx_dt *mlx_data);
void		updt_pl(t_mlx_dt *mlx_data);
void		destroy_images(t_mlx_dt *mlx_data);
void		creates_images(t_mlx_dt *dt, t_map_dt *map_dt);
void		clean_all(t_mlx_dt mlx_data);
void		create_map_dt(t_mlx_dt *mlx_data, char **av);
void		display_move(t_mlx_dt *mlx_data);

char		*sl_strjoin(char *s1, char *s2);

size_t		get_max_x(char **map);
size_t		get_max_y(char **map);
size_t		get_total_loots(char **map);
size_t		count_type(char **map, char *search);

char	*new_get_next_line(int fd);

#endif