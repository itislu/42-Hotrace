/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:56:36 by lbapart           #+#    #+#             */
/*   Updated: 2023/10/14 23:55:56 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	is_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	free_buf(char **buf)
{
	if (*buf)
		free(*buf);
	*buf = NULL;
}

char	*ft_realloc(char **old_buf, char **c)
{
	int		len_buf;
	int		len_c;
	char	*res;
	int		i;
	int		j;

	len_buf = ft_strlen(*old_buf);
	len_c = ft_strlen(*c);
	res = (char *)malloc(len_buf + len_c + 1);
	if (!res)
		return (free_buf(old_buf), free_buf(c), NULL);
	i = 0;
	while (*old_buf && (*old_buf)[i])
	{
		res[i] = (*old_buf)[i];
		i++;
	}
	j = 0;
	while (*c && (*c)[j])
		res[i++] = (*c)[j++];
	res[i] = '\0';
	free_buf(old_buf);
	free_buf(c);
	return (res);
}

int	delete_output(char	**buffer)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = 0;
	if (!*buffer)
		return (1);
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	len = ft_strlen(*buffer) - i;
	if (len == 0)
		return (free_buf(buffer), 1);
	res = (char *)malloc(len + 1);
	if (!res)
		return (free_buf(buffer), 0);
	j = 0;
	while ((*buffer)[i])
		res[j++] = (*buffer)[i++];
	res[j] = '\0';
	free_buf(buffer);
	*buffer = res;
	return (1);
}

char	*end_get_next_line(char **buffer, int i)
{
	char	*res;
	int		j;

	if (i == 0)
		return (free_buf(buffer), NULL);
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	res = (char *)malloc(i + 1);
	if (!res)
		return (free_buf(buffer), NULL);
	j = 0;
	while (j < i)
	{
		res[j] = (*buffer)[j];
		j++;
	}
	res[j] = '\0';
	if (!delete_output(buffer))
		return (free_buf(&res), NULL);
	return (res);
}
