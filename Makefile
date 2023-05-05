# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 02:06:43 by obouhrir          #+#    #+#              #
#    Updated: 2023/05/05 18:39:06 by obouhrir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#varibales
NAME   = fdf
CC	   = cc 
CFLAGS = -Wall -Werror -Wextra 
MLX    = -lmlx -framework OpenGL -framework AppKit
SRC    = fdf.c utl.c get_next_line.c get_next_line_utils.c check.c draw.c free.c get_value.c

#colours
GREEN = "\033[32m"
GREY = "\033[30m"
CYAN = "\033[36m"
RED = "\033[31m"

all : ${NAME}

${NAME} : ${SRC}
	@echo ${GREEN}"Compiling ${NAME}..."
	@${CC} ${CFLAGS} ${MLX} ${SRC} -o ${NAME}
	@echo "Successfully compiled ${NAME}!"

clean :
	@echo ${GREY}"Cleaning up..."
	@echo there are no objects files

fclean : clean
	@echo ${RED}"Removing ${NAME}..."
	@rm -f ${NAME}

re : fclean all
