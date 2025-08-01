#include "fractol.h"


static int	tricorn_iterations(double x, double y, int max_iterations)
{
	double	zx;
	double	zy;
	double	temp_x;
	int		i;

	zx = 0;
	zy = 0;
	i = 0;
	while (i < max_iterations)
	{
		temp_x = (zx * zx) - (zy * zy);
		zy = -2 * zx * zy;
		zx = temp_x;
		zx += x;
		zy += y;
		if ((zx * zx + zy * zy) > 4)
			break ;
		i++;
	}
	return (i);
}


void	calculate_tricorn(t_fractal *fractal)
{
	double	x;
	double	y;
	int		iterations;

	x = (fractal->x - SIZE / 2.0) / fractal->zoom + fractal->offset_x;
	y = (fractal->y - SIZE / 2.0) / fractal->zoom + fractal->offset_y;
	iterations = tricorn_iterations(x, y, fractal->max_iterations);
	if (iterations == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, 
			(fractal->color * iterations));
}