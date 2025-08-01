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

#include "fractol.h"

static int	julia_iterations(double x, double y, double cx, double cy)
{
    double	zx;
    double	zy;
    double	temp_x;
    int		i;

    zx = x;
    zy = y;
    i = 0;
    while (i < 50)
    {
        temp_x = (zx * zx) - (zy * zy);
        zy = 2 * zx * zy;
        zx = temp_x;
        zx += cx;
        zy += cy;
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

    x = (fractal->x - 350) / fractal->zoom + fractal->offset_x;
    y = (fractal->y - 350) / fractal->zoom + fractal->offset_y;
    iterations = julia_iterations(x, y, fractal->cx, fractal->cy);
    if (iterations == 50)
        put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
    else
        put_color_to_pixel(fractal, fractal->x, fractal->y, 
            (fractal->color * iterations));
}