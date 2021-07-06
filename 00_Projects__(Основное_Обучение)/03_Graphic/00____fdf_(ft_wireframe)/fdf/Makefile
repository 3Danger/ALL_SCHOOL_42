NAME=fdf
WWW=-Wall -Wextra -Werror
FILES_C=utils/libft/ft_strlen.c \
		utils/libft/ft_memchr.c \
		utils/libft/ft_atoi.c \
		utils/libft/ft_isdigit.c \
		utils/libft/ft_isprint.c \
		utils/libft/ft_putchar_fd.c \
		utils/libft/ft_putstr_fd.c \
		utils/libft/ft_split.c \
		utils/libft/ft_strchr.c \
		utils/libft/ft_strlcpy.c \
		utils/utils.c \
		utils/valid_map/hex_scan.c \
		utils/valid_map/valid_map.c \
		utils/valid_map/hand_sub.c \
		utils/minlibx_utils/minlibx_utils.c \
		utils/list_maps/list_maps.c \
		utils/list_maps/list_maps_free.c \
		utils/valid_map/maps_init_coodinate.c \
		utils/isometric.c \
		utils/run.c \
		main.c

FILES_O=$(FILES_C:%.c=%.o)
FILES_H=./mlx.h \
		./main_header.h

all: $(NAME)

$(NAME): $(FILES_O) $(FILES_H)
	@gcc $(FILES_O) -o $@ -lmlx -framework OpenGL -framework AppKit
.o: .c
	@gcc $(WWW) $? -o $@
clean:
	@rm -rf $(FILES_O)
fclean:
	@rm -rf $(FILES_O)
	@rm -rf $(NAME)
re: fclean all clean

.PHONY: all clean fclean re
