
#ifndef FRACTAL_H
#define FRACTAL_H

#include "Libft/libft.h"
#include "Libft/ft_printf.h"
#include<stdio.h>
#include<math.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct s_complex
{
    double re;
    double im;
} t_complex;

typedef struct s_fractal
{
	char *name;
	double zoom;
	t_complex c;
	t_complex z;
	int re_center;
	int im_center;
} t_fractal;


typedef struct	s_img_data {
	void	*img;
	char	*adress;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;


void init(int argc, char *argv[], t_fractal *fractal);
int draw_mandelbrot(t_img_data *img, t_fractal *fractal);
void fractalisor(t_fractal *fractal);
void	my_pixel_put(t_img_data *data, int x, int y, int color);

#endif