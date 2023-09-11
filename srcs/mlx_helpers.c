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

int close_window(t_fractal *fractal)
{
	
}

int key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
	{
		exit(1);
	}
	ft_printf("key pressed: %i\n", keycode);
	return (0);
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