/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapenko <aapenko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:20:33 by ldulling          #+#    #+#             */
/*   Updated: 2023/10/15 17:33:01 by aapenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	init_dict(t_list **dict)
{
	int	i;

	i = 0;
	while (i < ARRAY_SIZE)
	{
		dict[i] = (t_list *)malloc(sizeof(t_list));
		if (!dict[i])
			return (0);
		dict[i]->key = NULL;
		dict[i]->value = NULL;
		dict[i]->next = NULL;
		i++;
	}
	return (1);
}

void	assign_and_free(char *temp, int	*is_search)
{
	free(temp);
	*is_search = 1;
	temp = NULL;
}

void	check_edge_case(int is_search, int count, char *key)
{
	if (is_search == 0 && count % 2 == 1)
		free(key);
}

void	hotrace(t_list **dict, int is, int *c, char *key)
{
	char	*temp;

	while (1)
	{
		temp = get_next_line(FD);
		if (!temp)
			return (check_edge_case(is, *c, key));
		if (ft_strncmp(temp, "\n", 2) == 0 && is == 1)
			(print_value(NULL, temp), free(temp));
		else if (ft_strncmp(temp, "\n", 2) == 0 && *c % 2 == 0)
			assign_and_free(temp, &is);
		else if (((ft_strncmp(temp, "\n", 2) == 0) || (is == 0 && *c % 2 == 1)))
		{
			if (!put_key_and_val(key, temp, ARRAY_SIZE, dict))
				return ;
		}
		else if (is == 0)
			key = temp;
		else if (is == 1)
		{
			key = get_value_from_key(temp, ARRAY_SIZE, dict);
			(print_value(key, temp), free(temp));
		}
		(*c)++;
	}
}

int	main(void)
{
	int		count;
	t_list	**dict;
	char	*key;

	key = NULL;
	dict = (t_list **)malloc(sizeof(t_list *) * ARRAY_SIZE);
	if (!dict)
		return (1);
	if (!init_dict(dict))
		return (free_all(dict), 1);
	count = 0;
	hotrace(dict, 0, &count, key);
	free_all(dict);
}
