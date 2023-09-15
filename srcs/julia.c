/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:32:42 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/14 17:44:45 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	draw_julia(t_fractal *fractal)
{
	unsigned int	color;
	static 	t_complex c;
	double			x;
	double y;

	y = 0;
	if (fractal->julia != NULL)
	{
		if (ft_strncmp(str_to_lower(fractal->julia), "dentrite", 7) == 0)
		{
			fractal->c.re = 0;
			fractal->c.im = -1;
		}
		else if (ft_strncmp(fractal->julia, "rabbit", 5) == 0)
		{
			fractal->c.re = -0.1;
			fractal->c.im = 0.8;
		}
		else if (ft_strncmp(fractal->julia, "dragon", 5) == 0)
		{
			fractal->c.re = 0.36;
			fractal->c.im = 0.1;
		}
	}
	else
	{
		if (c.re == 0 && c.im == 0)
		{
			c.im = generate_random(-1.12, 1.12)
			c.re = generate_random(-2, 0.47);
		}
		fractal->c.re = c.re;
		fractal->c.im = c.im;
	}
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			fractal->z.re = -2 + (x / (double)WIDTH) * 4;
			fractal->z.im =  2 - (y / (double)HEIGHT) * 4;
			color = get_color(fractal, julia_escape(fractal));
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