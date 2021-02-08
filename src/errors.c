/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:22:47 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/08 14:37:16 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void		lst_del(void *content)
{
	free(content);
}

int exit_free(t_set *s)
{
	ft_lstclear(&s->mlist, &lst_del);
	exit (0);
}

void error(t_set *s, int code)
{
	if (code == ER_MAP)
		ft_putendl_fd("Wrong map", 1);
	if (code == ER_SETTINGS)
		ft_putendl_fd("Wrong map, check settings", 1);
	exit_free (s);
}

// int		deal_exit(t_env *env)
// {
// 	ft_free_tabs(env);
// 	ft_free_img(env);
// 	ft_free_tex(env, env->tex1);
// 	ft_free_tex(env, env->tex2);
// 	ft_free_tex(env, env->tex3);
// 	ft_free_tex(env, env->tex4);
// 	ft_free_tex(env, env->sprite);
// 	if (env->win_ptr)
// 		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
// 	if (env->mlx_ptr)
// 		free(env->mlx_ptr);
// 	exit(0);
// }

// void	ft_free_tex(t_env *env, t_tex *tex)
// {
// 	if (tex)
// 	{
// 		mlx_destroy_image(env->mlx_ptr, tex->tex_ptr);
// 		free(tex);
// 		tex = NULL;
// 	}
// }

// void	ft_free_img(t_env *env)
// {
// 	if (env->img)
// 	{
// 		mlx_destroy_image(env->mlx_ptr, env->img->img_ptr);
// 		free(env->img);
// 		env->img = NULL;
// 	}
// }

// void	ft_free_tabs(t_env *env)
// {
// 	if (env->rc.zbuffer)
// 		free(env->rc.zbuffer);
// 	if (env->map.tab_map)
// 		ft_tabdel((void *)env->map.tab_map);
// 	if (env->data.r)
// 		free(env->data.r);
// 	if (env->data.no)
// 		free(env->data.no);
// 	if (env->data.so)
// 		free(env->data.so);
// 	if (env->data.we)
// 		free(env->data.we);
// 	if (env->data.ea)
// 		free(env->data.ea);
// 	if (env->data.f)
// 		free(env->data.f);
// 	if (env->data.c)
// 		free(env->data.c);
// 	if (env->data.spr)
// 		free(env->data.spr);
// }