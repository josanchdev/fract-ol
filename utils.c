#include "fractol.h"
#include <stdlib.h>
#include <time.h>


void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(0);
	return (0);
}

double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == XK_m)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == XK_p)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}