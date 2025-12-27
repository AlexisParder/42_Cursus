/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:32:50 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/27 09:38:43 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	err_create_file(t_gen_map *dt, char *file)
{
	ft_printf("Error\nFile creation failure");
	free_arr(dt->map);
	free(file);
	exit(EXIT_FAILURE);
}

void	err_map(int fd, char *map_tmp, char *line)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	free(map_tmp);
	free(line);
	ft_printf("Error\nInvalid map");
	exit(EXIT_FAILURE);
}

void	err_img(t_mlx_dt *mlx_data, char *line)
{
	ft_printf("Error\nAllocation failure");
	free(line);
	free_lst(&mlx_data->enemy);
	close_game(mlx_data, EXIT_FAILURE);
}
