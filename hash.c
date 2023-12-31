/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapenko <aapenko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:49:28 by lbapart           #+#    #+#             */
/*   Updated: 2023/10/15 20:29:41 by aapenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

unsigned int	hash(const char *str, int max)
{
	unsigned long	hash;

	hash = 5381;
	while (*str && *str != '\n')
	{
		hash = ((hash << 5) + hash) + *str;
		str++;
	}
	return (hash % max);
}

int	put_key_and_val(char *key, char *value, int max, t_list **array)
{
	unsigned int	index;
	t_list			*temp;

	index = hash(key, max);
	if (!array[index])
		assign_node(array[index], key, value);
	else
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (!temp)
			return (0);
		assign_node(temp, key, value);
		temp->next = array[index];
		array[index] = temp;
	}
	return (1);
}

int	find_in_keys(char *str, t_list *node)
{
	int		len;
	int		i;
	t_list	*temp;

	i = 0;
	len = ft_strlen(str);
	temp = node;
	while (temp && temp->key)
	{
		if (ft_strncmp(str, temp->key, len + 1) == 0)
		{
			return (i);
		}
		i++;
		temp = temp->next;
	}
	return (-1);
}

char	*get_value_from_key(char *str, int max, t_list **array)
{
	int		index;
	int		val_index;
	t_list	*temp;
	int		i;

	index = hash(str, max);
	if (array[index] && array[index]->key)
	{
		val_index = find_in_keys(str, array[index]);
		if (val_index != -1)
		{
			i = 0;
			temp = array[index];
			while (i++ < val_index)
			{
				temp = temp->next;
			}
			return (temp->value);
		}
	}
	return (NULL);
}
