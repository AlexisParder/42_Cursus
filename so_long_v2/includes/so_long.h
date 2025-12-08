/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:10:01 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/08 12:51:27 by achauvie         ###   ########.fr       */
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

typedef struct s_img_dt
{
	int				size;
	size_t			pos_x;
	size_t			pos_y;
	struct s_img_dt	*img_next;
	struct s_img_dt	*img_prev;
}	t_img_dt;

typedef struct s_loots_dt
{
	int					size;
	int					is_looted;
	size_t				pos_x;
	size_t				pos_y;
	struct s_loots_dt	*loot_next;
	struct s_loots_dt	*loot_prev;
}	t_loot_dt;

typedef struct s_player_dt
{
	int			size;
	size_t		pos_x;
	size_t		pos_y;
	size_t		loot_collected;
	size_t		nb_move;
}	t_player_dt;

typedef struct s_map_dt
{
	char	**map;
	size_t	x_max;
	size_t	y_max;
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
	t_imgs_ref		img_ref;
	t_loot_dt		*loots;
	t_player_dt		*player;
	t_map_dt		map;
}	t_mlx_dt;

int			check_move(t_mlx_dt *mlx_data, char move);
int			is_area_loot(t_loot_dt *loots, size_t pos_x, size_t pos_y);
int			check_map(t_map_dt *map);
int			check_map_path(t_map_dt *map);
int			is_search(char c, char *search);
int			can_loot(t_loot_dt *loots, size_t pos_x, size_t pos_y);

void		add_img_pl(t_mlx_dt *dt, mlx_image img, size_t pos_x, size_t pos_y);
void		add_img_lt(t_mlx_dt *dt, mlx_image img, size_t pos_x, size_t pos_y);
void		add_image(t_mlx_dt *dt, mlx_image img, size_t pos_x, size_t pos_y);
void		make_move(t_mlx_dt *mlx_data, char move);
void		take_loot(t_loot_dt *loots, size_t pos_x, size_t pos_y);
void		destroy_images(t_mlx_dt *mlx_data);
void		free_loots(t_loot_dt **loots);

char		*sl_strjoin(char *s1, char *s2);

size_t		sl_imgs_size(t_img_dt *lst);
size_t		get_max_x(char **map);
size_t		get_max_y(char **map);
size_t		get_total_loots(char **map);
size_t		count_type(char **map, char *search);

t_img_dt	*sl_imgs_last(t_img_dt *lst);
t_img_dt	*sl_img_at_pos(t_img_dt **lst, size_t pos_x, size_t pos_y);

t_loot_dt	*loot_at_pos(t_loot_dt **loots, size_t pos_x, size_t pos_y);
t_loot_dt	*loots_last(t_loot_dt *loots);

#endif