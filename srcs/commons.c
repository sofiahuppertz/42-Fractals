/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:51:01 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/13 18:24:58 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

//Function to calculate "stability" -> MAX_ITER if stable,
//then number for how unstable.
unsigned int	get_color(t_fractal *fractal, int iter)
{
	double			log_zn;
	double			nu;
	double			smooth_iter;
	int 			alpha;
	//(void)fractal;
	//if (iter > MAX_ITERATIONS)
	//	return (0x00000000);
	//else
	//	return (0x00FFFFFF);
	log_zn = log(fractal->z.re * fractal->z.re + fractal->z.im
			* fractal->z.im) / 2;
	nu = log(log_zn / log(2)) / log(2);
	smooth_iter = iter + 1 - nu;
	
	//ou can adjust the 0.1 to make the transitions happen more or less frequently.
	int red   = (int)(255 * sin(0.1 * smooth_iter));
	int green = (int)(255 * sin(0.1 * smooth_iter + 2));
	int blue  = (int)(255 * sin(0.1 * smooth_iter + 4));
	
	alpha = 255;
	return ((alpha <<24) | (red << 16) | (green << 8) | blue);
}

int	escape_time_calculation(t_fractal *fractal)
{
	int	iter;
	double	x2;
	double	y2;

	iter = 0;
	x2 = 0;
	y2 = 0;
	if (fractal)
	{
		//printf("values are: c: %f + %f i, z: %f + %f i\n", fractal->c.re, fractal->c.im, fractal->z.re, fractal->z.im);
		while (x2 + y2 <= 4 && iter <= MAX_ITERATIONS)
		{
			fractal->z.im = 2 * fractal->z.re * fractal->z.im + fractal->c.im;
			fractal->z.re = x2 - y2 + fractal->c.re;
			x2 = fractal->z.re * fractal->z.re;
			y2 = fractal->z.im * fractal->z.im;
			iter += 1;
		//	printf("calculation %i  result: %f + %f i\n", iter, fractal->z.re,
				//fractal->z.im);
		}
	}
	if (iter == MAX_ITERATIONS)
		return (0);
	else
		return (iter);
}


/*
int	escape_time_calculation(t_fractal *fractal)
{
	int	iter;
	double	xtemp;

	iter = 1;
	if (fractal)
	{
		printf("values are: c: %f + %f i, z: %f + %f i\n", fractal->c.re,
				fractal->c.im, fractal->z.re, fractal->z.im);
		
		while (iter <= MAX_ITERATIONS)
		{
			xtemp = fractal->z.re;
			fractal->z.re = pow(fractal->z.re, 2) - pow(fractal->z.im, 2)
				+ fractal->c.re;
			fractal->z.im = (2 * xtemp * fractal->z.im) + fractal->c.im;
			if (pow(fractal->z.re, 2) + pow(fractal->z.im, 2) > 4)
				break ;
			iter += 1;
			printf("calculation %i  result: %f + %f i\n", iter, fractal->z.re,
					fractal->z.im);
		}
		
	}
	return (iter);
}*/