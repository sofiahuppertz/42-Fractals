/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:15:19 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/13 17:42:58 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	init_fractal(int argc, char *argv[], t_fractal *fractal)
{
	fractal->zoom = 1;
	fractal->offset_x = 0;
	fractal->offset_x = 0;
	fractal->julia = NULL;
	
	if (argc < 2)
		printf("Usage: ./fractal [fractal name] [*julia_set*]\n");
	else
	{
		fractal->name = ft_strdup(argv[1]);
		if (ft_strncmp(fractal->name, "mandelbrott", 10) == 0)
		{
			return (1);
		}
		else if (ft_strncmp(fractal->name, "julia", 4) == 0)
		{
			if (argv[2])
				fractal->julia = ft_strdup(argv[2]);
			return (1);
		}
		else
			printf("Fractals available: mandelbrot, julia\n");
	}
	return (0);
}

int	destroy_fractal(t_fractal *fractal)
{
	if (fractal)
	{
		if (fractal->name)
			free(fractal->name);
		if (fractal->julia)
			free(fractal->julia);
		if (fractal->img)
			mlx_destroy_image(fractal->mlx, fractal->img);
		if (fractal->window)
			mlx_destroy_window(fractal->mlx, fractal->window);
		if (fractal->mlx)
		{
			mlx_destroy_display(fractal->mlx);
			free(fractal->mlx);
		}
		free(fractal);
	}
	exit (1);
}
