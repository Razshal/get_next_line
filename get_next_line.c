/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/16 12:54:35 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_custom(char *s1, char *s2)
{
	char	*newstr;
	size_t	alloc_length;

	newstr = NULL;
	if (!s1 && s2)
		return (s2);
	if (s1 && s2)
	{
		alloc_length = (size_t)(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!(newstr = ft_strnew(alloc_length)))
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
	if (!(copy = ft_strnew(count)))
		return (NULL);
	ft_strncpy(copy, str, count);
	return (copy);
}

static char	*after_n(char *str)
{
	char *after;

	if (str && str[0])
	{
		after = ft_strchr(str, '\n');
		if (after && after[0])
		{
			after++;
			str = ft_strcpy(str, after);
		}
		else
			ft_memset(str, '\0', BUFF_SIZE);
	}
	return (str);
}

static int	fill_line(char **line, char *temp, const int fd)
{
	long cursor;

	cursor = 0;
	if (temp[0])
	{
		*line = ft_strjoin_custom(*line, copy_a_line(temp));
		if (ft_strchr(temp, '\n'))
			return (1);
	}
	while ((cursor = read(fd, temp, BUFF_SIZE)))
	{
		if (cursor < 1)
			return (cursor);
		temp[cursor] = '\0';
		*line = ft_strjoin_custom(*line, copy_a_line(temp));
		if (ft_strchr(temp, '\n'))
			return (1);
		else
			temp[0] = '\0';
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		*temp;
	char			*local_line;
	long			cursor;

	cursor = 0;
	local_line = NULL;
	if ((!temp && !(temp = ft_strnew(BUFF_SIZE)))
			|| BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	cursor = fill_line(&local_line, temp, fd);
	if (cursor == -1)
		return (-1);
	if (local_line && cursor >= 0)
	{
		temp = after_n(temp);
		*line = local_line;
		if (!temp[0])
			ft_memdel((void**)&temp);
		return (1);
	}
	if (cursor == 0 && temp)
		ft_memdel((void**)&temp);
	return (cursor);
}
