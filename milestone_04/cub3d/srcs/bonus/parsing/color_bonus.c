/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:56:44 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/06 14:08:25 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static int	fill_color(char **split_color, mlx_color *color)
{
	int			i;
	long		tmp_color;

	i = 0;
	while (i < 3)
	{
		tmp_color = ft_atol(split_color[i]);
		if (tmp_color < 0 || tmp_color > 255)
		{
			ft_dprintf(2, "Error\nColor values must be between 0 and 255\n");
			ft_free_arr(split_color);
			return (0);
		}
		if (i == 0)
			color->r = (uint8_t)tmp_color;
		else if (i == 1)
			color->g = (uint8_t)tmp_color;
		else if (i == 2)
			color->b = (uint8_t)tmp_color;
		i++;
	}
	return (1);
}

static int	create_color(char **split_color, mlx_color *key, int *parse)
{
	mlx_color	color;

	color.a = 0xFF;
	if (ft_arr_len(split_color) == 4)
	{
		ft_dprintf(2, "Error\nInvalid color (format: r,g,b)\n");
		ft_free_arr(split_color);
		return (0);
	}
	if (!fill_color(split_color, &color))
		return (0);
	ft_free_arr(split_color);
	*key = color;
	*parse = 1;
	return (1);
}

static int	color_is_valid(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		else if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	if (comma != 2)
		return (0);
	return (1);
}

static int	set_color(char **split_line, mlx_color *key, int *parse)
{
	char		**split_color;

	if (!color_is_valid(split_line[1]))
	{
		ft_dprintf(2, "Error\nInvalid color (format: r,g,b)\n");
		return (0);
	}
	split_color = ft_split(split_line[1], ',');
	if (!split_color)
	{
		ft_dprintf(2, "Error\nFailure during allocation\n");
		return (0);
	}
	return (create_color(split_color, key, parse));
}

int	manage_color(t_data *data, t_parse_map *dt_parse, char **split_line)
{
	int	code;

	code = 1;
	if (!ft_strncmp(split_line[0], "C", 2))
	{
		if (check_duplicated_color(dt_parse->cl_c_view, 'C'))
			return (0);
		code = set_color(split_line, &data->cl_ceiling, &dt_parse->cl_c_view);
	}
	else if (!ft_strncmp(split_line[0], "F", 2))
	{
		if (check_duplicated_color(dt_parse->cl_f_view, 'F'))
			return (0);
		code = set_color(split_line, &data->cl_floor, &dt_parse->cl_f_view);
	}
	else if (!ft_strncmp(split_line[0], "I", 2))
	{
		if (check_duplicated_color(dt_parse->cl_i_view, 'I'))
			return (0);
		code = set_color(split_line, &data->cl_interact, &dt_parse->cl_i_view);
	}
	return (code);
}
