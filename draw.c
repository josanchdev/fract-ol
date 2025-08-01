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

void	draw_mandelbrot(t_fractal *fractal)
{
    fractal->x = 0;
    fractal->y = 0;
    while (fractal->x < SIZE)
    {
        while (fractal->y < SIZE)
        {
            calculate_mandelbrot(fractal);
            fractal->y++;
        }
        fractal->y = 0;
        fractal->x++;
    }
}

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
        fractal->y = 0;
        fractal->x++;
    }
}

void	draw_tricorn(t_fractal *fractal)
{
    fractal->x = 0;
    fractal->y = 0;
    while (fractal->x < SIZE)
    {
        while (fractal->y < SIZE)
        {
            calculate_tricorn(fractal);
            fractal->y++;
        }
        fractal->y = 0;
        fractal->x++;
    }
}