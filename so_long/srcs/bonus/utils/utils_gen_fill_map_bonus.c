/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gen_fill_map_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:41:36 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/26 12:48:41 by achauvie         ###   ########.fr       */
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

static void	err_space(t_gen_map *dt, char c)
{
	char	*nb;

	if (c == 'C')
	{
		nb = ft_itoa(dt->space);
		ft_printf("You cannot place more than %s loot (C) on this map!\n", nb);
	}
	else
	{
		nb = ft_itoa(((dt->space - dt->c) / 3));
		ft_printf("You cannot place more than %s enemy (H) on this map!\n", nb);
	}
	free(nb);
	free_arr(dt->map);
	exit(EXIT_FAILURE);
}

static void	fill_map_type(t_gen_map *dt, char c)
{
	long	x;
	long	y;

	while (1)
	{
		x = rand() % dt->w;
		y = rand() % dt->h;
		if (dt->map[y][x] == '0')
		{
			dt->map[y][x] = c;
			break ;
		}
	}
}

void	fill_map_c_h(t_gen_map *dt)
{
	long	i;

	if (dt->space < dt->c)
		err_space(dt, 'C');
	if (((dt->space - dt->c) / 3) < dt->nb_en)
		err_space(dt, 'H');
	i = 0;
	while (i < dt->c)
	{
		fill_map_type(dt, 'C');
		dt->space--;
		i++;
	}
	i = 0;
	while (i < dt->nb_en)
	{
		fill_map_type(dt, 'H');
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
