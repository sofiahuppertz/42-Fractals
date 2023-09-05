#include "../fractal.h"

int draw_mandelbrot(t_img_data *img, t_fractal *fractal)
{
    double temp;
    int column;
    int row;
    int i;


    row = 0;
    while (row <= HEIGHT)
    {
        fractal->c.im = 2 - (row / (double)HEIGHT) * 4;
        column = 0;
        while (column <= WIDTH)
        {
            fractal->c.re = -2 + (column / (double)WIDTH) * 4;
            fractal->z.re = 0;
            fractal->z.im = 0;
            for (i = 1; i <= 1000; i++)
            {
                temp = fractal->z.re;
                fractal->z.re = pow(fractal->z.re, 2) - pow(fractal->z.im, 2) + fractal->c.re;
                fractal->z.im = (2 * temp * fractal->z.im) + fractal->c.im;
                if (pow(fractal->z.re, 2) + pow(fractal->z.im, 2) > 4)
                    break;
            }
            if (i == 1001)
                my_pixel_put(img, column, row, 0x00000000);
            else
                my_pixel_put(img, column, row, 0x00FFFFFF);
            column += 1;
        }  
        row += 1;
    }
    return (0);
}
