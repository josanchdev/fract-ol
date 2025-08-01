/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanch2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:13:39 by josanch2          #+#    #+#             */
/*   Updated: 2025/08/01 10:13:41 by josanch2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int	julia_iterations(t_fractal *fractal, double x, double y)
{
    double	zx;
    double	zy;
    double	temp_x;
    int		i;

    zx = x;
    zy = y;
    i = 0;
    while (i < fractal->max_iterations)
    {
        temp_x = (zx * zx) - (zy * zy);
        zy = 2 * zx * zy;
        zx = temp_x;
        zx += fractal->cx;
        zy += fractal->cy;
        if ((zx * zx + zy * zy) > 4)
            break ;
        i++;
    }
    return (i);
}


void	calculate_julia(t_fractal *fractal)
{
    double	x;
    double	y;
    int		iterations;

    x = (fractal->x - SIZE / 2.0) / fractal->zoom + fractal->offset_x;
    y = (fractal->y - SIZE / 2.0) / fractal->zoom + fractal->offset_y;
    iterations = julia_iterations(fractal, x, y);
    if (iterations == fractal->max_iterations)
        put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
    else
        put_color_to_pixel(fractal, fractal->x, fractal->y, 
            (fractal->color * iterations));
}