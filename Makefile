NAME = Cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm minilibx-linux/libmlx.a $(LIBFT_LIB)

LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC_DIR = src/
PARSER_DIR = $(SRC_DIR)parser/

SRC = $(PARSER_DIR)dfs.c \
	$(PARSER_DIR)file_utils.c \
	$(PARSER_DIR)gnl.c \
	$(PARSER_DIR)init_prop.c \
	$(PARSER_DIR)parser_utils.c \
	$(SRC_DIR)free.c \
	$(SRC_DIR)game.c \
	main.c
OBJ = $(SRC:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

.SILENT :

all: $(NAME)

$(NAME): $(OBJ)
	printf "${YELLOW}⎔ Compilando Cub3d...${NC}\n"
	$(MAKE) -C $(LIBFT_DIR) >/dev/null 2>&1
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) >/dev/null 2>&1
	printf "${GREEN}✅ Cub3d pronto!${NC}\n"
clean:
	$(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1
	rm -f $(OBJ) 
	printf "${YELLOW}⚠️  Objetos (*.o) removidos.${NC}\n"

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null 2>&1
	rm -f $(NAME)
	printf "${YELLOW}⚠️  Executável e libft limpos.${NC}\n"
re: fclean all

.PHONY: all clean fclean re