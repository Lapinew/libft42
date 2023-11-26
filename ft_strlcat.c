/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:43:07 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/19 14:58:02 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (size > 0 && dst[j])
		j++;
	i = 0;
	if (j < size)
	{
		while (src[i] && i < size - j - 1)
		{
			dst[j + i] = src[i];
			i++;
		}
		dst[j + i] = '\0';
	}
	else
		j = size;
	while (src[i])
		i++;
	return (j + i);
}
