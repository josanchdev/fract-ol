/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:09:22 by josanch2          #+#    #+#             */
/*   Updated: 2025/08/01 10:09:24 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)fractal_void;
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (NULL);
}

// void	mandelbrot_pthread(t_fractal *fractal)
// {
// 	t_fractal	tab[THREAD_NUMBER];
// 	pthread_t	t[THREAD_NUMBER];
// 	int			i;

// 	i = 0;
// 	while (i < THREAD_NUMBER)
// 	{
// 		ft_memcpy((void*)&tab[i], (void*)fractal, sizeof(t_fractal));
// 		tab[i].y = THREAD_WIDTH * i;
// 		pthread_create(&t[i], NULL, draw_mandelbrot, &tab[i]);
// 		i++;
// 	}
// 	while (i--)
// 		pthread_join(t[i], NULL);
// 	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image,
//		0, 0);
// }

void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}
