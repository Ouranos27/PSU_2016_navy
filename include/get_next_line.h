/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:06:51 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/01/23 15:34:11 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 42

struct	struct_gnl
{
	char			*st_str;
	int			size;
	int			fd;
	char			*str;
	char			*tmp;
	struct	struct_gnl	*next;
};
int		get_next_line(const int fd, char **line);

#endif
