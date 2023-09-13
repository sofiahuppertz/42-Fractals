/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:32:42 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/13 18:22:33 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	draw_julia(t_fractal *fractal)
{
	unsigned int	color;
	time_t			t;
	int				x;
	int				y;
	int iterations;
	y = 0;
	
	//Todo: case isntesitive.
	
	if (fractal->julia != NULL)
	{
		if (ft_strncmp(fractal->julia, "Dentrite", 7) == 0)
		{
			fractal->c.im = -1;
			fractal->c.re = 0;
		}
		else if (ft_strncmp(fractal->julia, "Rabbit", 5) == 0)
		{
			fractal->c.im = 0.8;
			fractal->c.re = -0.1;
		}
		else if (ft_strncmp(fractal->julia, "Dragon", 5) == 0)
		{
			fractal->c.im = 0.1;
			fractal->c.re = 0.36;
		}
	}
	else
	{
		//TODO: make this into a libft function.
		srand((unsigned)time(&t));
		fractal->c.im = (rand() / (double)RAND_MAX) * 2.24 - 1.12;
		fractal->c.re = (rand() / (double)RAND_MAX) * 2.47 - 2;
	}
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			
			fractal->z.im = 2 - (y / (double)HEIGHT) * 4;
			fractal->z.re = -2 + (x / (double)WIDTH) * 4;
			iterations = escape_time_calculation(fractal);
			printf("%i\n", iterations);
			color = get_color(fractal, iterations);
			my_pixel_put(fractal, x, y, color);
			x += 1;
		}
		y += 1;
	}
	return (0);
}
