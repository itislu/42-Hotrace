/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:17:46 by ldulling          #+#    #+#             */
/*   Updated: 2023/10/14 23:48:14 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 300000
# define MALLOC_ERR -2
# define FD_ERR -1
# define NOT_END_FILE 0
# define END_FILE 1
# define FD 1

typedef struct s_list
{
	char			*key;
	char			*value;
	struct s_list	*next;
}					t_list;

// get_next_line.c
char			*get_next_line(int fd);
// get_next_line_2.c
int				is_newline(char *str);
void			free_buf(char **buf);
char			*ft_realloc(char **old_buf, char **c);
int				delete_output(char	**buffer);
char			*end_get_next_line(char **buffer, int i);
// hash.c
int				put_key_and_val(char *key, char *value, int max, t_list *array);
unsigned int	hash(const char *str, int max);
int				find_in_keys(char *str, t_list *node);
char			*get_value_from_key(char *str, int max, t_list *array);
// lst_utils.c
void			assign_node(t_list *node, char *key, char *value);
// print.c
void			print_value(char *str, char *temp);
// utils.c
int				ft_strlen(char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *src);

#endif
