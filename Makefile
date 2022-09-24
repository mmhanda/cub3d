# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 18:04:53 by mhanda            #+#    #+#              #
#    Updated: 2022/09/23 01:00:27 by mhanda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = main.c parcing/get_map.c parcing/init_map_stuct.c parcing/get_colors.c parcing/check_colors.c parcing/free_c_f_path_rgb.c \
		parcing/make_map.c parcing/more_parce.c parcing/extra_parce.c utils/util_0.c utils/util_1.c utils/util_2.c utils/util_3.c utils/util_4.c \
		parcing/refield_map.c graphics/main_win.c graphics/handl_player.c graphics/paint.c graphics/make_moves.c graphics/render.c graphics/rays.c 
OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra #-Werror

RM = rm -r

NAME = cub3D 

INC = cub.h

LINKS = -lmlx -framework OpenGL -framework AppKit -lmlx

all : $(NAME)

$(NAME) : $(INC) $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(LINKS) -o cub3D

clean : 
		$(RM) $(OFILES)

fclean : clean
		$(RM) $(NAME)

re : fclean all