/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:10:01 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/01 13:20:35 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include <mlx.h>
# include <mlx_extended.h>
# include <fcntl.h>
# include <stdio.h>

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

typedef struct s_mlx_data
{
	mlx_window		win;
	mlx_context		mlx;
	t_img_data		*imgs;
	t_player_data	*player;
	t_map_data		map;
}	t_mlx_data;

char		*sl_strjoin(char *s1, char *s2);

size_t		sl_imgs_size(t_img_data *lst);
size_t		get_max_x(char **map);
size_t		get_max_y(char **map);

t_img_data	*sl_imgs_last(t_img_data *lst);
t_img_data	*sl_img_at_pos(t_img_data **lst, size_t pos_x, size_t pos_y);


#endif