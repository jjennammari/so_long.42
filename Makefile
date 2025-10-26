# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/23 19:39:47 by jemustaj          #+#    #+#              #
#    Updated: 2025/10/24 13:44:32 by jemustaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./archives/libft/libft.a 
FT_PRINTF = ./archives/ft_printf/ft_printf.a
GNL = ./archives/get_next_line/get_next_line.a
MINILIBX = ./archives/minilibx-linux/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

COMPILE_OBJ = $(CC) $(CFLAGS) -c $< -o $@

RM = rm -rf

FILES = src/parsing/check_args.c
FILES += src/parsing/create_matrix.c
FILES += src/parsing/check_characters.c
FILES += src/parsing/error_handling.c
FILES += src/main.c
FILES += src/parsing/validate_map.c
FILES += src/create_game/open_game_window.c
FILES += src/create_game/render_img.c
FILES += src/create_game/key_movements.c
FILES += src/create_game/game_utils.c
FILES += src/create_game/end_game.c

SRC = $(FILES)

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(LIBFT) $(FT_PRINTF) $(GNL) $(MINILIBX) $(NAME)

$(LIBFT):
	@make -C ./archives/libft
	@echo ">>> $(LIBFT) compiled <<<"

$(FT_PRINTF):
	@make -C ./archives/ft_printf
	@echo ">>> $(FT_PRINTF) compiled <<<"

$(GNL):
	@make -C ./archives/get_next_line
	@echo ">>> $(GNL) compiled <<<"

$(MINILIBX):
	@make -C ./archives/minilibx-linux
	@echo ">>> &(MINILIBX) compiled <<<"

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(GNL) $(MINILIBX)

	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(GNL) -L./archives/minilibx-linux -lmlx -lX11 -lXext -lbsd -lm -o $(NAME)
	@echo ">>> $(NAME) created <<<"

%.o: %.c
	$(COMPILE_OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) $(MINILIBX) ./archives/minilibx-linux/*.o
	$(RM) $(GNL) ./archives/get_next_line/*.o
	$(RM) $(FT_PRINTF) ./archives/ft_printf/*.o
	$(RM) $(LIBFT) ./archives/libft/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
