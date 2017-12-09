/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/09 13:25:50 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_realloc_and_copy(char *str, char *str_to_add)
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

char	*ft_copy_a_line(char *str)
{
	char *copy;
	int count;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count] != '\n' || str[count] != '\0')
		count++;
	copy = ft_strnew(count);
	ft_strncpy(copy, str, count);
	return (copy);
}


t_fd_list	*get_node(int fd, t_fd_list *list)
{
	t_fd_list current;

	if (list && list->fd == fd)
		return (list);
	while (list->fd != fd && list->next)
		list = list->next;
	if (list->fd == fd)
		return (list);
	return (0);
}

t_fd_list	*new_node(int fd, char *overflow, t_fd_list next)
{
	t_fd_list *new;

	if (!(new = (t_fd_list*)malloc(sizeof(t_fd_list))))
		return (NULL);
	new->overflow = overflow;
	new->fd = fd;
	new->next = NULL;
	return (new);
}

//copy_after_first_return()

int			get_next_line(const int fd, char **line)
{
	static t_fd_list	*list;
	char				*temp

	list = NULL;
	if (!read(fd, get_node(fd, list)->
	
}
