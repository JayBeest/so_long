NAME = 		so_long
SRC = 		so_long.c \
			draw.c \
			events.c \
			parser.c
SRC_DIR =	src
OBJ_DIR	= 	$(SRC_DIR)/obj
INCL = 		-I$(SRC_DIR)/incl
C_FLAGS = 	-g -fsanitize=address #-Wall -Wextra -Werror
OBJ = 		$(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C mlx
	$(CC) $(C_FLAGS) -o $@ $^ -Lmlx -Llibft -lmlx -lft \
					-framework OpenGL -framework AppKit

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $< $(C_FLAGS) $(INCL) -Imlx -Ilibft -c -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C libft
	$(MAKE) clean -C mlx
	rm -f $(NAME)

re: clean all
