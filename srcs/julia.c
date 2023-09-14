/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:32:42 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/14 17:12:52 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	draw_julia(t_fractal *fractal)
{
	unsigned int	color;
	time_t			t;
	double			x;
	double y;
	int				iterations;

	y = 0;
	//Todo: case isntesitive.
	if (fractal->julia != NULL)
	{
		if (ft_strncmp(fractal->julia, "Dentrite", 7) == 0)
		{
			fractal->c.re = 0;
			fractal->c.im = -1;
		}
		else if (ft_strncmp(fractal->julia, "Rabbit", 5) == 0)
		{
			fractal->c.re = -0.1;
			fractal->c.im = 0.8;
		}
		else if (ft_strncmp(fractal->julia, "Dragon", 5) == 0)
		{
			fractal->c.re = 0.36;
			fractal->c.im = 0.1;
		}
	}
	else
	{
		//TODO: make this into a libft function.
		srand((unsigned)time(&t));
		fractal->c.im = (rand() / (double)RAND_MAX) * 2 - 1.12;
		fractal->c.re = (rand() / (double)RAND_MAX) * 2.47 - 2;
	}
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			fractal->z.re = -2 + (x / (double)WIDTH) * (4 / fractal->zoom) + fractal->offset_x;
			fractal->z.im =  2 - (y / (double)HEIGHT) * (4 / fractal->zoom) + fractal->offset_y;
			iterations = julia_escape(fractal);
			color = get_color(fractal, iterations);
			my_pixel_put(fractal, x, y, color);
			x += 1;
		}
		y += 1;
	}
	return (0);
}

int julia_escape(t_fractal *fractal)
{
	int		iter;
	double	xtemp;

	iter = 0;
	while (fractal->z.re * fractal->z.re + fractal->z.im
			* fractal->z.im < 4 && iter <= MAX_ITERATIONS)
	{
		xtemp = fractal->z.re;
		fractal->z.re = fractal->z.re * fractal->z.re - fractal->z.im * fractal->z.im
			+ fractal->c.re;
		fractal->z.im = 2 * fractal->z.im * xtemp + fractal->c.im;
		iter += 1;
	}
	return (iter);
}