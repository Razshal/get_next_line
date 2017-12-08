/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/08 19:13:53 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_realloc(char *str, char *str_to_add)
{
	char *copy;

	if (!str || !(copy = ft_strnew(ft_strlen(str))))
		return (NULL);
	if (!str_to_add)
		return (str);
	ft_strcpy(copy, str);
	ft_memdel((void*)&str);
	str = ft_strnew(ft_strlen(copy) + ft_strlen(str_to_add) - 1);
	ft_strcat(str, copy);
	ft_strcat(str, str_to_add);
	ft_memdel((void*)&copy);
	return (str);
}



int get_next_line(const int fd, char **line)
{
	static f_list *list;

	list = NULL;
	
	
}
