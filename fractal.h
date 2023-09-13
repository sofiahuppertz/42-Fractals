/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:42:18 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/13 17:53:25 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "Libft/ft_printf.h"
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define MAX_ITERATIONS 50
# define WIDTH 700
# define HEIGHT 700
# define DESTROY 17
# define ESC 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_fractal
{
	t_complex	c;
	t_complex	z;
	double		offset_y;
	double		offset_x;
	double		zoom;
	void		*mlx;
	void		*window;
	void		*img;
	int			*adress;
	char		*julia;
	char		*name;
	int			bits_per_pixel;
	int			endian;
	int			line_length;
}				t_fractal;

unsigned int	get_color(t_fractal *fractal, int iter);

int				draw_julia(t_fractal *fractal);
int				draw_mandelbrot(t_fractal *fractal);
int				escape_time_calculation(t_fractal *fractal);
int				init_fractal(int argc, char *argv[], t_fractal *fractal);
int				init_minilibx(t_fractal *fractal);
int				key_press(int keycode, t_fractal *fractal);

int				destroy_fractal(t_fractal *fractal);
int				fractalisor(t_fractal *fractal);
int				handle_zoom(int button, int x, int y, t_fractal *fractal);
void			my_pixel_put(t_fractal *fractal, int x, int y, int color);
void			set_events(t_fractal *fractal);

#endif