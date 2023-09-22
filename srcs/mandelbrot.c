/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:42:39 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/22 14:02:40 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	draw_mandelbrot(t_fractal *fractal)
{
	unsigned int	color;
	int				x;
	int				y;

	y = 0;
	while (y <= HEIGHT)
	{
		fractal->c.im = 1.12 - ((y + fractal->offset_y) / (double)HEIGHT) * 2.24
			* fractal->zoom;
		x = 0;
		while (x <= WIDTH)
		{
			fractal->c.re = -2 + ((x + fractal->offset_x) / (double)WIDTH)
				* 2.47 * fractal->zoom;
			fractal->z.re = 0;
			fractal->z.im = 0;
			color = get_color(fractal, mandelbrot_escape(fractal));
			my_pixel_put(fractal, x, y, color);
			x += 1;
		}
		y += 1;
	}
	return (0);
}

int	mandelbrot_escape(t_fractal *fractal)
{
	int		iter;
	double	x2;
	double	y2;

	iter = 0;
	x2 = 0;
	y2 = 0;
	if (fractal)
	{
		while (x2 + y2 <= 4 && iter <= MAX_ITERATIONS)
		{
			fractal->z.im = 2 * fractal->z.re * fractal->z.im + fractal->c.im;
			fractal->z.re = x2 - y2 + fractal->c.re;
			x2 = fractal->z.re * fractal->z.re;
			y2 = fractal->z.im * fractal->z.im;
			iter += 1;
		}
	}
	return (iter);
}
