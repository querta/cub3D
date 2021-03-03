/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 22:35:25 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/03 17:39:00 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned char	*create_fileheader(int x, int y)
{
	static unsigned char	header[14];
	int						size;
	int						padding;

	ft_bzero(&header, 14);
	padding = (4 - (x * 3) % 4) % 4;
	size = 54 + ((x * 3) + padding) * y;
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(size);
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)(54);
	return (header);
}

static unsigned char	*create_infoheader(int x, int y)
{
	static unsigned char	header[40];

	ft_bzero(&header, 40);
	header[0] = (unsigned char)(40);
	header[4] = (unsigned char)(x);
	header[5] = (unsigned char)(x >> 8);
	header[6] = (unsigned char)(x >> 16);
	header[7] = (unsigned char)(x >> 24);
	header[8] = (unsigned char)(y);
	header[9] = (unsigned char)(y >> 8);
	header[10] = (unsigned char)(y >> 16);
	header[11] = (unsigned char)(y >> 24);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(24);
	return (header);
}

static void				write_image(t_set *s, int fd)
{
	unsigned char	rgb[3];
	int				i;
	int				k;
	int				y;
	int				p;

	i = 0;
	y = s->size_y - 1;
	while (i < y)
	{
		k = 0;
		while (k < s->size_x)
		{
			p = (*(int*)(s->img->addr +
				(k * s->img->bits_per_pixel / 8 + y * s->img->line_length)));
			rgb[2] = (unsigned char)(p / 65536);
			rgb[1] = (unsigned char)((p - (rgb[1] * 65536)) / 256);
			rgb[0] = (unsigned char)(p - ((rgb[1] * 65536) + (rgb[2] * 256)));
			write(fd, rgb, 3);
			k++;
		}
		y--;
	}
}

void					save_screenshot(t_set *s)
{
	int				fd;
	unsigned char	*infoheader;
	unsigned char	*fileheader;

	if ((fd = open("./cub3d.bmp", O_CREAT | O_RDWR, 416)) > 0)
	{
		infoheader = create_infoheader(s->size_x, s->size_y - 1);
		fileheader = create_fileheader(s->size_x, s->size_y);
		write(fd, fileheader, 14);
		write(fd, infoheader, 40);
		write_image(s, fd);
		close(fd);
	}
	if (fd == -1)
		error(s, ER_SCREEN);
	ft_putendl_fd("cub3d.bmp successfully created", 1);
	error(s, SUCCESS);
}
