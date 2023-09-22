/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:42:49 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/22 16:22:13 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	my_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	int	index;

	index = (y * fractal->line_length + x * (fractal->bits_per_pixel / 8));
	((fractal->adress))[index / (fractal->bits_per_pixel / 8)] = color;
}

int	init_minilibx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!(fractal->mlx))
		return (0);
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fractal");
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->adress = (int *)mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);
	return (1);
}

int	key_press(int keycode, t_fractal *fractal)
{
	double	move_factor;

	move_factor = 1.0 / fractal->zoom;
	if (keycode == ESC)
		destroy_fractal(fractal);
	if (keycode == SPACE)
	{
		fractal->zoom = 1;
		fractal->offset_x -= fractal->offset_x;
		fractal->offset_y -= fractal->offset_y;
	}
	return (0);
}

int	key_hold(int keycode, t_fractal *fractal)
{
	double	move_factor;

	move_factor = 1 / fractal->zoom;
	if (keycode == UP)
		fractal->offset_y -= move_factor;
	else if (keycode == DOWN)
		fractal->offset_y += move_factor;
	else if (keycode == RIGHT)
		fractal->offset_x += move_factor;
	else if (keycode == LEFT)
		fractal->offset_x -= move_factor;
	return (0);
}

int	handle_zoom(int button, int x, int y, t_fractal *fractal)
{
	double	dynamic_zoom_factor;

	dynamic_zoom_factor = 1.0 + 0.05 / (fractal->zoom / 100.0 + 1);
	fractal->offset_x -= (double)x / fractal->zoom;
	fractal->offset_y -= (double)y / fractal->zoom;
	if (button == 4)
	{
		fractal->zoom /= dynamic_zoom_factor;
	}
	else if (button == 5)
	{
		fractal->zoom *= dynamic_zoom_factor;
	}
	fractal->offset_x += (double)x / fractal->zoom;
	fractal->offset_y += (double)y / fractal->zoom;
	return (0);
}
