/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:42:18 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/15 19:00:56 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_ITERATIONS 200
# define WIDTH 700
# define HEIGHT 712
# define DESTROY 17
# define ESC 65307
# define SPACE 32
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

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

double			compute_smoothness(t_fractal *fractal, int iter);

int				draw_julia(t_fractal *fractal);
int				draw_mandelbrot(t_fractal *fractal);
int				init_fractal(int argc, char *argv[], t_fractal *fractal);
int				init_minilibx(t_fractal *fractal);
int				julia_escape(t_fractal *fractal);
int				key_hold(int keycode, t_fractal *fractal);
int				key_press(int keycode, t_fractal *fractal);
int				mandelbrot_escape(t_fractal *fractal);
int				destroy_fractal(t_fractal *fractal);
int				fractalisor(t_fractal *fractal);
int				handle_zoom(int button, int x, int y, t_fractal *fractal);

void			define_constant(t_fractal *fractal);
void			define_random_constant(t_fractal *fractal);
void			my_pixel_put(t_fractal *fractal, int x, int y, int color);
void			set_events(t_fractal *fractal);

#endif
