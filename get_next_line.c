/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapenko <aapenko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:30:01 by aapenko           #+#    #+#             */
/*   Updated: 2023/10/15 20:00:50 by aapenko          ###   ########.fr       */
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

char	*end_get_next_line(char **buffer, int i, int fd)
{
	char	*res;
	int		j;

	if (i == 0)
		return (free_buf(buffer), NULL);
	i = 0;
	while ((*buffer)[i])
		i++;
	if ((*buffer)[i - 1] != '\n')
		close(fd);
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

char	*get_next_line(int fd)
{
	int			read_bytes;
	char		*temp;
	static char	*buffer = NULL;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		if (is_newline(buffer))
			return (end_get_next_line(&buffer, ft_strlen(buffer), fd));
		temp = (char *)malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (NULL);
		temp[0] = '\0';
		read_bytes = read(fd, temp, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_buf(&buffer), free_buf(&temp), NULL);
		temp[read_bytes] = '\0';
		buffer = ft_realloc(&buffer, &temp);
		if (!buffer)
			return (NULL);
		if (read_bytes < BUFFER_SIZE)
			return (end_get_next_line(&buffer, ft_strlen(buffer), fd));
	}
	return (end_get_next_line(&buffer, ft_strlen(buffer), fd));
}
