name = libftprintf.a
flags = -Wall -Wextra -Werror
header = printf_header.h
filies = el_set_defaults.c\
		el_to_res.c\
		ft_atoi.c\
		ft_isdigit.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_printf.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlen.c\
		parse_check_for_flag.c\
		res_calculation.c\
		ft_memset.c\
		ft_memcpy.c\
		ft_hex_gen.c\
		concatenate.c\
		ft_strnew.c\
		string_fill.c\
		digit_fill.c\
		utils.c

obj = $(patsubst %.c, %.o, $(filies))

all: $(name)

$(name) : $(obj)
	ar rcs $(name) $? $(header)
%.o : %.c
	gcc $(flags) -c $(filies)

clean:
	rm -rf $(obj) *.dSYM
fclean: clean
	rm -rf $(name)

re: fclean all clean

.PHONY: all clean fclean re
