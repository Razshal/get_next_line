/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:41:18 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/11 18:28:53 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		count;

	count = 0;
	while (s[count] != c && s[count])
		count++;
	if (s[count] == c)
		return (&((char*)s)[count]);
	else
		return (NULL);
}
