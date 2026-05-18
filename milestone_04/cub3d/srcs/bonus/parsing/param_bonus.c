/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:01:52 by tjourdai          #+#    #+#             */
/*   Updated: 2026/04/24 11:30:58 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static int	set_param(char **tex, int *viewed, char *key, char *value)
{
	if (!check_img_format(key, value))
		return (0);
	if (*viewed)
	{
		ft_dprintf(2,
			"Error\nParameter '%s' appears multiple times in the file.\n", key);
		return (0);
	}
	*tex = ft_strdup(value);
	if (!*tex)
	{
		ft_dprintf(2, "Error\nFailure during allocation\n");
		return (0);
	}
	*viewed = 1;
	return (1);
}

int	manage_param(t_data *data, t_parse_map *dt_p, char **split_line)
{
	int	code;

	code = 1;
	if (!ft_strncmp(split_line[0], "NO", 3))
		code = set_param(&data->tex_n, &dt_p->tex_n_view, "NO", split_line[1]);
	else if (!ft_strncmp(split_line[0], "SO", 3))
		code = set_param(&data->tex_s, &dt_p->tex_s_view, "SO", split_line[1]);
	else if (!ft_strncmp(split_line[0], "WE", 3))
		code = set_param(&data->tex_w, &dt_p->tex_w_view, "WE", split_line[1]);
	else if (!ft_strncmp(split_line[0], "EA", 3))
		code = set_param(&data->tex_e, &dt_p->tex_e_view, "EA", split_line[1]);
	else if (!ft_strncmp(split_line[0], "DC", 3))
		code = set_param(&data->tex_dc, &dt_p->tex_dc_view,
				"DC", split_line[1]);
	else if (!ft_strncmp(split_line[0], "DO", 3))
		code = set_param(&data->tex_do, &dt_p->tex_do_view,
				"DO", split_line[1]);
	else
	{
		ft_dprintf(2, "Error\nInvalid argument\n");
		code = 0;
	}
	return (code);
}

int	check_duplicated_color(int viewed, char color_char)
{
	if (viewed)
	{
		ft_dprintf(2, "Error\nParameter '%c' is duplicated in the file.\n",
			color_char);
		return (1);
	}
	return (0);
}
