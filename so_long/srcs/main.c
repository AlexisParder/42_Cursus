/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:30:13 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/01 13:55:28 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

#include <stdio.h>

void	add_img_player(t_mlx_data *mlx_data, char *texture, int pos_x, int pos_y)
{
	long			x_calc;
	long			y_calc;
	t_player_data 	*tmp;
	size_t			tmp_nb_move;

	tmp = malloc(sizeof(t_player_data));
	tmp->size = 64;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	tmp->loot_collected = 0;
	tmp_nb_move = 0;
	if (mlx_data->player != NULL)
		tmp_nb_move = mlx_data->player->nb_move;
	tmp->nb_move = tmp_nb_move;
	tmp->img = mlx_new_image_from_file((*mlx_data).mlx, texture, &tmp->size, &tmp->size);
	(*mlx_data).player = tmp;
	x_calc = tmp->pos_x * tmp->size;
	y_calc = tmp->pos_y * tmp->size;
	mlx_put_image_to_window((*mlx_data).mlx, (*mlx_data).win, tmp->img, x_calc, y_calc);
}

void	add_image(t_mlx_data *mlx_data, char *texture, int pos_x, int pos_y)
{
	t_img_data **imgs;
	long int x_calc;
	long int y_calc;
	t_img_data *tmp;
	t_img_data *img_last;

	imgs = &(*mlx_data).imgs;
	tmp = malloc(sizeof(t_img_data));
	tmp->size = 64;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	tmp->img = mlx_new_image_from_file((*mlx_data).mlx, texture, &tmp->size, &tmp->size);
	tmp->img_prev = NULL;
	tmp->img_next = NULL;
	if (*imgs)
	{
		img_last = sl_imgs_last(*imgs);
		tmp->img_prev = img_last;
		img_last->img_next = tmp;
	}
	else
		*imgs = tmp;
	x_calc = tmp->pos_x * tmp->size;
	y_calc = tmp->pos_y * tmp->size;
	mlx_put_image_to_window((*mlx_data).mlx, (*mlx_data).win, tmp->img, x_calc, y_calc);
}

int		check_move(t_mlx_data *mlx_data, char move)
{
	size_t	p_x;
	size_t	p_y;
	size_t	map_max_x;
	size_t	map_max_y;
	
	p_x = mlx_data->player->pos_x;
	p_y = mlx_data->player->pos_y;
	map_max_x = mlx_data->map.x_max;
	map_max_y = mlx_data->map.y_max;
	if (move == 'r')
	{
		if ((p_x + 1 >= map_max_x) || mlx_data->map.map[p_y][p_x + 1] == '1')
			return (0);
	}
	else if (move == 'l')
	{
		if ((p_x - 1 <= 0) || mlx_data->map.map[p_y][p_x - 1] == '1')
			return (0);
	}
	else if (move == 't')
	{
		if ((p_y - 1 <= 0) || mlx_data->map.map[p_y - 1][p_x] == '1')
			return (0);
	}
	else if (move == 'd')
	{
		if ((p_y + 1 >= map_max_y) || mlx_data->map.map[p_y + 1][p_x] == '1')
			return (0);
	}
	return (1);
}

void	make_move_r(t_mlx_data *mlx_data)
{
	size_t	pos_x;
	size_t	pos_y;
	
	printf("NB LOOT COLLECTED = %zu / %zu\n", mlx_data->player->loot_collected, mlx_data->map.total_loots);
	if (check_move(mlx_data, 'r'))
	{
		pos_x = mlx_data->player->pos_x;
		pos_y = mlx_data->player->pos_y;
		add_image(mlx_data, "./textures/path.png", pos_x, pos_y);
		mlx_data->player->pos_x++;
		pos_x = mlx_data->player->pos_x;
		mlx_data->player->nb_move++;
		add_img_player(mlx_data,  "./textures/player/player_r.png", pos_x, pos_y);
	}
}

