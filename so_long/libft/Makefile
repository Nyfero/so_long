# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 14:07:19 by gsap              #+#    #+#              #
#    Updated: 2021/09/09 11:54:19 by gsap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_calloc.c \
	ft_strlen.c  ft_lstrlen.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
	ft_strnstr.c \
	ft_atoi.c ft_itoa.c ft_uitoa.c \
	ft_strdup.c \
	ft_strjoin.c ft_strjoin_and_free_s1.c ft_strjoin_and_free_s2.c \
	ft_strjoin_and_free_all.c \
	ft_strtrim.c ft_split.c ft_substr.c ft_strmapi.c \
	ft_free_ls.c \
	get_next_line.c \
	ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

CC = clang

AR = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

# Couleurs Mac
#
#NO_COLOR = \x1b[0m
#
#GREEN = \x1b[32;01m
#
#RED=\x1b[31;01m

all: $(NAME)

$(NAME): $(OBJS)
	@ $(AR) $(NAME) $(OBJS)
	@ ranlib $(NAME)
	@ echo "$(GREEN)\n		--- $(NAME) created ---\n$(NO_COLOR)"

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@ $(RM) $(OBJS)
	@ echo "$(RED)\n		*** Clean libft/*.o ***\n$(NO_COLOR)"

fclean: clean
	@ $(RM) $(NAME)
	@ echo "$(RED)\n		*** Clean $(NAME) ***\n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
