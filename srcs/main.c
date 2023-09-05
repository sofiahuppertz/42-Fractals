
#include "../fractal.h"

int main(int argc, char *argv[])
{
    t_fractal fractal;

    init(argc, argv, &fractal);
    fractalisor(&fractal);
    free(fractal.name);
}


void fractalisor(t_fractal *fractal)
{
    void *mlx;
    void *mlx_win;
    t_img_data img;

    //Initialize  the mlx, window and image.
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fractal");
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.adress = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    //Set event handlers
    //mlx_hook(win_ptr, 2, 0, key_press, NULL);
    //mlx_hook(win_ptr, 4, 0, mouse_click, NULL);
    //mlx_hook(win_ptr, 17, 0, close_window, NULL);

    //Draw the fractal
    fractal->name = fractal;
    if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
        draw_mandelbrot(&img, fractal);
    
    //Display the image
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop_mlx(mlx);

}

