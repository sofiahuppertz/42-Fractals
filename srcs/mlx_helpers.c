/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:42:49 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/11 16:41:01 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	my_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	int *buffer;
	
	buffer = (int *)fractal->adress;
	buffer[(y * fractal->line_length / 4) + x] = color;
}



int	init_minilibx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		return (0);
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fractal");
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->adress = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	return (1);
}

int	key_press(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		destroy_fractal(fractal);
	return (0);
}

int handle_zoom(int button, int x, int y,t_fractal *fractal)
{
	if (button == 4)
	{
		fractal->zoom *= 1.1;
		fractal->offset_x += (x / (double)WIDTH) * 2.47 / fractal->zoom;
		fractal->offset_y += (y / (double)HEIGHT) * 2.24 / fractal->zoom;
	}
	else if (button == 5)
	{
		fractal->zoom /= 1.1;
		fractal->offset_x -= (x / (double)WIDTH) * 2.47 / fractal->zoom;
		fractal->offset_y -= (y / (double)HEIGHT) * 2.24 / fractal->zoom;
	}
	return (0);
}