/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:51:01 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/22 16:54:16 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

unsigned int	get_color(t_fractal *fractal, int iter)
{
	double	smooth_iter;
	int		red;
	int		green;
	int		blue;

	(void)fractal;
	if (iter > MAX_ITERATIONS)
		return (0x00000000);
	smooth_iter = compute_smoothness(fractal, iter);
	red = (int)(100 * sin(0.3 * smooth_iter));
	green = (int)(255 * sin(0.5 * smooth_iter));
	blue = (int)(255 * sin(0.7 * smooth_iter));
	return ((255 << 24) | (red << 16) | (green << 8) | blue);
}

double	compute_smoothness(t_fractal *fractal, int iter)
{
	double	log_zn;
	double	nu;
	double	smooth_iter;
	double	mag_squared;

	mag_squared = fractal->z.re * fractal->z.re + fractal->z.im * fractal->z.im;
	if (mag_squared <= 0)
		return (0.0);
	log_zn = log(mag_squared) / 2;
	nu = log(log_zn / log(2)) / log(2);
	smooth_iter = iter + 1 - nu;
	return (smooth_iter);
}
