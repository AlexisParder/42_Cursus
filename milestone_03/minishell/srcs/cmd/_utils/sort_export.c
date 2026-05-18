/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:50:37 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/02 09:24:54 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_strcmp_key(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '=' && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static void	sort_arr(char **exports, int len, int *idx)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp_key(exports[idx[i]], exports[idx[j]]) > 0)
			{
				tmp = idx[i];
				idx[i] = idx[j];
				idx[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	print_word(char *str)
{
	int	i;
	int	has_value;

	i = 0;
	has_value = 0;
	while (str[i])
	{
		ft_printf("%c", str[i]);
		if ((str[i] == '=' && !has_value))
		{
			has_value = 1;
			ft_printf("\"");
		}
		i++;
	}
	if (has_value)
		ft_printf("\"");
	ft_printf("\n");
}

static void	print_exports(char **exports, int *idx, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!ft_strnstr(exports[idx[i]], "_=", 2))
		{
			ft_printf("declare -x ");
			print_word(exports[idx[i]]);
		}
		i++;
	}
}

void	display_exports(t_minishell *data, t_cmd *cmd)
{
	int		len;
	int		i;
	int		*idx;

	len = 0;
	while (data->exports[len])
		len++;
	idx = malloc(sizeof(int) * len);
	if (!idx)
	{
		cmd_exit(data, cmd);
		return ;
	}
	i = 0;
	while (i < len)
	{
		idx[i] = i;
		i++;
	}
	sort_arr(data->exports, len, idx);
	print_exports(data->exports, idx, len);
	free(idx);
}
