/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:42:49 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/06 15:45:51 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	my_pixel_put(t_instance *data, int x, int y, int color)
{
	char	*dst;
    int offset;

    offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->adress + offset;
	*(unsigned int*)dst = color;
}

int 	close_window(t_instance *omega)
{
	mlx_destroy_window(omega->mlx, omega->window);
	mlx_destroy_display(omega->mlx);
	free(omega->mlx);
	exit(0);
	return (0);
}

int key_hook(int keycode, t_instance *omega)
{
	if (keycode == ESC)
	{
		close_window(omega);
	}
	ft_printf("key pressed: %i\n", keycode);
	return (0);
}