# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:58:48 by mahautlat         #+#    #+#              #
#    Updated: 2023/10/03 22:32:45 by mahautlatin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 			=	./srcs/checks/check_map_walls.c \
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

SRCS_BONUS 		= 	/bonus/main_bonus.c \
					./bonus/itoa.c \
					./bonus/render.c \

SRCS_MANDATORY	= 	./main.c \

OBJS 			= 	${SRCS:.c=.o}
OBJS_B			= 	${SRCS_BONUS:.c=.o}
OBJS_M			= 	${SRCS_MANDATORY:.c=.o}
OS 				=	 $(shell uname)
PATH_MLX 		= 	../mlx_mac

CC 				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
NAME			= 	o_long
FLAGS			=	-framework OpenGL -framework AppKit
LIB_FLAGS		=	${FLAGS} -L ${PATH_MLX} -lmlx

all: 			${NAME}

.c.o:
				${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

$(NAME): 		$(OBJS) ${OBJS_M}
				make -C $(PATH_MLX)
				${CC} -I/usr/include $(CFLAGS) -o $(NAME) $(OBJS) ${OBJS_M} $(LIB_FLAGS)

bonus:			${OBJS} ${OBJS_B}
				make -C $(PATH_MLX)
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_B} $(LIB_FLAGS)

clean:
				make -C $(PATH_MLX) clean
				${RM} ${OBJS} ${OBJS_M} ${OBJS_B}

fclean: 		clean
				make -C $(PATH_MLX) clean
				${RM} ${NAME}

re: 			fclean all

.PHONY:			bonus all clean fclean re
