# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amahi <amahi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 06:50:19 by amahi             #+#    #+#              #
#    Updated: 2022/06/03 16:30:16 by amahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 	=	so_long

HEADER	=	so_long.h

LIBRARIES = -lmlx -lm -framework OpenGL -framework AppKit


FLAGS 	=	-Wextra -Werror -Wall
# FLAGS =	-Wextra -Werror -Wall -fsanitize=address -fsanitize=undefined

SOURCE	=	main.c				GNL/get_next_line.c			\
			init_map.c			GNL/get_next_line_utils.c	\
			src.c				out.c						\
			check_map.c			game.c						\
			move.c				check_move.c				\
			ft_itoa.c			animation.c					\
			move_enemy.c

OBJECT	=	$(SOURCE:.c=.o)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJECT)
			$(CC) $(OBJECT) $(LIBRARIES) -g -o $(NAME)

%.o		:	%.c $(HEADER)
			$(CC) $(FLAGS) -Imlx -g -c $< -o $@

clean	:
			$(RM) $(OBJECT)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all


# NAME 	=	so_long

# #===========================================================#
# #                          HEADERS			                #
# #===========================================================#

# HEADER	=	so_long.h


# #===========================================================#
# #                          SOURCES			                #
# #===========================================================#

# SOURCE	=	main.c				GNL/get_next_line.c			\
# 			init_map.c			GNL/get_next_line_utils.c	\
# 			src.c				out.c						\
# 			check_map.c			game.c						\


# #===========================================================#
# #                    INCLUDING MINILIBX                     #
# #===========================================================#

# MXL_DIR		= minilibx
# MLX_MAKE	= Makefile
# MLX_PATH	= ${MXL_DIR}/libmlx_Linux.a


# #===========================================================#
# #                          OBJECTS			                #
# #===========================================================#

# OBJECT	=	${SOURCE:.c=.o}


# #===========================================================#
# #                          FLAGS			                #
# #===========================================================#

# CFLAGS 	 = -Wextra -Werror -Wall -g
# MFLAGS	 = -ldl -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
# IFLAGS	:= -I ./includes
# # FLAGS = -fsanitize=address -fsanitize=undefined


# .PHONY	:	all clean fclean re

# all		:	$(NAME)

# $(NAME)	:	$(OBJECT)
# 			@make -C minilibx
# 			$(CC) $(CFLAGS) $(OBJECT) $(IFLAGS) -o $(NAME) $(MFLAGS)

# %.o		:	%.c $(HEADER)
# 			$(CC) $(FLAGS) -c $< -o $@

# clean	:
# 			$(RM) $(OBJECT)

# fclean	:	clean
# 			$(RM) $(NAME)

# re		:	fclean all