# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstepane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/24 19:00:22 by dstepane          #+#    #+#              #
#    Updated: 2019/06/24 19:00:24 by dstepane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_retro
CC			= clang++
FLAGS		= -g # -Wall -Wextra -Werror 

SRC_DIR		= src/
INC_DIR		= inc/

SRC			=	main.cpp \
				game.cpp \
				Player.cpp

HPP			=	main.hpp \
				game.hpp \
				Player.hpp

HEADS		= $(addprefix $(INC_DIR), $(HPP))
OBJ 		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -lncurses $(OBJ) -o $(NAME)
	@echo "\033[32m\033[100m\033[1mft_retro executable compiled.\033[0m"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp $(HEADS)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)
	@echo "	\033[96m$@\033[0m"

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "\033[31mft_retro object files removed.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mft_retro executable removed.\033[0m"

re: fclean all

vpath %.cpp $(SRC_DIR)

.PHONY: all clean fclean re
