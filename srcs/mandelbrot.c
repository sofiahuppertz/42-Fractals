/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:42:39 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/13 17:13:53 by shuppert         ###   ########.fr       */
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
		fractal->c.im = 1.12 - (y / (double)HEIGHT) * (2.24 / fractal->zoom) + fractal->offset_y;
		x = 0;
		while (x <= WIDTH)
		{

			fractal->c.re = -2 + (x / (double)WIDTH) * (2.47 / fractal->zoom) + fractal->offset_x;
			fractal->z.re = 0;
			fractal->z.im = 0;
			color = get_color(fractal, escape_time_calculation(fractal));
			my_pixel_put(fractal, x, y, color);
			x += 1;
		}
		y += 1;
	}
	return (0);
}
