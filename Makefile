# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 14:07:19 by gsap              #+#    #+#              #
#    Updated: 2021/09/21 18:07:03 by gsap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_bonus

CC = clang

FLAGS = -Wall -Wextra -Werror

MLX_FLAG = -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRCS = So_long.c ft_parsing.c ft_check_map.c ft_error.c ft_display.c ft_move.c

SB = So_long_bonus.c ft_parsing_bonus.c ft_display_bonus.c ft_move_bonus.c \
	ft_check_map_bonus.c ft_error.c

OBJS = $(SRCS:.c=.o)

OB = $(SB:.c=.o)

RM = rm -f

DIR = libft/

MLX_PATH = ./mlx_linux

LIBFT = $(addprefix $(DIR)/,libft.a)

MLX = $(addprefix $(MLX_PATH)/,libmlx_Linux.a libmlx.a)

# Couleurs Mac
#
#NO_COLOR=\x1b[0m
#
#GREEN=\x1b[32;01m
#
#RED=\x1b[31;01m
#
#YELLOW=\x1b[33;01m
#

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@ echo "$(YELLOW)\n		*** Make $(NAME) ***\n$(NO_COLOR)"
	@ $(CC) $(SRCS) $(MLX_FLAG) -o $(NAME) $(DIR)libft.a
	@ echo "$(GREEN)\n		--- $(NAME) created ---\n$(NO_COLOR)"

$(LIBFT):
	@ echo "$(YELLOW)\n		*** Make Libft ***\n$(NO_COLOR)"
	@ make -C $(DIR)

$(MLX):
	@ make -C $(MLX_PATH)

bonus: $(BONUS)

$(BONUS): $(OB) $(LIBFT) $(MLX)
	@ echo "$(YELLOW)\n		*** Make $(BONUS) ***\n$(NO_COLOR)"
	@ $(CC) $(SB) $(MLX_FLAG) -o $(BONUS) $(DIR)libft.a
	@ echo "$(GREEN)\n		--- $(BONUS) created ---\n$(NO_COLOR)"

.c.o:
	@ $(CC) $(FLAGS) -I/usr/include -Imlx_linux -c $< -o $(<:.c=.o)


clean:
	@ $(RM) $(OBJS)
	@ make clean -C $(DIR)
	@ echo "$(RED)\n		*** Clean $(NAME)/*.o ***\n$(NO_COLOR)"

bclean:
	@ $(RM) $(OB)
	@ make clean -C $(DIR)
	@ $(RM) $(BONUS)
	@ echo "$(RED)\n		*** Remove $(BONUS) ***\n$(NO_COLOR)"

fclean: clean
	@ make fclean -C $(DIR)
	@ make clean -C $(MLX_PATH)
	@ $(RM) $(NAME)
	@ echo "$(RED)\n		*** Remove $(NAME) ***\n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean bclean re .c.o debug
