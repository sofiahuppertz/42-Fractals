/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:51:01 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/15 18:23:00 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

unsigned int	get_color(t_fractal *fractal, int iter)
{
	double	log_zn;
	double	nu;
	double	smooth_iter;
	int		alpha;
	int		red;
	int		green;
	int		blue;

	if (iter > MAX_ITERATIONS)
		return (0x00000000);
	log_zn = log(fractal->z.re * fractal->z.re + fractal->z.im * fractal->z.im)
		/ 2;
	nu = log(log_zn / log(2)) / log(2);
	smooth_iter = iter + 1 - nu;
	red = (int)(255 * sin(0.5 * smooth_iter));
	green = (int)(255 * sin(0.5 * smooth_iter + 2));
	blue = (int)(225);
	alpha = 255;
	return ((alpha << 24) | (red << 16) | (green << 8) | blue);
}
