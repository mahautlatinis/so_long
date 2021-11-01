# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:58:48 by mahautlat         #+#    #+#              #
#    Updated: 2021/06/28 10:31:02 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/checks/check_map_walls.c \
		./srcs/checks/check_minimap.c \
		./srcs/checks/check_elements.c \
		./srcs/checks/read.c \
		./srcs/render/keyboard_inputs.c \
		./srcs/render/graphics.c \
		./srcs/render/draw.c \
		./srcs/checks/check_minimap_lines.c \
		./srcs/utils/utils0.c \
		./srcs/utils/utils1.c \
		./srcs/utils/utils2.c \
		./srcs/utils/utils3.c \
		./srcs/struct/exits/exits0.c \
		./srcs/struct/exits/exits1.c \
		./srcs/struct/collectibles/collectibles0.c \
		./srcs/struct/collectibles/collectibles1.c \
		./srcs/struct/collectibles/collectibles2.c \
		./srcs/struct/player/player0.c \
		./srcs/struct/data/data.c \
		./srcs/struct/mem/mem0.c \
		./srcs/error_handling/error0.c \
		./srcs/error_handling/error1.c \
		./srcs/free/free.c \

SRCS_BONUS = ./bonus/main_bonus.c \
			./bonus/itoa.c \
			./bonus/render.c \

SRCS_MANDATORY = ./main.c \

OBJS 		= ${SRCS:.c=.o}
OBJS_B		= ${SRCS_BONUS:.c=.o}
OBJS_M		= ${SRCS_MANDATORY:.c=.o}

UNAME		:= $(shell uname)

PATH_MLX	= mlx
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS) ${OBJS_M}
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) ${OBJS_M} $(FLAGS)

bonus:		${OBJS} ${OBJS_B}
			make -C $(PATH_MLX)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_B} $(FLAGS)

clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS} ${OBJS_M} ${OBJS_B}

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		bonus all clean fclean re
