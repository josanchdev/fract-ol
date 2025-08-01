/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:10:57 by josanch2          #+#    #+#             */
/*   Updated: 2025/08/01 10:10:59 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 400;
	fractal->offset_x = -1.2;
	fractal->offset_y = -1.2;
	fractal->max_iterations = 42;
}

void	init_mlx(t_fractal *fractal)
{
	int	screen_width;
	int	screen_height;
	int	win_x;
	int	win_y;

	fractal->mlx = mlx_init();
	mlx_get_screen_size(fractal->mlx, &screen_width, &screen_height);
	win_x = (screen_width - SIZE) / 2;
	win_y = (screen_height - SIZE) / 2;
	if (win_x < 0)
		win_x = 0;
	if (win_y < 0)
		win_y = 0;
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel,
			&fractal->size_line,
			&fractal->endian);
}
