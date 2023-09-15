/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:18:57 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/15 18:33:05 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	main(int argc, char *argv[])
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (init_fractal(argc, argv, fractal))
	{
		if (init_minilibx(fractal))
		{
			mlx_loop_hook(fractal->mlx, &fractalisor, fractal);
			set_events(fractal);
			mlx_loop(fractal->mlx);
		}
	}
	destroy_fractal(fractal);
	return (0);
}

int	fractalisor(t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(fractal->name, "julia", 5) == 0)
		draw_julia(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->img, 0, 0);
	return (1);
}

void	set_events(t_fractal *fractal)
{
	mlx_key_hook(fractal->window, key_press, fractal);
	mlx_mouse_hook(fractal->window, handle_zoom, fractal);
	mlx_hook(fractal->window, 17, 0L, destroy_fractal, fractal);
	mlx_hook(fractal->window, 2, 1L << 0, key_hold, fractal);
}
