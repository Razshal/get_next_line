/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:16:13 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/16 17:34:59 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

void	ft_putstr(char const *s)
{
	int count;

	count = -1;
	if (s)
	{
		while (s[++count] != '\0')
			ft_putchar(s[count]);
	}
}
