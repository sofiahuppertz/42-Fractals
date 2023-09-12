/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:51:01 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/11 16:53:03 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

//Function to calculate "stability" -> MAX_ITER if stable, then number for how unstable.
unsigned int	get_color(t_fracatl fractal, int iter)
{
	double			log_zn;
	double			nu;
	double			smooth_iter;
	int 			alpha;


    if (iter == MAX_ITERATIONS)
        return 0x000000;
    log_zn = log(fractal->z.re * fractal->z.re + fractal->z.im * fractal->z.im) / 2;
    nu = log(log_zn / log(2)) / log(2);
    smooth_iter = iter + 1 - nu;

// you can adjust the 0.1 to make the transitions happen more or less frequently.
    int red   = (int)(255 * sin(0.1 * smooth_iter));
    int green = (int)(255 * sin(0.1 * smooth_iter + 2));
    int blue  = (int)(255 * sin(0.1 * smooth_iter + 4));

	alpha = 255;
    return (alpha <<24) | (red << 16) | (green << 8) | blue; 
}

int	escape_time_calculation(t_fractal *fractal)
{
	double	w;
	int		iter;
	int 	x2;
	int		y2;

	iter = 1;
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
    if (iter == MAX_ITERATIONS)
        return (0);
    else
        return (iter);
}
