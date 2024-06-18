CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/opt/X11/include -Imlx
MLX_FLAGS = -Lmlx/ -lmlx -framework OpenGL -framework AppKit

NAME = cub3D

SRCS = 	proyect/main.c							\
		proyect/input.c							\
		proyect/mouse.c 						\
		proyect/update.c						\
		proyect/parse/parse.c					\
		proyect/parse/read_file.c				\
		proyect/parse/check_data.c				\
		proyect/parse/check_map.c				\
		proyect/parse/check_map_aux.c			\
		proyect/parse/gnl/get_next_line.c 		\
		proyect/parse/gnl/get_next_line_utils.c	\
		proyect/render/render.c					\
		proyect/render/render_math.c			\
		proyect/render/texture_raycast.c		\
		proyect/render/pixel_img.c				\
		proyect/render/door.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS) libft/libft.a mlx/libmlx.a
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME) -Llibft/ -lft -lm

libft/libft.a:
	make -C libft/

mlx/libmlx.a:
	make -C mlx/

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -rf $(OBJS)
	make -C libft/ clean
	make -C mlx/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean $(NAME)

bonus: $(NAME)

.PHONY: clean fclean re