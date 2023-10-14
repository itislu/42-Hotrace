/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:56:36 by lbapart           #+#    #+#             */
/*   Updated: 2023/10/14 13:05:57 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_realloc(char *old_buf, int total)
{
	int		i;
	char	*res;

	res = (char *)malloc(total + BUFFERSIZE);
	if (!res)
		return (free(old_buf), NULL);
	i = 0;
	while (i < total)
	{
		res[i] = old_buf[i];
		i++;
	}
	free(old_buf);
	return (res);
}

char	*finish_read_out(char *buffer, int i, int read_bytes)
{
	if (i <= 0 || (!buffer[i - 1] && !read_bytes))
		return (free(buffer), NULL);
	buffer[i] = '\0';
	return (buffer);
}

int	set_result(int *result, int value)
{
	*result = value;
	return (1);
}

char	*read_out(int fd, int *result)
{
	int		i;
	int		read_bytes;
	int		total;
	char	*buffer;

	buffer = (char *) malloc(BUFFERSIZE);
	if (!buffer)
		return (set_result(result, MALLOC_ERR), NULL);
	i = 0;
	total = 0;
	while (1)
	{
		read_bytes = read(fd, buffer + total, BUFFERSIZE);
		total += read_bytes;
		if (read_bytes == -1)
			return (set_result(result, FD_ERR), free(buffer), NULL);
		else if (set_result(result, NOT_END_FILE) && read_bytes < BUFFERSIZE)
		{
			set_result(result, END_FILE);
			break ;
		}
		buffer = ft_realloc(buffer, total);
		if (!buffer)
			return (NULL);
	}
	return (finish_read_out(buffer, total, read_bytes));
}
