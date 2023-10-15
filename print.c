/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapenko <aapenko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:04:27 by aapenko           #+#    #+#             */
/*   Updated: 2023/10/15 17:16:39 by aapenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	print_value(char *str, char *temp)
{
	int	i;

	i = 0;
	if (!str)
	{
		while (temp[i] && temp[i] != '\n')
			write(1, &temp[i++], 1);
		write(1, ": Not found.\n", 13);
		return ;
	}
	while (str[i])
		write(1, &str[i++], 1);
}
