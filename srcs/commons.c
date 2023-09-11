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

//Function to calculate "stability" -> 0 if stable, then number for how unstable.
void	get_color(t_fractal *fractal, int stability_level)
{
    //Default behaviour

    //Blue

    //Green

    //Red

    //perfect stabillity (black zone)
}

int	calculate_stability(t_fractal *fractal)
{
	double	temp;
	int		stability;
	int		i;

	i = 1;
	if (fractal)
	{
		while (i < MAX_ITERATIONS)
		{
			temp = fractal->z.re;
			fractal->z.re = pow(fractal->z.re, 2) - pow(fractal->z.im, 2)
				+ fractal->c.re;
			fractal->z.im = (2 * temp * fractal->z.im) + fractal->c.im;
			if (pow(fractal->z.re, 2) + pow(fractal->z.im, 2) > 4)
				break ;
			i += 1;
		}
	}
    if (i == MAX_ITERATIONS)
        return (0);
    else
        return (MAX_ITERATIONS - i);
}
