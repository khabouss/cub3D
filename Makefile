# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 18:50:42 by tkhabous          #+#    #+#              #
#    Updated: 2021/02/02 15:07:48 by tkhabous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	cub3D
CC		= 	gcc
SRC		=	files/*.c
SRC2	=	files/*.c
LIB		=	*.a -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
FLAGS	=	-Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@make re -C libft/
	@rm -rf libft.a
	@mv ./libft/libft.a .
	@clear
	@$(CC) -g $(SRC) $(LIB) $(FLAGS) -o $(NAME)

bonus:
	@make re -C libft/
	@rm -rf libft.a
	@mv ./libft/libft.a .
	@clear
	@$(CC) -g $(SRC2) $(LIB) $(FLAGS) -o $(NAME)

clean:
	@echo "Clean"
	@(make clean -C ./libft/)
	@rm -rf *.a

fclean:	clean
	@echo "Fclean"
	@(make fclean -C ./libft/)
	@(rm -rf $(NAME))

re:	fclean all

.PHONY : bonus clean fclean re