void	make_move_l(t_mlx_data *mlx_data)
{
	size_t	pos_x;
	size_t	pos_y;
	
	printf("NB LOOT COLLECTED = %zu / %zu\n", mlx_data->player->loot_collected, mlx_data->map.total_loots);
	if (check_move(mlx_data, 'l'))
	{
		pos_x = mlx_data->player->pos_x;
		pos_y = mlx_data->player->pos_y;
		add_image(mlx_data, "./textures/path.png", pos_x, pos_y);
		mlx_data->player->pos_x--;
		pos_x = mlx_data->player->pos_x;
		mlx_data->player->nb_move++;
		add_img_player(mlx_data,  "./textures/player/player_l.png", pos_x, pos_y);
	}
}

void	make_move_t(t_mlx_data *mlx_data)
{
	size_t	pos_x;
	size_t	pos_y;
	
	printf("NB LOOT COLLECTED = %zu / %zu\n", mlx_data->player->loot_collected, mlx_data->map.total_loots);
	if (check_move(mlx_data, 't'))
	{
		pos_x = mlx_data->player->pos_x;
		pos_y = mlx_data->player->pos_y;
		add_image(mlx_data, "./textures/path.png", pos_x, pos_y);
		mlx_data->player->pos_y--;
		pos_y = mlx_data->player->pos_y;
		mlx_data->player->nb_move++;
		add_img_player(mlx_data,  "./textures/player/player_t.png", pos_x, pos_y);
	}
}

void	make_move_d(t_mlx_data *mlx_data)
{
	size_t	pos_x;
	size_t	pos_y;
	
	printf("NB LOOT COLLECTED = %zu / %zu\n", mlx_data->player->loot_collected, mlx_data->map.total_loots);
	if (check_move(mlx_data, 'd'))
	{
		pos_x = mlx_data->player->pos_x;
		pos_y = mlx_data->player->pos_y;
		add_image(mlx_data, "./textures/path.png", pos_x, pos_y);
		mlx_data->player->pos_y++;
		pos_y = mlx_data->player->pos_y;
		mlx_data->player->nb_move++;
		add_img_player(mlx_data,  "./textures/player/player_d.png", pos_x, pos_y);
	}
}

void key_hook(int key, void* param)
{
	t_mlx_data	*mlx_data;

	mlx_data = (t_mlx_data *)param;
	ft_printf("%d\n", key);
    if (key == 41) // ECHAP
        mlx_loop_end((mlx_context)mlx_data->mlx);
	else if (key == 7) // D
	{
		make_move_r(mlx_data);
		ft_printf("NB MOVE: %s\n", ft_itoa(mlx_data->player->nb_move));
	}
	else if (key == 26) // W
	{
		make_move_t(mlx_data);
		ft_printf("NB MOVE: %s\n", ft_itoa(mlx_data->player->nb_move));
	}
	else if (key == 4) // A
	{
		make_move_l(mlx_data);
		ft_printf("NB MOVE: %s\n", ft_itoa(mlx_data->player->nb_move));
	}
	else if (key == 22) // S
	{
		make_move_d(mlx_data);
		ft_printf("NB MOVE: %s\n", ft_itoa(mlx_data->player->nb_move));
	}
}

void win_hook(int key, void* param)
{
	t_mlx_data	*mlx_data;

	mlx_data = (t_mlx_data *)param;
    if (key == 0)
        mlx_loop_end((mlx_context)mlx_data->mlx);
}

char	*manage_texture(char type, t_map_data *map_data, size_t pos_x, size_t pos_y)
{
	// TEMPORAIRE
	(void)pos_x;
	(void)pos_y;
	if (type == 1)
		return ("./textures/wall.png");
	else if (type == 'E')
		return ("./textures/exit.png");
	else if (type == 'C')
	{
		(*map_data).total_loots++;
		return ("./textures/collectible.png");
	}
	else if (type == 'P')
		return ("./textures/player/player_r.png");
	return ("./textures/path.png");
}

