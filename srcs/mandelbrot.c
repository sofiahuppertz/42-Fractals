/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:42:39 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/06 15:42:41 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int draw_mandelbrot(t_instance *img, t_fractal *fractal)
{
    double temp;
    int column;
    int row;
    int i;


    row = 0;
    while (row <= HEIGHT)
    {
        fractal->c.im = 1.5 - (row / (double)HEIGHT) * 3;
        column = 0;
        while (column <= WIDTH)
        {
            fractal->c.re = -2 + (column / (double)WIDTH) * 3;
            fractal->z.re = 0;
            fractal->z.im = 0;
            for (i = 1; i <= 500; i++)
            {
                temp = fractal->z.re;
                fractal->z.re = pow(fractal->z.re, 2) - pow(fractal->z.im, 2) + fractal->c.re;
                fractal->z.im = (2 * temp * fractal->z.im) + fractal->c.im;
                if (pow(fractal->z.re, 2) + pow(fractal->z.im, 2) > 4)
                    break;
            }
            if (i == 501)
                my_pixel_put(img, column, row, 0x00000000);
            else
            //set shades
                my_pixel_put(img, column, row, 0x00FFFFFF);
            column += 1;
        }  
        row += 1;
    }
    return (0);
}


//int set_shades(int instability_level)
