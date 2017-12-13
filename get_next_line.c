/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/13 16:05:38 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_custom(char *s1, char *s2)
{
	char	*newstr;
	size_t	alloc_length;

	newstr = NULL;
	if (s1 && s2)
	{
		alloc_length = (size_t)(ft_strlen(s1) + ft_strlen(s2) + 1);
		newstr = (ft_strnew(alloc_length));
		if (newstr == NULL)
			return (NULL);
		ft_strcat(newstr, s1);
		ft_strcat(newstr, s2);
		free(s1);
		free(s2);
	}
	return (newstr);
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

static int	fill_line(char **line, char *temp, const int fd)
{
	int cursor;

	cursor = 0;
	while (temp && !ft_strchr(temp, '\n'))
	{
		*line = ft_strjoin_custom(*line, copy_a_line(temp));
		if ((cursor = read(fd, temp, BUFF_SIZE)) < 1)
		{
			ft_memdel((void**)&*line);
			return (cursor);
		}
		else
			return (fill_line(line, temp, fd));
	}
	if (ft_strchr(temp, '\n'))
	{
		*line = ft_strjoin_custom(*line, copy_a_line(temp));
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		*temp;
	char			*swap;
	unsigned int	cursor;

	cursor = 0;
	if (!temp)
	{
		if (!(temp = ft_strnew(BUFF_SIZE)))
			return (-1);
		if ((cursor = read(fd, temp, BUFF_SIZE)) < 1)
			return (cursor);
		temp[cursor] = '\0';
	}
	*line = ft_strnew(0);
	if ((cursor = fill_line(line, temp, fd)) == 1)
	{
		swap = ft_strdup(ft_strchr(temp, '\n') + 1);
		free(temp);
		temp = swap;
		swap = NULL;
		return (1);
	}
	else if (cursor == 0)
	{
		ft_memdel((void**)&temp);
		return (0);
	}
	return (cursor);
}
