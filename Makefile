# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amahi <amahi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 06:50:19 by amahi             #+#    #+#              #
#    Updated: 2022/05/26 09:43:58 by amahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	so_long

#===========================================================#
#                          HEADERS			                #
#===========================================================#

HEADER	=	so_long.h


#===========================================================#
#                          SOURCES			                #
#===========================================================#

SOURCE	=	main.c				GNL/get_next_line.c			\
			init_map.c			GNL/get_next_line_utils.c	\
			src.c				out.c						\
			check_map.c			game.c						\


#===========================================================#
#                    INCLUDING MINILIBX                     #
#===========================================================#

MXL_DIR		= minilibx
MLX_MAKE	= Makefile
MLX_PATH	= ${MXL_DIR}/libmlx_Linux.a


#===========================================================#
#                          OBJECTS			                #
#===========================================================#

OBJECT	=	${SOURCE:.c=.o}


#===========================================================#
#                          FLAGS			                #
#===========================================================#

CFLAGS 	 = -Wextra -Werror -Wall -g
MFLAGS	 = -ldl -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
IFLAGS	:= -I ./includes
# FLAGS = -fsanitize=address -fsanitize=undefined


.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJECT)
			@make -C minilibx
			$(CC) $(CFLAGS) $(OBJECT) $(IFLAGS) -o $(NAME) $(MFLAGS)

%.o		:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJECT)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all