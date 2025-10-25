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
#MINILIBX = ./archives/minilibx-linux/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
#MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

COMPILE_OBJ = $(CC) $(CFLAGS) -c $< -o $@

RM = rm -rf

FILES = src/parsing/check_args.c
FILES += src/parsing/create_matrix.c
FILES += src/parsing/error_handling.c
FILES += src/main.c
FILES += src/parsing/validate_map.c
#FILES += src/rendering/open_game_window.c
#FILES += src/rendering/error_game.c
#FILES += src/rendering/render_game.c
#FILES += src/rendering/events.c

SRC = $(FILES)

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(LIBFT) $(FT_PRINTF) $(GNL) $(NAME)

$(LIBFT):
	@make -C ./archives/libft
	@echo ">>> $(LIBFT) compiled <<<"

$(FT_PRINTF):
	@make -C ./archives/ft_printf
	@echo ">>> $(FT_PRINTF) compiled <<<"

$(GNL):
	@make -C ./archives/get_next_line
	@echo ">>> $(GNL) compiled <<<"

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(GNL)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(GNL) -o $(NAME)
	@echo ">>> $(NAME) created <<<"

%.o: %.c
	$(COMPILE_OBJ)

clean:
	$(RM) $(OBJ)
#	$(RM) $(MINILIBX) ./archives/minilibx-linux/*.o
	$(RM) $(GNL) ./archives/get_next_line/*.o
	$(RM) $(FT_PRINTF) ./archives/ft_printf/*.o
	$(RM) $(LIBFT) ./archives/libft/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
