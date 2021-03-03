/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:22:47 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/03 18:17:16 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		freestruct(t_set *s)
{
	free(s->tex->no->path);
	free(s->tex->so->path);
	free(s->tex->we->path);
	free(s->tex->ea->path);
	free(s->tex->spr->path);
	free(s->tex->no);
	free(s->tex->so);
	free(s->tex->we);
	free(s->tex->ea);
	free(s->tex->spr);
	free(s->tex);
	free(s->ray);
	free(s->sp);
	free(s->img);
	free(s->spr);
	free(s->mlx);
}

static	void	lst_del(void *content)
{
	free(content);
}

static int		exit_free(t_set *s)
{
	if (s->img->img)
		mlx_destroy_image(s->mlx->mlx, s->img->img);
	ft_lstclear(&s->mlist, &lst_del);
	freestruct(s);
	free(s->map);
	free(s);
	exit(1);
}

void			error(t_set *s, int code)
{
	if (code == SUCCESS)
		exit(0);
	if (code == ER_MAP)
		ft_putendl_fd("Wrong map", 1);
	if (code == ER_SETTINGS)
		ft_putendl_fd("Wrong map, check settings", 1);
	if (code == ER_TEXTURE)
		ft_putendl_fd("Error reading texture", 1);
	if (code == ER_SCREEN)
		ft_putendl_fd("Error making screenshot", 1);
	if (code == ER_OPEN)
		ft_putendl_fd("Error opening file", 1);
	if (code == ER_TEXTURESIZE)
		ft_putendl_fd("Textures sizes not equal each other", 1);
	if (code == MALLOC)
		ft_putendl_fd("Memory allocation error", 1);
	exit_free(s);
}
