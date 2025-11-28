/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:30:13 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/28 17:11:16 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void key_hook(int key, void* param)
{
	ft_printf("%d\n", key);
    if (key == 41) // ECHAP
        mlx_loop_end((mlx_context)param);
}

void win_hook(int key, void* param)
{
    if (key == 0)
        mlx_loop_end((mlx_context)param);
}

void add_image(t_mlx_data mlx_data, char *texture, int pos_x, int pos_y)
{
	t_img_data **imgs;
	int x_calc;
	int y_calc;
	t_img_data *tmp;
	t_img_data *img_last;

	imgs = &mlx_data.imgs;
	tmp = malloc(sizeof(t_img_data));
	tmp->size = 64;
	tmp->pos_x = pos_x;
	tmp->pos_y = pos_y;
	tmp->img = mlx_new_image_from_file(mlx_data.mlx, texture, &tmp->size, &tmp->size);
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
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, tmp->img, x_calc, y_calc);
}

char	*manage_texture(char type, size_t pos_x, size_t	pos_y)
{
	// TEMPORAIRE
	(void)pos_x;
	(void)pos_y;
	if (type == 1)
		return ("./textures/wall_l_r.png");
	else if (type == 'E')
		return ("./textures/exit.png");
	else if (type == 'C')
		return ("./textures/collectible.png");
	else if (type == 'P')
		return ("./textures/player.png");
	return ("./textures/path_all.png");
	//
}

void 	manage_line(t_mlx_data mlx_data, char *line, size_t pos_y)
{
	size_t	i;
	char	*texture;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
		{
			texture = manage_texture(1, i, pos_y);
			add_image(mlx_data, texture, i, pos_y);
		}
		else if (line[i] == '0' || line[i] == 'C' || line[i] == 'E' || line[i] == 'P')
		{
			texture = manage_texture(0, i, pos_y);
			add_image(mlx_data, texture, i, pos_y);
			if (line[i] != '0')
			{
				texture = manage_texture(line[i], i, pos_y);
				add_image(mlx_data, texture, i, pos_y);
			}
		}
		else if (line[i] != '\n')
		{
			perror("Error: invalid map");
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

void	creates_images(t_mlx_data mlx_data, char *map_name)
{
	int	fd;
	size_t	pos_y;
	char *map_fd;
	char *line;
	
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
	pos_y = 0;
	while (line)
	{
		manage_line(mlx_data, line, pos_y);
		free (line);
		line = get_next_line(fd);
		pos_y++;
	}
	close (fd);
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
	t_mlx_data mlx_data;

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
	mlx_on_event(mlx_data.mlx, mlx_data.win, MLX_KEYDOWN, key_hook, mlx_data.mlx);
	mlx_on_event(mlx_data.mlx, mlx_data.win, MLX_WINDOW_EVENT, win_hook, mlx_data.mlx);
	creates_images(mlx_data, av[1]);
	mlx_loop(mlx_data.mlx);
    mlx_destroy_window(mlx_data.mlx, mlx_data.win);
	destroy_images(mlx_data, &mlx_data.imgs);
    mlx_destroy_context(mlx_data.mlx);
	return (0);
}
