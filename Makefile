# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 15:29:33 by mdavid            #+#    #+#              #
#    Updated: 2019/06/16 19:31:35 by mdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clear all fclean

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = fillit

LIBFT_L = -L libft -lft -I libft
LIBFT_PATH = ./libft
LIBFT = ./libft/libft.a

SRC_NAME =	main.c			\
		ft_check.c		\
		ft_solve.c		\
		init_map.c		\
		ft_parsing.c		\
		ft_display.c		\
		ft_table_int.c		\
		ft_check_form.c		\
		ft_check_nb_blocs.c	\
		ft_check_tetramino.c	\
		ft_table_neighbours.c

OBJ_NAME = $(SRC_NAME:.c=.o)
INCLUDE = -I fillit.h

all: $(NAME)

$(LIBFT_PATH)/%.c:
	@make -C libft

$(LIBFT): $(LIBFT_PATH)/%.c
	
%.o: %.c
	@printf "\e[1A"
	@echo "\033[1;32m[$(CC)] - [$(CFLAGS)]\033[0m \033[1;33min progress ...:\033[0m $< \033[1;31m->\033[0m $@"
	@$(CC) $(CFLAGS) -I. -c $< -o $@
	@printf "\e[0K"

$(NAME) : $(LIBFT) $(OBJ_NAME)
	@echo "\033[1;32m[$(CC)] - [$(CFLAGS)]\033[0m \033[1;33m- generating executable - :\033[0m $@"
	@echo "\033[1;31m--->\033[0m $(CC) $(CFLAGS) $(OBJ_NAME) $(LIBFT_L) $(INCLUDE) -o $(NAME)"
	@$(CC) $(CFLAGS) $(OBJ_NAME) $(INCLUDE) $(LIBFT_L) -o $(NAME)

norme :
	 norminette -R CheckForbiddenSourceHeader $(SRC_NAME) $(INC_NAME)

clean :
	@echo "\033[1;31m[CLEAN RULE]\033[0m \033[1;33mdeleting objects directory\033[0m"
	rm -f $(OBJ_NAME)
	@echo "\033[1;31m[LIBFT CLEAN RULE]\033[0m \033[1;33mdeleting libft objects\033[0m"
	@make -C libft/ clean

fclean : clean
	@echo "\033[1;31m[FCLEAN RULE]\033[0m \033[1;33mdeleting fillit executable\033[0m"
	rm -rf $(NAME)
	@echo "\033[1;31m[LIBFT FCLEAN RULE]\033[0m \033[1;33mdeleting libft objects and libft.a\033[0m"
	@make -C libft/ fclean
	
re : fclean all

