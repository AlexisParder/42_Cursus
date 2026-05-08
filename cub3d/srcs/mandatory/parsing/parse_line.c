/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:42:16 by tjourdai          #+#    #+#             */
/*   Updated: 2026/05/06 14:10:46 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	line_is_map(char *line, char **map, t_parse_map *dt_parse)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr("10 NSWE", line[i]))
		{
			ft_dprintf(2, "Error\nInvalid map character\n");
			return (0);
		}
		i++;
	}
	if (!dt_parse->tex_n_view || !dt_parse->tex_s_view
		|| !dt_parse->tex_e_view || !dt_parse->tex_w_view
		|| !dt_parse->cl_c_view || !dt_parse->cl_f_view)
	{
		ft_dprintf(2, "Error\nMissing textures or colors before map\n");
		return (0);
	}
	*map = ft_strjoin_free(*map, line);
	return (1);
}

char	**get_split_line(char *line)
{
	char	**split_line;
	char	**split_all;

	if (line[0] == '0' || line[0] == '1' || ft_isspace(line[0]))
	{
		split_line = ft_calloc(2, sizeof(char *));
		if (!split_line)
		{
			ft_dprintf(2, "Error\nFailure during allocation\n");
			return (NULL);
		}
		split_line[0] = ft_strdup(line);
		if (!split_line[0])
		{
			ft_free_arr(split_line);
			ft_dprintf(2, "Error\nFailure during allocation\n");
			return (NULL);
		}
		return (split_line);
	}
	split_all = ft_split_all_space(line);
	return (split_all);
}

int	handle_param_or_color(t_data *data, t_parse_map *dt_parse,
	char ***split_line)
{
	size_t	len;
	int		code;

	len = ft_strlen(*split_line[0]);
	if ((len == 1 || len == 2) && ft_arr_len(*split_line) == 2)
	{
		if (len == 1)
			code = manage_color(data, dt_parse, *split_line);
		else
			code = manage_param(data, dt_parse, *split_line);
		if (*split_line)
			ft_free_arr(*split_line);
		return (code);
	}
	else
	{
		ft_dprintf(2, "Error\nInvalid format\n");
		return (0);
	}
	return (1);
}

int	handle_map_line(char **split_line, char **map,
	t_parse_map *dt_parse)
{
	if (str_has_space(split_line[0]))
		return (0);
	if (!line_is_map(split_line[0], map, dt_parse))
	{
		ft_free_arr(split_line);
		free(*map);
		*map = NULL;
		return (1);
	}
	return (0);
}
