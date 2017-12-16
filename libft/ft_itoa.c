/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:07:57 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/16 17:53:59 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		checkneg;
	long	num;

	size = ft_countdigit(n);
	checkneg = 0;
	num = n;
	if (num < 0)
	{
		size++;
		checkneg = 1;
		num = -num;
	}
	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	if (checkneg)
		str[0] = '-';
	str[size] = '\0';
	while (checkneg ? size > 1 : size >= 0)
	{
		str[--size] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}
