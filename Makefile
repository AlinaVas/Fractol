# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afesyk <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/01 18:39:25 by afesyk            #+#    #+#              #
#    Updated: 2018/04/01 18:39:27 by afesyk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = main.c exit.c hooks.c fractals.c definition.c definition2.c \
		threads.c bonus_fractals.c
OBJS = $(SRCS:.c=.o)
FLAGS = -O3 -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGl -framework AppKit
LDIR = libft

GREEN = \033[32;1m
YELLOW = \033[1;33m
RED = \033[1;31m

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@make -C $(LDIR)
	@gcc $(MLXFLAGS) $(OBJS) -L $(LDIR) -lft -o $(NAME) -lpthread
	@echo "$(GREEN)Compiled!"

clean:
	@make clean -C $(LDIR)
	@/bin/rm -f $(OBJS)
	@echo "$(YELLOW)Cleaned!"

fclean: clean
	@make fclean -C $(LDIR)
	@/bin/rm -f $(NAME)
	@echo "$(RED)Fcleaned!"

re: fclean all
