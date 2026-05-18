/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 10:20:42 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/16 13:52:37 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	check_map_format(char *map_path)
{
	size_t	len;

	len = ft_strlen(map_path);
	if (!ft_strnstr(&map_path[len - 4], ".cub", 4))
	{
		ft_dprintf(2, "Error\nInvalid type, format: <name>.cub\n");
		exit(EXIT_FAILURE);
	}
}

int	check_img_format(char *key, char *img)
{
	size_t	len;

	len = ft_strlen(img);
	if (!ft_strnstr(&img[len - 4], ".png", 4)
		&& !ft_strnstr(&img[len - 4], ".jpg", 4)
		&& !ft_strnstr(&img[len - 4], ".bmp", 4)
		&& !ft_strnstr(&img[len - 5], ".jpeg", 5))
	{
		ft_dprintf(2, "Error\nInvalid image (%s)\n", key);
		ft_dprintf(2, "Autorized formats: {png/jpg/jpeg/bmp}\n");
		return (0);
	}
	return (1);
}

int	str_has_space(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '\n')
		return (1);
	while (str[i] && str[i] != '\n')
	{
		if (ft_isspace(str[i]))
			j++;
		i++;
	}
	return (i == j);
}

void	free_get_next_line(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	free_data_params(t_data *data)
{
	free(data->tex_n);
	free(data->tex_s);
	free(data->tex_w);
	free(data->tex_e);
	data->tex_n = NULL;
	data->tex_s = NULL;
	data->tex_w = NULL;
	data->tex_e = NULL;
}
