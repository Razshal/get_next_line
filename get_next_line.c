/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/13 11:57:46 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*realloc_and_copy(char *str, char *str_to_add)
{
	char *copy;

	if (!str)
	{
		str = ft_strnew(ft_strlen(str_to_add));
		return (ft_strcpy(str, str_to_add));
	}
	if (!(copy = ft_strnew(ft_strlen(str))))
	{
		printf("NULL REALLOC\n");
		return (NULL);
	}
	if (!str_to_add)
	{
		printf("no str to add\n");
		return (str);
	}
	ft_strcpy(copy, str);
	str = ft_strnew(ft_strlen(copy) + ft_strlen(str_to_add) - 1);
	ft_strcat(str, copy);
	ft_strcat(str, str_to_add);
	ft_memdel((void**)&copy);
	ft_memdel((void**)&str_to_add);
				printf("str realloced :%s\n", str);
	return (str);
}

static char	*copy_a_line(char *str)
{
	char			*copy;
	unsigned int	count;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count] && str[count] != '\n')
		count++;
	copy = ft_strnew(count);
	ft_strncpy(copy, str, count);
	return (copy);
}

int			get_next_line(const int fd, char **line)
{
	static char		*temp;
	unsigned int	cursor;

	cursor = 0;
	if (!temp)
	{
		if (!(temp = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		if ((cursor = read(fd, temp, BUFF_SIZE)) < 1)
			return (cursor);
		temp[cursor] = '\0';
	}
	*line = ft_strnew(0);
	while (!ft_strchr(*line, '\n'))
	{

		*line = realloc_and_copy(*line, copy_a_line(temp));
		if (temp && ft_strchr(temp, '\n'))
		{
			temp = ft_strchr(temp, '\n') + 1;
			printf("temp :%s\n", temp);
			return (1);
		}
		else if ((cursor = read(fd, temp, BUFF_SIZE)) < 1)
		{
			ft_memdel((void**)&temp);
			return (cursor);
		}
		temp[cursor] = '\0';
	}
	return (1);
}
