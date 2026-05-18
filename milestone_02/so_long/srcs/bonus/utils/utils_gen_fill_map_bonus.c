/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gen_fill_map_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:41:36 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/29 08:51:19 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	calc_space(t_gen_map *dt)
{
	long	i;
	long	j;

	i = 0;
	dt->space = 0;
	while (dt->map[i])
	{
		j = 0;
		while (dt->map[i][j])
		{
			if (dt->map[i][j] == '0')
				dt->space++;
			j++;
		}
		i++;
	}
}

static int	fill_map_type(t_gen_map *dt, char c)
{
	long	x;
	long	y;
	long	attempts;

	attempts = 0;
	while (attempts < (dt->w * dt->h * 2))
	{
		x = rand() % dt->w;
		y = rand() % dt->h;
		if (dt->map[y][x] == '0')
		{
			if (c == 'H' && player_too_close(dt, x, y))
			{
				attempts++;
				continue ;
			}
			dt->map[y][x] = c;
			return (1);
		}
		attempts++;
	}
	return (0);
}

static void	fill_loots(t_gen_map *dt)
{
	long	i;

	i = 0;
	while (i < dt->c)
	{
		if (!fill_map_type(dt, 'C'))
		{
			ft_printf("Error\nCannot place collectible\n");
			free_arr(dt->map);
			exit(EXIT_FAILURE);
		}
		dt->space--;
		i++;
	}
}

void	fill_map_c_h(t_gen_map *dt)
{
	long	i;

	if (dt->space < dt->c)
		err_space(dt, 'C');
	if (((dt->space - dt->c) / 3) < dt->nb_en)
		err_space(dt, 'H');
	fill_loots(dt);
	i = 0;
	while (i < dt->nb_en)
	{
		if (!fill_map_type(dt, 'H'))
		{
			ft_printf("Error\nCannot place enemy (no valid position)\n");
			free_arr(dt->map);
			exit(EXIT_FAILURE);
		}
		dt->space--;
		i++;
	}
}

void	fill_map_base(t_gen_map *dt)
{
	long	i;
	long	j;

	i = 0;
	while (dt->map[i])
	{
		j = 0;
		while (j < dt->w)
		{
			if (i == 0 || i == dt->h - 1)
				dt->map[i][j] = '1';
			else
			{
				if (j == 0 || j == dt->w - 1)
					dt->map[i][j] = '1';
				else
					dt->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	fill_map_type(dt, 'P');
	fill_map_type(dt, 'E');
	calc_space(dt);
}