void 	manage_line(t_mlx_data *mlx_data, t_map_data *map_data, size_t pos_y)
{
	size_t	i;
	char	*texture;
	char	*line;
	
	i = 0;
	line = ft_strdup((*map_data).map[pos_y]);
	while (line[i])
	{
		if (line[i] == '1')
		{
			texture = manage_texture(1, map_data, i, pos_y);
			add_image(mlx_data, texture, i, pos_y);
		}
		else if (line[i] == '0' || line[i] == 'C' || line[i] == 'E' || line[i] == 'P')
		{
			texture = manage_texture(0, map_data, i, pos_y);
			add_image(mlx_data, texture, i, pos_y);
			if (line[i] != '0' && line[i] != 'P')
			{
				texture = manage_texture(line[i], map_data, i, pos_y);
				add_image(mlx_data, texture, i, pos_y);
			}
			if (line[i] == 'P')
				add_img_player(mlx_data, "./textures/player/player_r.png", i, pos_y);
		}
		else if (line[i] != '\n')
		{
			perror("Error: invalid map");
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

void	creates_images(t_mlx_data *mlx_data, t_map_data *map_data)
{
	size_t	pos_y;

	(*mlx_data).imgs = malloc(1000000); // TEMPORAIRE
	pos_y = 0;
	while ((*map_data).map[pos_y])
	{
		manage_line(mlx_data, map_data, pos_y);
		pos_y++;
	}
}

char	**read_map(t_mlx_data mlx_data, char *map_name)
{
	int		fd;
	char	*map_fd;
	char	*line;
	char	*map_tmp;
	char	**map;
	
	if (!map_name)
	{
		perror("Error: invalid map name");
		// Mettre une fonction pour tout detruire avant d'arreter
		exit(EXIT_FAILURE);
	}
	mlx_data.imgs = malloc(1000000); // TEMPORAIRE
	map_fd = ft_strjoin("./maps/", map_name);
	fd = open(map_fd, O_RDONLY);
	if (fd < 0)
	{
		perror("Error: map does not exist");
		// Mettre une fonction pour tout detruire avant d'arreter
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		map_tmp = sl_strjoin(map_tmp, line);
		free (line);
		line = get_next_line(fd);
	}
	map = ft_split(map_tmp, '\n');
	close (fd);
	return (map);
}

void	destroy_images(t_mlx_data mlx_data, t_img_data **imgs)
{
	t_img_data *tmp;

	if (!imgs)
		return ;
	while (*imgs)
	{
		tmp = (*imgs)->img_next;
		mlx_destroy_image(mlx_data.mlx, (*imgs)->img);
		free(*imgs);
		*imgs = tmp;
	}
	*imgs = NULL;
}

int main(int ac, char **av)
{
	t_mlx_data	mlx_data;

	if (ac != 2)
	{
		perror("Error: invalid format: './so_long <map name>'");
		return (1);
	}
	mlx_data.mlx = mlx_init();
	mlx_window_create_info info = { 0 };
	info.title = "so_long";
	info.width = 1200;
	info.height = 600;
	info.is_resizable = true;
	mlx_data.win = mlx_new_window(mlx_data.mlx, &info);
	mlx_on_event(mlx_data.mlx, mlx_data.win, MLX_KEYDOWN, key_hook, &mlx_data);
	mlx_on_event(mlx_data.mlx, mlx_data.win, MLX_WINDOW_EVENT, win_hook, &mlx_data);
	mlx_data.map.map = read_map(mlx_data, av[1]);
	mlx_data.map.x_max = get_max_x(mlx_data.map.map);
	mlx_data.map.y_max = get_max_y(mlx_data.map.map);
	mlx_data.map.total_loots = 0;
	mlx_data.player = NULL;
	creates_images(&mlx_data, &mlx_data.map);
	mlx_loop(mlx_data.mlx);
    mlx_destroy_window(mlx_data.mlx, mlx_data.win);
	destroy_images(mlx_data, &mlx_data.imgs);
    mlx_destroy_context(mlx_data.mlx);
	return (0);
}
