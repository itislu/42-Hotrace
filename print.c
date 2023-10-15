/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapenko <aapenko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:04:27 by aapenko           #+#    #+#             */
/*   Updated: 2023/10/15 21:03:38 by aapenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	print_value(char *str, char *temp)
{
	int	i;
	int len;

	i = 0;
	if (!str)
	{
		len = ft_strlen(temp);
		if (temp[len - 1] == '\n')
			write(1, temp, len - 1);
		else
			write(1, temp, len);
		write(1, ": Not found.\n", 13);
		return ;
	}
	len = ft_strlen(str);
	write(1, str, len);
}
