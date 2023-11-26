/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:31:32 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/24 15:48:19 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_findfirstdim(char const *s, char c)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (result);
}

char	**ft_splitbis(const char *s, char c, char **result, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (s[j] == c && s[j])
			j++;
		len = 0;
		while (s[j + len] != c && s[j + len])
			len++;
		result[i] = malloc((len + 1) * sizeof(char));
		if (result[i] == NULL)
			return (NULL);
		ft_strlcpy(result[i], &s[j], len + 1);
		j += len;
		i++;
	}
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	size;

	size = ft_findfirstdim(s, c);
	result = malloc((size + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result[size] = NULL;
	result = ft_splitbis(s, c, result, size);
	if (result == NULL)
		free(result);
	return (result);
}
/*
int	main ()
{
	ft_split("Tripouille", ' ');
}*/
