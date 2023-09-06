/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:15:19 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/06 15:43:08 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int init(int argc, char *argv[], t_fractal *fractal)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		{
			fractal->name = ft_strdup("mandelbrot");
			return (1);
		}
		else
		{
			printf("Fractals available: mandelbrot, julia\n");
			return (0);
		}
	}
	else
	{
		printf("Usage: ./fractal [fractal name]\n");
		return(0);
	}
	(void)fractal;
}