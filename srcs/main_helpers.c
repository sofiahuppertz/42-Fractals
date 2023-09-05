
#include "../fractal.h"

void init(int argc, char *argv[], t_fractal *fractal)
{
    if (argc == 2)
    {
        if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
            fractal->name = ft_strdup("mandelbrot");
        else
            printf("Fractals available: mandelbrot, julia\n");
    }
    else
        printf("Usage: ./fractal [fractal name]\nFractals available: mandelbrot, julia\n");
    (void)fractal;
}