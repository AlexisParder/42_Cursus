/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjourdai <tjourdai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:23:08 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/08 11:31:12 by tjourdai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	get_saved_file(t_data *data)
{
	char	*line;
	int		fd;

	fd = open(".cub3d_save", O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		set_saved_value(data, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	write_setting(int fd, char *prefix, int value)
{
	char	*str;
	char	*line;

	str = ft_itoa(value);
	if (!str)
		return ;
	line = ft_strjoin(prefix, str);
	free(str);
	if (!line)
		return ;
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	free(line);
}

void	save_settings_in_file(t_data *data)
{
	int	fd;

	fd = open(".cub3d_save", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		return ;
	write_setting(fd, "FW=", data->settings.key_forward);
	write_setting(fd, "BW=", data->settings.key_backward);
	write_setting(fd, "LW=", data->settings.key_left);
	write_setting(fd, "RW=", data->settings.key_right);
	write_setting(fd, "DC=", data->settings.fov);
	write_setting(fd, "MS=", (int)(data->settings.mouse_sensitivity * 1000.0));
	write_setting(fd, "BR=", data->settings.brightness);
	close(fd);
}

void	set_save_settings(t_data *data)
{
	data->settings.fov = 90;
	data->settings.mouse_sensitivity = 0.002;
	data->settings.brightness = 100;
	data->settings.key_forward = KEY_W;
	data->settings.key_backward = KEY_S;
	data->settings.key_left = KEY_A;
	data->settings.key_right = KEY_D;
	get_saved_file(data);
}
