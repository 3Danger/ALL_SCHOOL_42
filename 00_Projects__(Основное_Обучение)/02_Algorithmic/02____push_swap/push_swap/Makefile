NAME_M=push_swap
NAME_B=checker

# FILIES=$(shell find . -name "*.c" -exec echo {} \; -o -name "*.h" -exec echo {} \;)
MAIN_B=		./checker.c \
			./gnl/get_next_line.c \
			./gnl/get_next_line.h 

MAIN_M= 	./push_swap.c

FILIES=	./algorithm/alg_utils.c \
		./algorithm/alg_utils_2.c \
		./algorithm/algorithm.c \
		./utils/incoming_handler/incoming_handler.c \
		./utils/incoming_handler/utils_handler.c \
		./utils/list/list.c \
		./utils/list/list2.c \
		./utils/list/list_iarr_to_list.c \
		./utils/list/list_sub_utils.c \
		./utils/list/list_sub_utils_2.c \
		./utils/list/move.c \
		./utils/ops_story.c \
		./libft/ft_atoi.c \
		./libft/ft_bzero.c \
		./libft/ft_calloc.c \
		./libft/ft_isalnum.c \
		./libft/ft_isalpha.c \
		./libft/ft_isascii.c \
		./libft/ft_isdigit.c \
		./libft/ft_isprint.c \
		./libft/ft_itoa.c \
		./libft/ft_lstadd_back.c \
		./libft/ft_lstadd_front.c \
		./libft/ft_lstclear.c \
		./libft/ft_lstdelone.c \
		./libft/ft_lstiter.c \
		./libft/ft_lstlast.c \
		./libft/ft_lstmap.c \
		./libft/ft_lstnew.c \
		./libft/ft_lstsize.c \
		./libft/ft_memccpy.c \
		./libft/ft_memchr.c \
		./libft/ft_memcmp.c \
		./libft/ft_memcpy.c \
		./libft/ft_memmove.c \
		./libft/ft_memset.c \
		./libft/ft_putchar_fd.c \
		./libft/ft_putendl_fd.c \
		./libft/ft_putnbr_fd.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_split.c \
		./libft/ft_strchr.c \
		./libft/ft_strdup.c \
		./libft/ft_strjoin.c \
		./libft/ft_strlcat.c \
		./libft/ft_strlcpy.c \
		./libft/ft_strlen.c \
		./libft/ft_strmapi.c \
		./libft/ft_strncmp.c \
		./libft/ft_strnstr.c \
		./libft/ft_strrchr.c \
		./libft/ft_strtrim.c \
		./libft/ft_substr.c \
		./libft/ft_tolower.c \
		./libft/ft_toupper.c \
		./algorithm/alg_utils_proto.h \
		./utils/list/list.h \
		./libft/libft.h \
		./push_swap.h



all: $(NAME_M)
$(NAME_M): $(FILIES) $(MAIN_M)
	@gcc -Wall -Werror -Wextra $(FILIES) $(MAIN_M)
	@mv a.out $(NAME_M)

bonus: $(NAME_B)
$(NAME_B): $(FILIES) $(MAIN_B)
	@gcc -Wall -Werror -Wextra $(FILIES) $(MAIN_B)
	@mv a.out $(NAME_B)

debug_b:
	@gcc -g -Wall -Werror -Wextra $(FILIES) $(MAIN_B)

clean:
	@rm -rf a.out
	@rm -rf a.out.dSYM
	@rm -rf $(shell find . -name "*.gch" -exec echo {} \;)

fclean: clean
	@rm -rf $(NAME_M)
	@rm -rf $(NAME_B)
	@find . -name "*.tmp" -exec rm -rf {} +;
re: fclean build clean

.PHONY: build show clean fclean re all