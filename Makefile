# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 18:04:53 by mhanda            #+#    #+#              #
#    Updated: 2022/10/25 23:58:58 by mhanda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = mandatory/main.c mandatory/parcing/get_map.c mandatory/parcing/init_map_stuct.c mandatory/parcing/get_colors.c mandatory/parcing/check_colors.c mandatory/parcing/free_c_f_path_rgb.c \
		mandatory/parcing/make_map.c mandatory/parcing/more_parce.c mandatory/parcing/extra_parce.c mandatory/utils/util_0.c mandatory/utils/util_1.c mandatory/utils/util_2.c mandatory/utils/util_3.c \
		mandatory/utils/util_4.c mandatory/parcing/refield_map.c mandatory/graphics/main_win.c mandatory/graphics/handl_player.c mandatory/graphics/paint.c mandatory/graphics/make_moves.c \
		mandatory/graphics/rays.c mandatory/graphics/raycaster_0.c mandatory/graphics/distancebtwpts.c mandatory/graphics/horizontal_intersections.c \

BCFILES = bonus/main.c bonus/parcing/get_map.c bonus/parcing/init_map_stuct.c bonus/parcing/get_colors.c bonus/parcing/check_colors.c bonus/parcing/free_c_f_path_rgb.c \
		bonus/parcing/make_map.c bonus/parcing/more_parce.c bonus/parcing/extra_parce.c bonus/utils/util_0.c bonus/utils/util_1.c bonus/utils/util_2.c bonus/utils/util_3.c \
		bonus/utils/util_4.c bonus/parcing/refield_map.c bonus/graphics/main_win.c bonus/graphics/handl_player.c bonus/graphics/paint.c bonus/graphics/make_moves.c \
		bonus/graphics/rays.c bonus/graphics/raycaster_0.c bonus/graphics/distancebtwpts.c bonus/graphics/horizontal_intersections.c \

OFILES = $(CFILES:.c=.o)
BOFILES = $(BCFILES:.c=.o)

CFLAGS =  -Wall -Wextra -Werror

RM = rm

NAME = cub3D 
BNAME = cub3D_bonus

INC = mandatory/cub.h
INCB = bonus/cub_b.h

LINKS = -lmlx -framework OpenGL -framework AppKit -lmlx

$(NAME) : $(OFILES) $(INC)
	$(CC) $(LINKS) $(CFLAGS) $(OFILES) -o cub3D
$(BNAME) : $(BOFILES) $(BINC)
	$(CC) $(LINKS) $(CFLAGS) $(BOFILES) -o cub3D_bonus
all:$(NAME)
bonus:$(BNAME)
clean:
	$(RM) -f $(OFILES) $(BOFILES)
fclean:
	$(RM) -f $(NAME) $(OFILES) $(BNAME) $(BOFILES)
re : fclean all