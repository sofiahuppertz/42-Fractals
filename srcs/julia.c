/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:32:42 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/15 19:00:37 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	draw_julia(t_fractal *fractal)
{
	unsigned int	color;
	double			x;
	double			y;

	if (fractal->julia != NULL)
		define_constant(fractal);
	else
		define_random_constant(fractal);
	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			fractal->z.re = -2 + ((x + fractal->offset_x) / (double)WIDTH) * 4
				* fractal->zoom;
			fractal->z.im = 2 - ((y + fractal->offset_y) / (double)HEIGHT) * 4
				* fractal->zoom;
			color = get_color(fractal, julia_escape(fractal));
			my_pixel_put(fractal, x, y, color);
			x += 1;
		}
		y += 1;
	}
	return (0);
}

void	define_constant(t_fractal *fractal)
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

void	define_random_constant(t_fractal *fractal)
{
	static t_complex	c;

	if (c.re == 0 && c.im == 0)
	{
		c.im = generate_random(-1.12, 1.12);
		c.re = generate_random(-2, 0.47);
	}
	fractal->c.re = c.re;
	fractal->c.im = c.im;
}

int	julia_escape(t_fractal *fractal)
{
	int		iter;
	double	xtemp;

	iter = 0;
	while (fractal->z.re * fractal->z.re + fractal->z.im * fractal->z.im < 4
		&& iter <= MAX_ITERATIONS)
	{
		xtemp = fractal->z.re;
		fractal->z.re = fractal->z.re * fractal->z.re - fractal->z.im
			* fractal->z.im + fractal->c.re;
		fractal->z.im = 2 * fractal->z.im * xtemp + fractal->c.im;
		iter += 1;
	}
	return (iter);
}
