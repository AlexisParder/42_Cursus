/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:36:42 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/27 09:37:23 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	err_img(t_mlx_dt *mlx_data, char *line)
{
	ft_printf("Error\nAllocation failure");
	free(line);
	close_game(mlx_data, EXIT_FAILURE);
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
