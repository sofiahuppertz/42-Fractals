/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:32:42 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/11 17:05:06 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	draw_julia(t_fractal *fractal)
{
    t_complex c;
    unsigned int color;
    int stability_level;
	int		column;
	int		row;

	row = 0;
    //default constant: make random.
    if (fractal->julia == NULL)
    {
        c.im = generate_random();
        c.re = generate_random();
    }
    //otherwise passed values.
    
	while (row <= HEIGHT)
	{
		fractal->z.im = 1.5 - (row / (double)HEIGHT) * 3;
		column = 0;
		while (column <= WIDTH)
		{
			fractal->z.re = -2 + (column / (double)WIDTH) * 3;
			stability_level = calculate_stability(fractal);
			color = get_color(fractal, stability_level);
			my_pixel_put(fractal, column, row, color);
		}
		row += 1;
	}
	return (0);
}

//ADD ZOOM AND OFFSET!!
