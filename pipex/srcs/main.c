/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:56:30 by achauvie          #+#    #+#             */
/*   Updated: 2025/12/16 15:05:37 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int main(int ac, char **av)
{
	int	fd1;
	
	if (ac != 5)
	{
		ft_putstr_fd("Error usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (1);
	}
	fd1 = open(av[1], O_RDONLY);
	if (fd1 < 0)
		perror(av[1]);
	return 0;
}
