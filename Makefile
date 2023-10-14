# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aapenko <aapenko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 12:48:32 by ldulling          #+#    #+#              #
#    Updated: 2023/10/14 20:37:01 by aapenko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			hotrace
I				=			./
D				=			build/dep/
O				=			build/obj/

SRC				=			get_next_line.c \
							get_next_line_2.c \
							hash.c \
							lst_utils.c \
							main.c \
							print.c \
							utils.c

CC				=			cc
CFLAGS			=			-Wall -Wextra -Werror $(foreach X,$I,-I$(X))

DEP				=			$(SRC:%.c=$D%.d)
OBJ				=			$(SRC:%.c=$O%.o)

.PHONY:						all clean fclean re

all:						$(NAME)

$(NAME):					$(OBJ)
							$(CC) $(CFLAGS) $^ -o $@

$(OBJ): $O%.o:	%.c | $O
							$(CC) $(CFLAGS) -c $< -o $@

$(DEP): $D%.d:				%.c | $D
							$(CC) $(CFLAGS) -MM -MP -MF $@ -MT "$O$*.o $@" $<

$O $D:
							mkdir -p $@

cleandep:
							rm -f $(wildcard $(DEP))

cleandepdir:				cleandep
							rm -rf $D

cleanobj:
							rm -f $(wildcard $(OBJ))

cleanobjdir:				cleanobj
							rm -rf $O

clean:						cleandepdir cleanobjdir
							rm -rf build/

fclean:						clean
							rm -f $(NAME)

re:							fclean all

-include 					$(DEP)
