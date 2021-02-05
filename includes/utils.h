/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:16:45 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/05 19:14:29 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../src/libft/libft.h"

int		get_next_line(int fd, char **line);
int		ft_isspace(char c);
char	*strstart(char *str);


#endif