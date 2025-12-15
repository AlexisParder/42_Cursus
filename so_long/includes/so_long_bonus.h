/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:10:01 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/15 14:48:19 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <libft.h>
# include <mlx.h>
# include <fcntl.h>

# ifndef TXT_PLAYER_R
#  define TXT_PLAYER_R "./textures/player/player_r.xpm"
# endif
# ifndef TXT_PLAYER_L
#  define TXT_PLAYER_L "./textures/player/player_l.xpm"
# endif
# ifndef TXT_PLAYER_T
#  define TXT_PLAYER_T "./textures/player/player_t.xpm"
# endif
# ifndef TXT_PLAYER_D
#  define TXT_PLAYER_D "./textures/player/player_d.xpm"
# endif
# ifndef TXT_ENEMY_R
#  define TXT_ENEMY_R "./textures/enemy/enemy_r.xpm"
# endif
# ifndef TXT_ENEMY_L
#  define TXT_ENEMY_L "./textures/enemy/enemy_l.xpm"
# endif
# ifndef TXT_ENEMY_T
#  define TXT_ENEMY_T "./textures/enemy/enemy_t.xpm"
# endif
# ifndef TXT_ENEMY_D
#  define TXT_ENEMY_D "./textures/enemy/enemy_d.xpm"
# endif
# ifndef TXT_PATH
#  define TXT_PATH "./textures/path.xpm"
# endif
# ifndef TXT_WALL
#  define TXT_WALL "./textures/wall.xpm"
# endif
# ifndef TXT_LOOT
#  define TXT_LOOT "./textures/loot.xpm"
# endif
# ifndef TXT_EXIT_C
#  define TXT_EXIT_C "./textures/exit_c.xpm"
# endif
# ifndef TXT_EXIT_O
#  define TXT_EXIT_O "./textures/exit_o.xpm"
# endif
# ifndef TXT_LOSE
#  define TXT_LOSE "./textures/lose.xpm"
# endif
# ifndef TXT_WIN
#  define TXT_WIN "./textures/win.xpm"
# endif
# ifndef IMG_SIZE
#  define IMG_SIZE 64
# endif
# ifndef SPEED_MOVE_ENEMY
#  define SPEED_MOVE_ENEMY 100000
# endif

typedef struct s_player_dt
{
	int			size;
	size_t		pos_x;
	size_t		pos_y;
	size_t		loot_collected;
	size_t		nb_move;
	char		direction;
}	t_player_dt;

typedef struct s_enemy_dt
{
	int					size;
	size_t				pos_x;
	size_t				pos_y;
	char				direction;
	int					is_on_loot;
	struct s_enemy_dt	*next; 
}	t_enemy_dt;

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
	void	*pl_d;
	void	*pl_l;
	void	*pl_r;
	void	*pl_t;
	void	*exit_c;
	void	*exit_o;
	void	*loot;
	void	*path;
	void	*wall;
	void	*en_d;
	void	*en_l;
	void	*en_r;
	void	*en_t;
	void	*win;
	void	*lose;
}	t_imgs_ref;

typedef struct s_mlx_dt
{
	void			*win;
	void			*mlx;
	int				stop_game;
	t_imgs_ref		img_ref;
	t_player_dt		*player;
	t_enemy_dt		*enemy;
	t_map_dt		map_dt;
	size_t			frame;
}	t_mlx_dt;

int			check_move(t_mlx_dt *mlx_data, char move, size_t p_x, size_t p_y);
int			check_move_en(t_mlx_dt *mlx_dt, char move, size_t p_x, size_t p_y);
int			check_map(t_map_dt *map);
int			check_map_path(t_map_dt *map);
int			is_search(char c, char *search);
int			add_img_pl(t_mlx_dt *dt, void *img, size_t pos_x, size_t pos_y);
int			create_enemy(t_enemy_dt **lst, size_t pos_x, size_t pos_y);
int			manage_enemy(t_mlx_dt *mlx_dt);

void		add_image(t_mlx_dt *dt, void *img, size_t pos_x, size_t pos_y);
void		make_move(t_mlx_dt *mlx_data, char move);
void		redraw_window(t_mlx_dt *mlx_data);
void		updt_pl(t_mlx_dt *mlx_data);
void		destroy_images(t_mlx_dt *mlx_data);
void		creates_images(t_mlx_dt *dt, t_map_dt *map_dt);
void		clean_all(t_mlx_dt *mlx_data);
void		close_game(t_mlx_dt *mlx_data, int status);
void		create_map_dt(t_mlx_dt *mlx_data, char **av);
void		display_move(t_mlx_dt *mlx_data);
void		display_lose(t_mlx_dt *dt);
void		display_win(t_mlx_dt *dt);
void		free_arr(char **arr);
void		free_lst(t_enemy_dt **lst);
void		save_exit_pos(t_mlx_dt *mlx_data, size_t x, size_t y);
void		manage_window(t_mlx_dt *mlx_dt);
void		*get_image_ref(t_mlx_dt *mlx_data, char	chr);
void		err_img(t_mlx_dt *mlx_data, char *line);
void		draw_enemies(t_mlx_dt *dt);

char		*sl_strjoin(char *s1, char *s2);

size_t		sl_lstsize(t_enemy_dt *lst);
size_t		get_max_x(char **map);
size_t		get_max_y(char **map);
size_t		get_total_loots(char **map);
size_t		count_type(char **map, char *search);

t_enemy_dt	*sl_lstlast(t_enemy_dt *lst);

#endif