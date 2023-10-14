/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:20:33 by ldulling          #+#    #+#             */
/*   Updated: 2023/10/14 23:35:27 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	init_dict(t_list *dict)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		dict[i].key = NULL;
		dict[i].value = NULL;
		dict[i].next = NULL;
		i++;
	}
}

void	hotrace(t_list *dict, int is_search, int *count)
{
	char	*temp;
	char	*key;

	while (1)
	{
		temp = get_next_line(FD);
		if (!temp)
			break ;
		if (ft_strncmp(temp, "\n", 2) == 0 && is_search == 1)
			print_value(NULL, temp);
		else if (ft_strncmp(temp, "\n", 2) == 0 && *count % 2 == 0)
			is_search = 1;
		else if (ft_strncmp(temp, "\n", 2) == 0)
			put_key_and_val(key, temp, BUFFER_SIZE, dict);
		else if (is_search == 0 && *count % 2 == 1)
			put_key_and_val(key, temp, BUFFER_SIZE, dict);
		else if (is_search == 0)
			key = temp;
		else if (is_search == 1)
		{
			key = get_value_from_key(temp, BUFFER_SIZE, dict);
			print_value(key, temp);
		}
		(*count)++;
	}
}

void	free_all(t_list *dict)
{
	int		i;
	t_list	*current;
	t_list	*temp;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		current = &dict[i];
		while (current)
		{
			temp = current;
			current = current->next;
			if (temp->key)
				free(temp->key);
			if (temp->value)
				free(temp->value);
			free(temp);
		}
		i++;
	}
	free(dict);
}

int	main(void)
{
	int		count;
	t_list	*dict;

	dict = (t_list *)malloc(sizeof(t_list) * BUFFER_SIZE);
	if (!dict)
		return (1);
	count = 0;
	init_dict(dict);
	hotrace(dict, 0, &count);
	//free_all(dict);
}
