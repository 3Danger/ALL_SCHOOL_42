#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define ROTATE 0.75
# define STRETH_HEIGHT 0.7
# define STRETH_WIDTH 0.7
# define WIDTH 1024
# define HEIGHT 968
# define LEFT -6
# define LEFT_TO_END -5

# define RIGHT -4
# define RIGHT_TO_END -3

# define DOWN_TO_END -2
# define DOWN -1
# define UP 1
# define UP_TO_END 2

typedef struct s_color
{
	float	t;
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_mlx
{
	void	*pt;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_pixel
{
	double		x;
	double		y;
	double		z;
}	t_pixel;

typedef struct s_maps
{
	int				height;
	t_color			color;
	t_pixel			pix;
	struct s_maps	*left;
	struct s_maps	*right;
	struct s_maps	*up;
	struct s_maps	*down;
}	t_maps;

void			run_nigga(t_maps *maps, t_mlx *mlx);
t_color			get_hex_ishex(char *str);
t_maps			*hand_iarr(char **mapline2);
t_color			color_get_i(int	res_hex);
int				color_get_c(t_color color);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
t_maps			*hand_data_iarr(const char *path);
void			maps_init_coodinate(t_maps *maps);

void			print_line(t_maps a, t_maps b, t_mlx *mlx);
double			get_dmax(double a, double b);
double			get_dmin(double a, double b);
double			d_sgn(double val, short sign);
int				file_len(const char *path);
double			mid_point(int hw, double a, double b);
t_maps			*maps_new_el(int height, t_color color);
int				maps_len_width(t_maps *maps);
short			maps_add_bind(t_maps **maps, t_maps *el);
void			maps_go(t_maps **maps, short go);
void			maps_free_full(t_maps **maps);

void			isometric(t_maps *maps);

void			ft_bzero(void *dest, unsigned int size);
void			*ft_memchr(void *str, int c, unsigned int n);
unsigned int	ft_strlen(const char *str);
char			*ft_strchr(const char *str, int symbol);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			**ft_split(char const *s, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			*ft_memchr(void *str, int c, unsigned int n);
unsigned int	ft_strlen(const char *str);
#endif