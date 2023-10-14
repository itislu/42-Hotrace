/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:02:33 by ldulling          #+#    #+#             */
/*   Updated: 2023/10/14 11:44:51 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	*ft_calloc(int bytes)
{
	unsigned char	*ptr;
	int		i;

	ptr = (unsigned char *) malloc(bytes);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < bytes)
		ptr[i++] = '\0';
	return ((void *) ptr);
}
