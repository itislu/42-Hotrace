/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:20:33 by ldulling          #+#    #+#             */
/*   Updated: 2023/10/15 16:50:08 by ldulling         ###   ########.fr       */
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
}

void	hotrace(t_list **dict, int is_search, int *count, int fd)
{
	char	*temp;
	char	*key;

	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			return ;
		if (ft_strncmp(temp, "\n", 2) == 0 && is_search == 1)
			(print_value(NULL, temp), free(temp));
		else if (ft_strncmp(temp, "\n", 2) == 0 && *count % 2 == 0)
			assign_and_free(temp, &is_search);
		else if ((ft_strncmp(temp, "\n", 2) == 0) || (is_search == 0 && *count
		% 2 == 1)
			put_key_and_val(key, temp, ARRAY_SIZE, dict);
		else if (is_search == 0 && *count % 2 == 1)
			put_key_and_val(key, temp, ARRAY_SIZE, dict);
		else if (is_search == 0)
			key = temp;
		else if (is_search == 1)
		{
			key = get_value_from_key(temp, ARRAY_SIZE, dict);
			(print_value(key, temp), free(temp));
		}
		(*count)++;
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
			while(temp)
			{
				current = temp;
				if (temp->key)
				{
					free(temp->key);
					temp->key = NULL;
				}
				if (temp->value)
				{
					free(temp->value);
					temp->value = NULL;
				}
				temp = temp->next;
				free(current);
				current = NULL;
			}
		}
		i++;
	}
	free(dict);
}

int	main(void)
{
	int		count;
	t_list	**dict;

	dict = (t_list **)malloc(sizeof(t_list *) * ARRAY_SIZE);
	if (!dict)
		return (1);
	if (!init_dict(dict))
		return (free_all(dict), 1);
	count = 0;
// int fd = open(PATH, O_RDONLY);
	hotrace(dict, 0, &count, FD);
	free_all(dict);
}
