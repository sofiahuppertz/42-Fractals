/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:18:57 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/11 17:05:33 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	main(int argc, char *argv[])
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (init_fractal(argc, argv, fractal))
	{
		if (init_minilibx(&fractal));
		{
			mlx_loop_hook(fractal->mlx, &fractalisor, fractal);
			set_events(fractal);
			mlx_loop(fractal->mlx);
		}
	}
	destroy_fractal(fractal);
	return (1);
}

void	fractalisor(t_fractal *fractal)
{
	//re-direct to specific fractal generator
	if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(fractal->name, "julia", 5) == 0)
		draw_julia(fractal);
}

void set_events(t_fractal *fractal)
{
	mlx_hook(fractal->win, 3, (1L<<0), &key_press, fractal); 
	mlx_hook(fractal->win, 17, 0, &destroy_fractal, fractal);
	mlx_hook(fractal->win, 4, 0, &handle_zoom, fractal);
	mlx_hook(fractal->win, 5, 0, &handle_zoom, fractal);
}