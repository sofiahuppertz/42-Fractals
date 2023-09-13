NAME	= fractol
LIBFT	= Libft/libft.a
MLX = minilibx-linux/libmlx_Linux.a
LIBFT_PATH = Libft
MLX_PATH = minilibx-linux

INCLUDE = -I./headers -I./$(LIBFT_PATH) -I./$(MLX_PATH)
CFLAGS = -Wall -Wextra -Werror  

SRCS_NAMES = main.c \
			commons.c \
			main_helpers.c \
			julia.c \
			mandelbrot.c \
			mlx_helpers.c \

SRCS = $(addprefix srcs/, $(SRCS_NAMES))
OBJS = $(SRCS:c=o)

all		: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MLX)
	cc -g3 $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME) -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm -lz 

%.o: srcs/%.c
	cc -g3 $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT): 
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

fclean	: clean
	rm -f $(NAME) 

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

re		: fclean all

.PHONY: clean fclean all re