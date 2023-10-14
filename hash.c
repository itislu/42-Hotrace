/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapenko <aapenko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:49:28 by lbapart           #+#    #+#             */
/*   Updated: 2023/10/14 21:35:34 by aapenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

// unsigned int hash(char *str, int max)
// {
// 	int h;

// 	h = 0;
// 	while (*str)
// 		h = (h << 4) + *str++;
// 	return (h % max);
// }

unsigned int hash(const char *str, int max) 
{
    unsigned long hash;
	int c;

	hash = 5381;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % max;
}

int	put_key_and_val(char *key, char *value, int max, t_list *array)
{
	unsigned int index;

	index = hash(key, max);
	printf("%d\n", index);
	if (!array[index].key)
		assign_node(&array[index], key, value);
	else
	{
		t_list *tmp;
		tmp = (t_list *)malloc(sizeof(t_list));
		if (!tmp)
			return (free(key), free(value), 0);
		assign_node(tmp, key, value);
		tmp->next = &array[index];
		array[index] = *tmp;
	}
	return (1);
}

int		find_in_keys(char *str, t_list *node)
{
	int len;
	int	i;
	t_list *temp;

	i = 0;
	len = ft_strlen(str);
	temp = node;
	while (temp->key)
	{
		if (ft_strncmp(str, temp->key, len + 1) == 0)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}

char	*get_value_from_key(char *str, int max, t_list *array)
{
	int	index;
	int val_index;
	t_list *temp;
	int i;

	index = hash(str, max);
	if (array[index].key)
	{
		val_index = find_in_keys(str, &array[index]);
		if (val_index != -1)
		{
			i = 0;
			temp = &array[index];
			while (i++ < val_index)	
			{
				temp = temp->next;
			}
			// printf("%s\n", temp->next->value);
			return (temp->value);
		}
	}
	return (NULL);
}