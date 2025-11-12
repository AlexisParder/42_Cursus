/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:15:11 by achauvie          #+#    #+#             */
/*   Updated: 2025/11/12 17:08:28 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/**
 * TODO:
 * Parsing
 * faire un split pour recuperer un tableau
 * Mettre le tableau dans atoi
 */

// static char **ps_parsing(int len, char **av)
static void ps_parsing(int len, char **av)
{
    int  i;
    char *tmp_str;
   
    i = 1;
    tmp_str = NULL;
    while (i <= len)
    {
        tmp_str = ps_strjoin(tmp_str, av[i]);
        i++;
    }
    ft_printf("%s\n", tmp_str);
}

int	main(int ac, char **av)
{
    // char **tab;

	if (ac > 1)
	{
        ac--;
        // tab = ps_parsing(ac, av);
        ps_parsing(ac, av);
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
