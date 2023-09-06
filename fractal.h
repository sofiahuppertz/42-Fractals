/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:42:18 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/06 15:46:31 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "Libft/ft_printf.h"
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000
# define DESTROY 17
# define ESC 65307

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_fractal
{
	char		*name;
	double		zoom;
	t_complex	c;
	t_complex	z;
	int			re_center;
	int			im_center;
}				t_fractal;

typedef struct s_instance
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*adress;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_instance;

int				close_window(t_instance *omega);
int				init(int argc, char *argv[], t_fractal *fractal);
int				draw_mandelbrot(t_instance *img, t_fractal *fractal);
void			fractalisor(t_fractal *fractal);
int				key_hook(int keycode, t_instance *omega);
void			my_pixel_put(t_instance *data, int x, int y, int color);

#endif