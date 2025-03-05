# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 16:29:05 by algarci5          #+#    #+#              #
#    Updated: 2025/03/05 17:30:25 by algarci5         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory
# The name of your project
NAME = so_long
MAP = ./maps/map.ber
LIBFT = ./libft/
LIBFT_LIB = $(LIBFT)libft.a
LIBMLX	:= ./MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# The C compiler to use
CC = gcc -g3

# The flags to use with the archiver
ARFLAGS = -rc

# The flags to use with the C compiler
CFLAGS = -Wall -Wextra -Werror

# The command to remove files
RM = rm -f

# A list of all .c files in the current directory
SRCS = so_long.c

# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)

# A list of all .o files of bonus
BNS = $(BONUS:.c=.o)

# The default target - builds the project
all: $(NAME)

# A rule to build the project from the .o files
$(NAME): $(LIBFT_LIB) $(MLX_LIB) libmlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(LIBFT_LIB) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT_LIB):
	make -C $(LIBFT) -f Makefile

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# A rule to build the bonus part
bonus: $(BNS)
	$(CC) $(CFLAGS) $(BNS) -o $(NAME) $(LIBFT_LIB) $(LDFLAGS) $(LIBS)

# A rule to remove all .o files
clean:
	$(RM) $(OBJS) $(BNS)
	make -C $(LIBFT) clean
	make -C $(LIBMLX)/build clean

# A rule to remove all .o files and the project
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

# A rule to rebuild everything from scratch
re: fclean all

# A special rule to tell make that these targets aren't files
.PHONY: all fclean re clean bonus run error