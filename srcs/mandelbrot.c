/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:42:39 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/11 17:02:42 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	draw_mandelbrot(t_fractal *fractal)
{
	unsigned int	color;
	int				escape_time;
	int				x;
	int				y;

	y = 0;
	while (y <= HEIGHT)
	{
		fractal->c.im = 1.12 - (y / (double)HEIGHT) * 2.24 / fractal->zoom + fractal->offset_y;
		x = 0;
		while (x <= WIDTH)
		{
			fractal->c.re = -2 + (x / (double)WIDTH) * 2.47 / fractal->zoom + fractal->offset_x;
			fractal->z.re = 0;
			fractal->z.im = 0;
			escape_time = escapte_time_calculation(fractal);
			color = get_color(fractal, escape_time);
			my_pixel_put(fractal, x, y, color);
		}
		y += 1;
	}
	return (0);
}

