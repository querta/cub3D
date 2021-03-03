/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:16:45 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/03 17:26:47 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define BUFFER_SIZE 100

# include "../src/libft/libft.h"

int		get_next_line(int fd, char **line);
int		ft_isspace(char c);
int		ft_isnumstr(char *s);
void	freearr(char **arr);
int		arrsize(char **arr);
int		check_mapsign(char c);

#endif
