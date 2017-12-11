/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/11 13:33:00 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*realloc_and_copy(char *str, char *str_to_add)
{
	char *copy;

	if (!(copy = ft_strnew(ft_strlen(str))))
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

static char	*ft_copy_a_line(char *str)
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

int			get_next_line(const int fd, char **line)
{
	static char *temp;

	temp = NULL;
	if (!(temp = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!read(fd, temp, BUFF_SIZE))
		return (0);
	while (!ft_strchr(*line, '\n'))
	{
		if (temp)
		{
			*line = realloc_and_copy(*line, ft_copy_a_line(temp));
			temp = ft_strchr(temp, '\n');
		}
		else if (!read(fd, temp, BUFF_SIZE))
			return (0);
	}
	return (1);
}
