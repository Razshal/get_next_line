/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:03:53 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/08 18:16:18 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include "libft/libft.h"

int get_next_line(const int fd, char **line);
#define BUFF_SIZE 32

typedef struct	s_fd_list
{
	char	*str;
	int		fd;
	int		line;
}				t_fd_list;

#endif
