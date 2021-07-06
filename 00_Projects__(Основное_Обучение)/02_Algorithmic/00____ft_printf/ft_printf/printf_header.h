#ifndef PRINTF_HEADER_H
# define PRINTF_HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define ALLOW ".0123456789* +-"
# define TYPE "%%csidupxX"

typedef struct s_el
{
	char	*res;
	int		type;
	int		width;
	int		precission;
	short	width_in_format;
	short	is_width;
	short	is_precission;
	short	is_dot;
	short	is_space;
	short	is_minus;
	short	is_plus;
	short	is_zero;

}	t_el;
t_el	el_set_defaults(void);
int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int symbol);
void	*ft_memchr(void *str, int c, size_t n);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
t_el	parse_check_for_flag(t_el el, va_list args, const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
int		ft_isdigit(int c);
t_el	el_to_res(t_el el, va_list args);
t_el	res_calculation(t_el el);
void	*ft_memset(void *dest, int c, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_hex_gen_long(long dec);
char	*ft_hex_gen_int(int dec, char c);
char	*concatenate(char *s1, char *s2);
char	*concatenate_fr1(char *s1, int size1, char *s2, int size2);
char	*concat_fr2(char *s1, char *s2);
char	*concatenate_frbth(char *s1, int size1, char *s2, int size2);
char	*ft_strnew(size_t size);
t_el	string_fill(t_el el);
int		max_min(int a, int b, int c);
int		is_minus(const char *str, t_el el);
void	minus_move(char	*str);
t_el	digit_fill(t_el el);
#endif