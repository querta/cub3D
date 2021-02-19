/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:22:47 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/19 20:05:07 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void freestruct(t_set *s)
{
	free(s->tex->no->path);
	free(s->tex->so->path);
	free(s->tex->we->path);
	free(s->tex->ea->path);
	free(s->tex->no);
	free(s->tex->so);
	free(s->tex->we);
	free(s->tex->ea);
	free(s->tex);
	free(s->s);
	free(s->f);
	free(s->c);
}

static	void		lst_del(void *content)
{
	free(content);
}

static	int exit_free(t_set *s)
{
	// if (s->mlx->win)
	// 	mlx_destroy_window(s->mlx->mlx, s->mlx->win);
	// if(s->img->img)
	// 	mlx_destroy_image(s->mlx->mlx, s->img->img);
	ft_lstclear(&s->mlist, &lst_del);
	freestruct(s);
	free(s->map);
	exit (0);
}

void error(t_set *s, int code)
{
	if (code == ER_MAP)
		ft_putendl_fd("Wrong map", 1);
	if (code == ER_SETTINGS)
		ft_putendl_fd("Wrong map, check settings", 1);
	if (code == ER_TEXTURE)
		ft_putendl_fd("Error reading texture", 1);
	exit_free (s);
}
