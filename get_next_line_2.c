/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapenko <aapenko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:30:01 by aapenko           #+#    #+#             */
/*   Updated: 2023/10/14 21:39:03 by aapenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*get_next_line(int fd)
{
	int		read_bytes;
	char	*temp;
	static char	*buffer = NULL;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	temp[0] = '\0';
	read_bytes = 1;
	while (read_bytes > 0)
	{
		if (is_newline(buffer))
			return (free(temp), finish_get_next_line(&buffer, ft_strlen(buffer)));
		read_bytes = read(fd, temp, BUFFER_SIZE);
		temp[read_bytes] = '\0';
		if (read_bytes == -1)
			return (free_buf(&buffer), free_buf(&temp), NULL);
		else if (read_bytes == 0)
			return (free(temp), finish_get_next_line(&buffer, ft_strlen(buffer)));
		buffer = ft_realloc(&buffer, &temp);
		if (!buffer)
			return (NULL);
	}
	return (finish_get_next_line(&buffer, ft_strlen(buffer)));
}