#include "../fractal.h"

void	my_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
    int offset;

    offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->adress + offset;
	*(unsigned int*)dst = color;
}