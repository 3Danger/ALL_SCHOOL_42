# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csamuro <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 11:35:14 by csamuro           #+#    #+#              #
#    Updated: 2021/04/17 11:51:51 by csamuro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
FUNC=ft_tolower.c ft_calloc.c ft_strdup.c\
	ft_isascii.c ft_isprint.c ft_toupper.c\
	ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	ft_strnstr.c ft_strncmp.c ft_atoi.c\
	ft_strlcat.c ft_strchr.c ft_strrchr.c\
	ft_strlen.c ft_memcmp.c ft_strlcpy.c\
	ft_memccpy.c ft_memmove.c ft_memchr.c\
	ft_memset.c ft_bzero.c ft_memcpy.c\
	ft_substr.c ft_strjoin.c ft_strtrim.c\
	ft_split.c ft_itoa.c ft_strmapi.c\
	ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c

FUNC_B=ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ=$(patsubst %.c, %.o, $(FUNC))
OBJ_B=$(patsubst %.c, %.o, $(FUNC_B))
DFILES=$(patsubst %.c, %.d, $(FUNC) $(FUNC_B))
MAIN=main.c
HEADER=libft.h

OPF=-O2
FLAGS=-Wall -Wextra -Werror

all: $(NAME)
$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(OPF) $(FLAGS) -c $< -o $@ -MD
include $(wildcard $(DFILES))

bonus:
	@make OBJ="$(OBJ) $(OBJ_B)" all
clean:
	rm -f $(OBJ) $(OBJ_B) $(DFILES)
fclean: clean
	rm -f $(NAME) a.out
re: fclean all bonus

.PHONY : all clean fclean re bonus
