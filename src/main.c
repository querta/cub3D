/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:00:56 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/24 18:49:02 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		main(int argc, char **argv)
{
	// (void)argc;
	// (void)argv;
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr_fd(line, 1);
		ft_putchar_fd('\n', 1);
		free(line);
	}
	ft_putstr_fd(line, 1);
	ft_putchar_fd('\n', 1);
	free(line);
	
	if (argc == 2)
		close(fd);
	
	return (0);
}