# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 22:07:08 by ebensalt          #+#    #+#              #
#    Updated: 2022/05/30 19:27:16 by ebensalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
C = so_long.c \
	so_long_utils.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_my_split.c \
	ft_my_strjoin.c \
	ft_my_strdup.c \
	ft_my_strlen.c \
	ft_printf.c \
	ft_puthexa.c \
	ft_puthexap.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_putunbr.c \
	ft_putchar_fd.c \
	game.c \
	ft_my_swap.c \
	end_game.c \
	ft_count.c \
	map_check2.c \
	ft_my_strncmp.c \
	ft_my_strrchr.c \
	game1.c
O = $(C:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -Imlx -D BUFFER_SIZE=1
all : $(NAME)
$(NAME) : $(O)
	$(CC) $(GFLAGS) $(O) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean :
	rm -rf *.o
fclean : clean
	rm -rf $(NAME)
re : fclean all