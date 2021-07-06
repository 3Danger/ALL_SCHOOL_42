#include "main_header.h"

#include <stdio.h>

int	close_x(int keycode, void *somenull)
{
	exit(EXIT_SUCCESS);
	return (1);
}

int	key_hook(int keycode, void *somenull)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (1);
}

int	main(int argc, char **argv)
{
	t_maps	*maps;
	t_mlx	mlx;

	if (argc != 2)
	{
		ft_putstr_fd("Enter one arg.\nExample: ~/Desctop/folder/file.fdf\n", 1);
		return (1);
	}
	maps = hand_data_iarr(argv[1]);
	mlx.pt = mlx_init();
	mlx.win = mlx_new_window(mlx.pt, WIDTH, HEIGHT, "FDF_Project");
	mlx.img = mlx_new_image(mlx.pt, WIDTH, HEIGHT);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel,
			&mlx.line_length, &mlx.endian);
	isometric(maps);
	run_nigga(maps, &mlx);
	mlx_put_image_to_window(mlx.pt, mlx.win, mlx.img, 0, 0);
	maps_free_full(&maps);
	mlx_key_hook(mlx.win, &key_hook, NULL);
	mlx_hook(mlx.win, 17, 0, &close_x, NULL);
	mlx_loop(mlx.pt);
	return (1);
}
