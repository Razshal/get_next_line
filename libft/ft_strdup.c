/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:58:13 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/14 11:58:54 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		count;
	int		length;
	char	*copy;

	count = 0;
	length = ft_strlen(s1);
	if (!(copy = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (count < length)
	{
		copy[count] = s1[count];
		count++;
	}
	copy[count] = '\0';
	return (copy);
}
