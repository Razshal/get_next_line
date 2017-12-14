/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/14 16:00:25 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_custom(char *s1, char *s2)
{
	char	*newstr;
	size_t	alloc_length;

	newstr = NULL;
	if (!s1 && s2)
		return (ft_strdup(s2));
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

static char	*after_n(char *str)
{
	char *after;

	if (str && str[0])
	{
		after = ft_strchr(str, '\n');
		after++;
		str = ft_strcpy(str, after);
	}
	return (str);
}

static int	fill_line(char **line, char *temp, const int fd)
{
	int cursor;

	cursor = 0;
	if (temp && temp[0])
		*line = ft_strjoin_custom(*line, copy_a_line(temp));
	if (!ft_strchr(temp, '\n') && (cursor = read(fd, temp, BUFF_SIZE)) < 1)
		return (cursor);
	if (cursor == 1)
		temp[cursor] = '\0';
	*line = ft_strjoin_custom(*line, copy_a_line(temp));
	if (ft_strchr(temp, '\n'))
		return (1);
	else
	{
		ft_memset(temp, '\0', BUFF_SIZE);
		return (fill_line(line, temp, fd));
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*temp;
	char			*local_line;
	unsigned int	cursor;

	cursor = 0;
	local_line = NULL;
	if (!temp && !(temp = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((cursor = fill_line(&local_line, temp, fd)) == 1)
	{
		temp = after_n(temp);
		*line = local_line;
		return (1);
	}
	else if (cursor == 0)
	{
		if (temp)
			ft_memdel((void**)&temp);
		return (0);
	}
	return (cursor);
}
