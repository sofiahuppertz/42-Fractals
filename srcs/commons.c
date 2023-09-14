/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:51:01 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/14 17:06:43 by shuppert         ###   ########.fr       */
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

	if (iter > MAX_ITERATIONS)
		return (0x00000000);
	log_zn = log(fractal->z.re * fractal->z.re + fractal->z.im
			* fractal->z.im) / 2;
	nu = log(log_zn / log(2)) / log(2);
	smooth_iter = iter + 1 - nu;
	
	//ou can adjust the 0.1 to make the transitions happen more or less frequently.
	int red   = (int)(105 * sin(0.5 * smooth_iter));
	int green = (int)(105 * sin(0.5 * smooth_iter + 2));
	int blue  = (int)(205 * sin(0.6 * smooth_iter + 4));
	
	alpha = 255;
	return ((alpha <<24) | (red << 16) | (green << 8) | blue);
}

