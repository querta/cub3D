/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:57:56 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/25 19:08:46 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../src/libft/libft.h"
# include "./utils.h"
# include <fcntl.h>

typedef	struct	s_settings
{
	char *r;
	char *no;
	char *so;
	char *we;
	char *ea;
	char *s;
	char *f;
	char *c;
}				t_set;


int				main(int argc, char **argv);
char			**main_parser(int argc, char *argv, t_set *set, t_list **head);

#endif