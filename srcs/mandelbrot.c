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
	int 			stability_level;
	int				column;
	int				row;

	row = 0;
	while (row <= HEIGHT)
	{
		fractal->c.im = 1.5 - (row / (double)HEIGHT) * 3;
		column = 0;
		while (column <= WIDTH)
		{
			fractal->c.re = -2 + (column / (double)WIDTH) * 3;
			fractal->z.re = 0;
			fractal->z.im = 0;
			stability_level = calculate_stability(fractal);
			color = get_color(fractal, stability_level);
			my_pixel_put(fractal, column, row, color);
		}
		row += 1;
	}
	return (0);
}


//ADD ZOOM AND OFFSET!!