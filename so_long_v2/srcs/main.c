/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:30:13 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/08 13:54:09 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	key_hook(int key, void *param)
{
	t_mlx_dt	*mlx_data;

	mlx_data = (t_mlx_dt *)param;
	if (key == 41)
		mlx_loop_end((mlx_context)mlx_data->mlx);
	else if (key == 7)
		make_move(mlx_data, 'r');
	else if (key == 26)
		make_move(mlx_data, 't');
	else if (key == 4)
		make_move(mlx_data, 'l');
	else if (key == 22)
		make_move(mlx_data, 'd');
}

void	win_hook(int key, void *param)
{
	t_mlx_dt	*mlx_data;

	mlx_data = (t_mlx_dt *)param;
	if (key == 0)
		mlx_loop_end((mlx_context)mlx_data->mlx);
}

void	manage_line(t_mlx_dt *mlx_data, t_map_dt *map_data, size_t pos_y)
{
	size_t	i;
	char	*line;

	i = 0;
	line = ft_strdup((*map_data).map[pos_y]);
	while (line[i])
	{
		if (line[i] == '1')
			add_image(mlx_data, mlx_data->img_ref.wall, i, pos_y);
		else if (line[i] == '0')
			add_image(mlx_data, mlx_data->img_ref.path, i, pos_y);
		else if (line[i] == 'E')
			add_image(mlx_data, mlx_data->img_ref.exit, i, pos_y);
		else if (line[i] == 'P')
			add_img_pl(mlx_data, mlx_data->img_ref.pl_r, i, pos_y);
		else if (line[i] == 'C')
			add_img_lt(mlx_data, mlx_data->img_ref.loot, i, pos_y);
		i++;
	}
	free(line);
}

void	creates_images(t_mlx_dt *dt, t_map_dt *map_dt)
{
	int			size;
	size_t		pos_y;
	t_imgs_ref	i_ref;

	pos_y = 0;
	size = IMG_SIZE;
	i_ref.exit = mlx_new_image_from_file((*dt).mlx, TXT_EXIT, &size, &size);
	i_ref.loot = mlx_new_image_from_file((*dt).mlx, TXT_LOOT, &size, &size);
	i_ref.path = mlx_new_image_from_file((*dt).mlx, TXT_PATH, &size, &size);
	i_ref.wall = mlx_new_image_from_file((*dt).mlx, TXT_WALL, &size, &size);
	i_ref.pl_d = mlx_new_image_from_file((*dt).mlx, TXT_PLAYER_D, &size, &size);
	i_ref.pl_l = mlx_new_image_from_file((*dt).mlx, TXT_PLAYER_L, &size, &size);
	i_ref.pl_r = mlx_new_image_from_file((*dt).mlx, TXT_PLAYER_R, &size, &size);
	i_ref.pl_t = mlx_new_image_from_file((*dt).mlx, TXT_PLAYER_T, &size, &size);
	dt->img_ref = i_ref;
	while ((*map_dt).map[pos_y])
	{
		manage_line(dt, map_dt, pos_y);
		pos_y++;
	}
}

char	**read_map(char *map_name)
{
	int		fd;
	char	*map_fd;
	char	*line;
	char	*map_tmp;
	char	**map;

	if (!map_name)
	{
		perror("Error:\nInvalid map name");
		// Mettre une fonction pour tout detruire avant d'arreter
		exit(EXIT_FAILURE);
	}
	map_fd = ft_strjoin("./maps/", map_name);
	fd = open(map_fd, O_RDONLY);
	if (fd < 0)
	{
		perror("Error:\nMap does not exist");
		// Mettre une fonction pour tout detruire avant d'arreter
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	map_tmp = NULL;
	while (line)
	{
		map_tmp = sl_strjoin(map_tmp, line);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(map_tmp, '\n');
	close(fd);
	free(map_fd);
	free(map_tmp);
	return (map);
}

void	destroy_images(t_mlx_dt *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.exit);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.loot);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.path);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.wall);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.pl_d);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.pl_l);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.pl_r);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_ref.pl_t);
}

int	main(int ac, char **av)
{
	t_mlx_dt				mlx_dt;
	mlx_window_create_info	info = {0};

	if (ac != 2)
	{
		perror("Error:\nInvalid format: './so_long <map_name.ber>'");
		return (1);
	}
	mlx_dt.map.map = read_map(av[1]);
	mlx_dt.map.x_max = get_max_x(mlx_dt.map.map);
	mlx_dt.map.y_max = get_max_y(mlx_dt.map.map);
	mlx_dt.map.total_loots = get_total_loots(mlx_dt.map.map);
	if (!check_map(&mlx_dt.map))
		return (1); // faire une fonction de clean;
	mlx_dt.loots = NULL;
	mlx_dt.player = NULL;
	mlx_dt.mlx = mlx_init();
	info.title = "so_long";
	info.width = 1920;
	info.height = 1080;
	info.is_resizable = true;
	mlx_dt.win = mlx_new_window(mlx_dt.mlx, &info);
	mlx_on_event(mlx_dt.mlx, mlx_dt.win, MLX_KEYDOWN, key_hook, &mlx_dt);
	mlx_on_event(mlx_dt.mlx, mlx_dt.win, MLX_WINDOW_EVENT, win_hook, &mlx_dt);
	creates_images(&mlx_dt, &mlx_dt.map);
	mlx_loop(mlx_dt.mlx);
	// CLEAN
	mlx_destroy_window(mlx_dt.mlx, mlx_dt.win);
	destroy_images(&mlx_dt);
	free(mlx_dt.player);
	free(mlx_dt.map.map);
	free_loots(&mlx_dt.loots);
	mlx_destroy_context(mlx_dt.mlx);
	//
	return (0);
}
