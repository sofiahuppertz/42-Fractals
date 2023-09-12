/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:15:19 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/11 17:03:45 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	init_fractal(int argc, char *argv[], t_fractal *fractal)
{
	char colors[3];

	colors[0] = 'B';
	colors[1] = 'G';
	colors[2] = 'R';
	//Default color: grayscale or multicolor?
	if (argc < 2)
	{
		printf("Usage: ./fractal [fractal name] [color: BGR] [*julia_set*]\n");
		return (0);
	}
	else
	{
		fractal->name = ft_strdup(argv[1]);
		fractal->palette = NULL;
		fractal->julia = NULL;
		if (argv[2])
		{
			if (ft_strchr((const char)colors, ft_toupper(*argv[2])))
				fractal->palette = argv[2];
		}
		if (ft_strncmp(fractal->name, "mandelbrott", 10) == 0)
		{
			return (1);
		}
		else if (ft_strncmp(fractal->name, "julia", 5) == 0)
		{
			if (argv[3])
				fractal->julia = ft_strdup(argv[3]);
			return (1);
		}	
		else
		{
			printf("Fractals available: mandelbrot, julia\n");
			return (0);
		}
	}
}

void	destroy_fractal(t_fractal *fractal)
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
