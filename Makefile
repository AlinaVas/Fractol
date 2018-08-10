# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afesyk <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/26 18:18:57 by afesyk            #+#    #+#              #
#    Updated: 2018/04/26 18:19:00 by afesyk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
SRC = main.c exit.c vector.c intersection.c scene.c scene2.c color.c normal.c \
    raytrace.c hook.c get_scene.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAG = -O3 -Wall -Wextra -Werror
MLXFLAG = -lmlx -framework OpenGl -framework AppKit
LDIR = libft

GREEN = \033[32;1m
YELLOW = \033[1;33m
RED = \033[1;31m

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAG) -o $@ -c $<

$(NAME): $(OBJ)
	@make -C $(LDIR)
	@$(CC) $(MLXFLAG) $(CFLAG) $(OBJ) -L $(LDIR) -lft -o $(NAME) -lpthread
	@echo "$(GREEN)Compiled!"

clean:
	@make clean -C $(LDIR)
	@/bin/rm -f $(OBJ)
	@echo "$(YELLOW)Cleaned!"

fclean: clean
	@make fclean -C $(LDIR)
	@/bin/rm -f $(NAME)
	@echo "$(RED)Fcleaned!"

re: fclean all

.PHONY: all clean fclean re