/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:17:46 by ldulling          #+#    #+#             */
/*   Updated: 2023/10/14 13:18:32 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// DELETE
#include <stdio.h>

# define BUFFERSIZE 300000
# define MALLOC_ERR -2
# define FD_ERR -1
# define NOT_END_FILE 0
# define END_FILE 1

typedef struct		s_list
{
    char			*key;
    char			*value;
    struct s_list	*next;
}					t_list;

void	*ft_calloc(int bytes);
char	*read_out(int fd, int *result);

#endif
