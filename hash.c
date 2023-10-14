/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbapart <lbapart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:49:28 by lbapart           #+#    #+#             */
/*   Updated: 2023/10/14 01:24:21 by lbapart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

unsigned int hash(char *str, int max)
{
	int h;

	h = 0;
	while (*str)
		h = (h << 4) + *str++;
	return (h % max);
}

// unsigned long hash(const char *str) {
//     unsigned long hash = 5381;
//     int c;

//     while ((c = *str++)) {
//         hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
//     }

//     return hash;
// }

int	put_in_array(char *key, char *value, int max, t_list *array)
{
	int index;
	char *key_to_put;
	char *value_to_put;

	index = hash(key, max);
	key_to_put = ft_strdup(key);
	if (!key)
		return (0);
	value_to_put = ft_strdup(value);
	if (!value)
		return (free(key_to_put), NULL);
	if (!array[index].key)
		assign_node(&array[index], key_to_put, value_to_put);
	else
	{
		t_list *tmp;
		tmp = (t_list *)malloc(sizeof(t_list));
		if (!tmp)
			return (free(key_to_put), free(value_to_put), NULL);
		assign_node(tmp, key_to_put, value_to_put);
	}
}