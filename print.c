/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:04:27 by aapenko           #+#    #+#             */
/*   Updated: 2023/10/14 23:25:16 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	print_value(char *str, char *temp)
{
	int	i;

	if (!str)
	{
		write(1, temp, ft_strlen(temp) - 1);
		write(1, ": Not found.\n", 13);
		return ;
	}
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
