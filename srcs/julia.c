/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:32:42 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/11 17:05:06 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	draw_julia(t_fractal *fractal)
{

    unsigned int color;
	t_complex c;
	time_t t;
	int		x;
	int		y;

	y = 0;
    //default constant: make random.
    if (fractal->julia == NULL)
    {
		srand((unsigned) time(&t))
        c.im = double(rand() / RAND_MAX) * 2.24 - 1.12;
        c.re = double(rand() / RAND_MAX) * 2.47 - 2;
    }
	else if (ft_strncmp(fractal->julia, "Dentrite", 8) == 0)
	{
		c.im = -1;
        c.re = 0;
	}
	else if (ft_strncmp(fractal->julia, "Rabbit", 6) == 0)
	{
		c.im = 0.8;
        c.re = -0.1;
	}
	else if (ft_strncmp(fractal->julia, "Dragon", 6) == 0)
	{
		c.im = 0.1;
        c.re = 0.36;
	}
    else
	{
		write(1, "Invalid Julia Set\n", 18);
		destroy_fractal(fractal);
		exit (1);
	}
	while (y <= HEIGHT)
	{
		fractal->z.im = 1.12 - (y / (double)HEIGHT) * 2.24 / fractal->zoom + fractal->offset_y;
		x = 0;
		while (x <= WIDTH)
		{
			fractal->z.re = -2 + (x / (double)WIDTH) * 2.47 / fractal->zoom + fractal->offset_x;
			color = get_color(fractal, escape_time_calculation(fractal));
			my_pixel_put(fractal, x, y, color);
		}
		y += 1;
	}
	return (0);
}
