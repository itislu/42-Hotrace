/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapenko <aapenko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:44:49 by lbapart           #+#    #+#             */
/*   Updated: 2023/10/14 20:37:54 by aapenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int ft_strlen(char *str)
{
    int i;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*first;
	unsigned char	*second;

	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	i = 0;
	while (first[i] && second[i] && i < n)
	{
		if (first[i] != second[i])
		{
			if (i + 1 == n && first[i + 1] == '\0' && second[i + 1] == '\n' && second[i + 2] == '\0')
				return (0);
			return (first[i] - second[i]);
		}
		i++;
	}
	if (i == n)
		return (0);
	return (first[i] - second[i]);
}

char	*ft_strdup(const char *src)
{
	char	*new_str;
	int		i;

	i = 0;
	while (src[i])
		i++;
	new_str = (char *)malloc(i + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}