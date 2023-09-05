NAME = fractol
LIBFT = /Libft/libft.a

INCLUDE = -I./ -I/Libft
CFLAGS = -Wall -Wextra -Werror

SRC_NAMES = main.c \
		main_helperes.c \
		mandelbrot.c \


SRCS = $(addprefix srcs/, $(SRC_NAMES))
OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME) : $(LIBFT) $(OBJS)
	cc -g $(CFLAGS) $(OBJS) -LLibft -lft -o $(NAME)

%.o: srcs/%.c
	cc -g $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	make -C Libft

fclean: clean
	rm -f $(NAME) 
	
clean: 
	rm -f $(C_OBJS)
	rm -f $(OBJS)
	make clean -C Libft

re: fclean all

.PHONY: all clean fclean re