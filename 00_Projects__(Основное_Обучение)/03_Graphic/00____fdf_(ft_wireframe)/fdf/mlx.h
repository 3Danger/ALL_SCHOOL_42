#ifndef MLX_H
# define MLX_H
void			*mlx_init(void);
void			*mlx_new_window(void *pt, int size_x,
					int size_y, char *title);
int				mlx_clear_window(void *pt, void *win_ptr);
int				mlx_pixel_put(void *pt, void *win_ptr, int x,
					int y, int color);
void			*mlx_new_image(void *pt, int width, int height);
char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
					int *size_line, int *endian);
int				mlx_put_image_to_window(void *pt, void *win_ptr,
					void *img_ptr, int x, int y);
unsigned int	mlx_get_color_value(void *pt, int color);
int				mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_expose_hook (void *win_ptr, int (*funct_ptr)(),
					void *param);
int				mlx_loop_hook (void *pt, int (*funct_ptr)(), void *param);
int				mlx_loop (void *pt);
int				mlx_string_put(void *pt, void *win_ptr,
					int x, int y, int color, char *string);
void			*mlx_xpm_to_image(void *pt, char **xpm_data,
					int *width, int *height);
void			*mlx_xpm_file_to_image(void *pt, char *filename,
					int *width, int *height);
void			*mlx_png_file_to_image(void *pt, char *file,
					int *width, int *height);
int				mlx_destroy_window(void *pt, void *win_ptr);
int				mlx_destroy_image(void *pt, void *img_ptr);
int				mlx_hook(void *win_ptr, int x_event, int x_mask,
					int (*funct)(), void *param);
int				mlx_mouse_hide(void);
int				mlx_mouse_show(void);
int				mlx_mouse_move(void *win_ptr, int x, int y);
int				mlx_mouse_get_pos(void *win_ptr, int *x, int *y);
int				mlx_do_key_autorepeatoff(void *pt);
int				mlx_do_key_autorepeaton(void *pt);
int				mlx_do_sync(void *pt);
#endif
