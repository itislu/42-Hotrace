/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:04:27 by aapenko           #+#    #+#             */
/*   Updated: 2023/10/15 15:14:02 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	print_value(char *str, char *temp)
{
	int	i;

	if (!str)
	{
		if (temp[ft_strlen(temp) - 1] != '\n')
			write(1, temp, ft_strlen(temp));
		else
			write(1, temp, ft_strlen(temp) - 1);
		write(1, ": Not found.\n", 13);
		return ;
	}
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
