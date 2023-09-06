/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:18:57 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/06 15:43:44 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (!init(argc, argv, &fractal))
		return (0);
	fractalisor(&fractal);
	free(fractal.name);
}

void	fractalisor(t_fractal *fractal)
{
	t_instance *omega;

	//Initialize  the mlx, window and image.
	omega = NULL;
	omega = malloc(sizeof(t_instance));
	if (!omega)
		return ;
	omega->mlx = mlx_init();
	if (!omega->mlx)
		return ;
	omega->window = mlx_new_window(omega->mlx, WIDTH, HEIGHT, "Fractal");
	omega->img = mlx_new_image(omega->mlx, WIDTH, HEIGHT);
	omega->adress = mlx_get_data_addr(omega->img, &omega->bits_per_pixel,
			&omega->line_length, &omega->endian);

	//Set event handlers
	mlx_hook(omega->window, DESTROY, 0, close_window, &omega);
    mlx_key_hook(omega->window, key_hook, &omega);
	//mlx_hook(omega->window, ESC, 0, close_window, &omega);
	//mlx_hook(win_ptr, 2, 0, key_press, NULL);
	//mlx_hook(win_ptr, 4, 0, mouse_click, NULL);

	//Draw the fractal
	if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		draw_mandelbrot(omega, fractal);

	//Display the image
	mlx_put_image_to_window(omega->mlx, omega->window, omega->img, 0, 0);
	mlx_loop(omega->mlx);
}