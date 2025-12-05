/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:10:01 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/05 09:36:34 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include <mlx.h>
# include <mlx_extended.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef TEXTURE_PLAYER_R
#  define TEXTURE_PLAYER_R "./textures/player/player_r.png"
# endif
# ifndef TEXTURE_PLAYER_L
#  define TEXTURE_PLAYER_L "./textures/player/player_l.png"
# endif
# ifndef TEXTURE_PLAYER_T
#  define TEXTURE_PLAYER_T "./textures/player/player_t.png"
# endif
# ifndef TEXTURE_PLAYER_D
#  define TEXTURE_PLAYER_D "./textures/player/player_d.png"
# endif
# ifndef TEXTURE_PATH
#  define TEXTURE_PATH "./textures/path.png"
# endif
# ifndef TEXTURE_WALL
#  define TEXTURE_WALL "./textures/wall.png"
# endif
# ifndef TEXTURE_LOOT
#  define TEXTURE_LOOT "./textures/loot.png"
# endif
# ifndef TEXTURE_EXIT
#  define TEXTURE_EXIT "./textures/exit.png"
# endif
# ifndef IMG_SIZE
#  define IMG_SIZE 64
# endif

typedef struct s_img_data
{
	mlx_image			img;
	int					size;
	size_t				pos_x;
	size_t				pos_y;
	struct s_img_data	*img_next;
	struct s_img_data	*img_prev;
}	t_img_data;

typedef struct s_player_data
{
	mlx_image	img;
	int			size;
	size_t		pos_x;
	size_t		pos_y;
	size_t		loot_collected;
	size_t		nb_move;
}	t_player_data;

typedef struct s_map_data
{
	char	**map;
	size_t	x_max;
	size_t	y_max;
	size_t	total_loots;
}	t_map_data;

typedef struct s_map_ck
{
	char	**map;
	int		exit_found;
	size_t	loot_found;
}	t_map_ck;

typedef struct s_mlx_data
{
	mlx_window		win;
	mlx_context		mlx;
	t_img_data		*imgs;
	t_img_data		*loots;
	t_player_data	*player;
	t_map_data		map;
}	t_mlx_data;

int			check_move(t_mlx_data *mlx_data, char move);
int			is_area_loot(t_img_data *lst, size_t pos_x, size_t pos_y);
int			check_map(t_map_data *map);
int			check_map_path(t_map_data *map);
int			is_search(char c, char *search);

void		add_img_pl(t_mlx_data *dt, char *txt, int pos_x, int pos_y);
void		add_img_lt(t_mlx_data *dt, char *txt, int pos_x, int pos_y);
void		add_image(t_mlx_data *dt, char *txt, int pos_x, int pos_y);
void		make_move(t_mlx_data *mlx_data, char move);
void		remove_loot(t_img_data **lst, size_t pos_x, size_t pos_y);
void 		redraw_all_images(t_mlx_data *mlx_data);
void		destroy_images(t_mlx_data *mlx_data, t_img_data **imgs);

char		*sl_strjoin(char *s1, char *s2);

size_t		sl_imgs_size(t_img_data *lst);
size_t		get_max_x(char **map);
size_t		get_max_y(char **map);
size_t		get_total_loots(char **map);
size_t		count_type(char **map, char *search);

t_img_data	*sl_imgs_last(t_img_data *lst);
t_img_data	*sl_img_at_pos(t_img_data **lst, size_t pos_x, size_t pos_y);

#endif