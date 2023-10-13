/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbapart <lbapart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:58:28 by lbapart           #+#    #+#             */
/*   Updated: 2023/10/13 22:00:31 by lbapart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void    assign_node(t_list *node, char *key, char *value)
{
    node->key = key;
    node->value = value;
    node->next = NULL;
}