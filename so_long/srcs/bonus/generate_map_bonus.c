/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:35:39 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/27 08:23:41 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	fill_file(t_gen_map *dt, int fd, char *file)
{
	size_t	i;

	i = 0;
	while (dt->map[i])
	{
		ft_putstr_fd(dt->map[i], fd);
		if (dt->map[i + 1])
			ft_putchar_fd('\n', fd);
		i++;
	}
	close(fd);
	free_arr(dt->map);
	ft_printf("The map was generated (%s)", file);
	free(file);
}

static void	create_file(t_gen_map *dt)
{
	long	current_time;
	int		fd;
	char	*time;
	char	*file;

	current_time = get_time_ms();
	time = ft_itoa(current_time);
	file = ft_strjoin("./maps/", time);
	free(time);
	file = sl_strjoin(file, ".ber");
	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd < 0)
	{
		ft_printf("Error\nFile creation failure");
		free_arr(dt->map);
		free(file);
		exit(EXIT_FAILURE);
	}
	fill_file(dt, fd, file);
}

static int	check_map_gen(t_gen_map *dt)
{
	t_map_dt	map_dt;

	map_dt.map = dt->map;
	map_dt.x_max = dt->w;
	map_dt.y_max = dt->h;
	map_dt.total_loots = dt->c;
	while (!check_map(&map_dt))
	{
		free_arr(dt->map);
		map_dt.map = dt->map;
		map_dt.x_max = dt->w;
		map_dt.y_max = dt->h;
		map_dt.total_loots = dt->c;
		return (0);
	}
	create_file(dt);
	return (1);
}

static void	generate_map(t_gen_map *dt)
{
	long	i;

	dt->map = ft_calloc(dt->h + 1, sizeof(char *));
	if (!dt->map)
	{
		ft_printf("Error\nAllocation failure");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < dt->h)
	{
		dt->map[i] = ft_calloc(dt->w + 1, sizeof(char));
		if (!dt->map[i])
		{
			ft_printf("Error\nAllocation failure");
			free_arr(dt->map);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	fill_map_base(dt);
	fill_map_c_h(dt);
	if (!check_map_gen(dt))
		generate_map(dt);
}

void	start_generate_map(char **av)
{
	t_gen_map	dt;

	dt.w = ft_atol(av[1]);
	dt.h = ft_atol(av[2]);
	dt.c = ft_atol(av[3]);
	dt.nb_en = ft_atol(av[4]);
	if (dt.w < 5 || dt.w > 30)
		ft_printf("Error\nWidth must be between 5 and 30\n");
	if (dt.h < 3 || dt.h > 16)
		ft_printf("Error\nHeight must be between 3 and 16\n");
	if (dt.w == dt.h)
		ft_printf("Error\nThe map is not rectangular\n");
	if (dt.c < 1)
		ft_printf("Error\nLoot must be at least 1\n");
	if (dt.nb_en < 0)
		dt.nb_en = 0;
	if (dt.w < 5 || dt.w > 30 || dt.h > 16 || dt.h < 3
		|| dt.w == dt.h || dt.c < 1)
		exit(EXIT_FAILURE);
	generate_map(&dt);
}
