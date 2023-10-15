/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:30:01 by aapenko           #+#    #+#             */
/*   Updated: 2023/10/15 16:25:51 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	ft_strlen_test(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	int			read_bytes;
	char		*temp;
	static char	*buffer = NULL;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		temp = (char *)malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (NULL);
		temp[0] = '\0';
		if (is_newline(buffer))
			return (free(temp), end_get_next_line(&buffer, ft_strlen(buffer)));
		read_bytes = read(fd, temp, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_buf(&buffer), free_buf(&temp), NULL);
		else if (read_bytes == 0)
			return (free(temp), end_get_next_line(&buffer, ft_strlen(buffer)));
		temp[read_bytes] = '\0';
		buffer = ft_realloc(&buffer, &temp);
		if (!buffer)
			return (NULL);
	}
	return (end_get_next_line(&buffer, ft_strlen(buffer)));
}
