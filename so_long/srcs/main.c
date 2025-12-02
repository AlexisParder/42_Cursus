/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:30:13 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/02 13:23:34 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void key_hook(int key, void* param)
{
	t_mlx_data	*mlx_data;

	mlx_data = (t_mlx_data *)param;
    if (key == 41) // ECHAP
        mlx_loop_end((mlx_context)mlx_data->mlx);
	else if (key == 7) // D
		make_move(mlx_data, 'r');
	else if (key == 26) // W
		make_move(mlx_data, 't');
	else if (key == 4) // A
		make_move(mlx_data, 'l');
	else if (key == 22) // S
		make_move(mlx_data, 'd');
}

void win_hook(int key, void* param)
{
	t_mlx_data	*mlx_data;

	mlx_data = (t_mlx_data *)param;
    if (key == 0)
        mlx_loop_end((mlx_context)mlx_data->mlx);
}

void 	manage_line(t_mlx_data *mlx_data, t_map_data *map_data, size_t pos_y)
{
	size_t	i;
	char	*line;
	
	i = 0;
	line = ft_strdup((*map_data).map[pos_y]);
	while (line[i])
	{
		if (line[i] == '1')
			add_image(mlx_data, TEXTURE_WALL, i, pos_y);
		else if (line[i] == '0')
			add_image(mlx_data, TEXTURE_PATH, i, pos_y);
		else if (line[i] == 'E')
			add_image(mlx_data, TEXTURE_EXIT, i, pos_y);
		else if (line[i] == 'P')
			add_img_pl(mlx_data, TEXTURE_PLAYER_R, i, pos_y);
		else if (line[i] == 'C')
			add_img_lt(mlx_data, TEXTURE_LOOT, i, pos_y);
		else if (line[i] != '\n')
		{
			perror("Error: invalid map");
			exit (EXIT_FAILURE);
		}
		i++;
	}
	free(line);
}

void	creates_images(t_mlx_data *mlx_data, t_map_data *map_data)
{
	size_t	pos_y;
	size_t	nb_imgs;

	nb_imgs = ((map_data->y_max + 1) * (map_data->x_max + 1)) - map_data->total_loots;
	(*mlx_data).imgs = ft_calloc(nb_imgs, sizeof(t_img_data));
	(*mlx_data).loots = ft_calloc(map_data->total_loots + 1, sizeof(t_img_data));
	pos_y = 0;
	while ((*map_data).map[pos_y])
	{
		manage_line(mlx_data, map_data, pos_y);
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
		perror("Error: invalid map name");
		// Mettre une fonction pour tout detruire avant d'arreter
		exit(EXIT_FAILURE);
	}
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
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(map_tmp, '\n');
	close (fd);
	return (map);
}

void	destroy_images(t_mlx_data mlx_data, t_img_data **imgs)
{
	t_img_data *tmp;
	(void)mlx_data;

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
	mlx_data.map.map = read_map(av[1]);
	mlx_data.map.x_max = get_max_x(mlx_data.map.map);
	mlx_data.map.y_max = get_max_y(mlx_data.map.map);
	mlx_data.map.total_loots = get_total_loots(mlx_data.map.map);
	if (!check_map(&mlx_data.map))
		return (1); // faire une fonction de clean;
	mlx_data.imgs = NULL;
	mlx_data.loots = NULL;
	mlx_data.player = NULL;
	mlx_data.mlx = mlx_init();
	mlx_window_create_info info = { 0 };
	info.title = ft_strjoin("so_long - ", av[1]);
	info.width = 1200;
	info.height = 600;
	info.is_resizable = true;
	mlx_data.win = mlx_new_window(mlx_data.mlx, &info);
	mlx_on_event(mlx_data.mlx, mlx_data.win, MLX_KEYDOWN, key_hook, &mlx_data);
	mlx_on_event(mlx_data.mlx, mlx_data.win, MLX_WINDOW_EVENT, win_hook, &mlx_data);
	creates_images(&mlx_data, &mlx_data.map);
	mlx_loop(mlx_data.mlx);
	// CLEAN
    mlx_destroy_window(mlx_data.mlx, mlx_data.win);
	destroy_images(mlx_data, &mlx_data.imgs);
	destroy_images(mlx_data, &mlx_data.loots);
	mlx_destroy_image(mlx_data.mlx, mlx_data.player->img);
	free(mlx_data.player);
    mlx_destroy_context(mlx_data.mlx);
	// 
	return (0);
}
