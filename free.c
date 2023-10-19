/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapenko <aapenko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:06:03 by aapenko           #+#    #+#             */
/*   Updated: 2023/10/15 17:07:04 by aapenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	free_buf(char **buf)
{
	if (*buf)
		free(*buf);
	*buf = NULL;
}

void	free_content(t_list *node)
{
	if (node->key)
	{
		free(node->key);
		node->key = NULL;
	}
	if (node->value)
	{
		free(node->value);
		node->value = NULL;
	}
}

void	free_all(t_list **dict)
{
	int		i;
	t_list	*temp;
	t_list	*current;

	i = 0;
	while (i < ARRAY_SIZE)
	{
		if (dict[i])
		{
			temp = dict[i];
			while (temp)
			{
				current = temp;
				free_content(temp);
				temp = temp->next;
				free(current);
				current = NULL;
			}
		}
		else
			break ;
		i++;
	}
	free(dict);
}
