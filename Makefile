NAME	:= rt

SRC	:= src/transparency.c \
	   src/get_next_line.c \
	   src/reflection.c \
	   src/normalizing.c \
	   src/loader.c \
	   src/errors.c \
	   src/eye.c \
	   src/get_color.c \
	   src/init.c \
	   src/intersec.c \
	   src/l_eye.c \
	   src/l_obj.c \
	   src/my_atoi_base.c \
	   src/l_light.c \
	   src/tools.c \
	   src/trans_rot.c \
	   src/intersec/objs1.c \
	   src/intersec/objs2.c \
	   src/intersec/waves.c \
	   src/intersec/get_inter_inf.c \
	   src/window.c \
	   src/shadow.c \
	   src/light.c \
	   src/main.c \
	   bitmap/bitmap.c \
	   tools/my_strlen.c \
	   tools/my_fputstr.c \
	   tools/epur_str.c \
	   tools/my_strncmp.c \
	   tools/my_putstr.c \
	   tools/my_str_to_wordtab.c \
	   tools/my_str_isnum.c \
	   parsing/parser.c \
	   parsing/main_parse.c \
	   parsing/end_token.c \
	   parsing/begin_scene.c \
	   parsing/token.c \
	   parsing/object.c \
	   parsing/eye.c \
	   parsing/object_color.c \
	   parsing/object_effect.c \
	   parsing/light.c

CC	:= gcc -lncurses -pthread -lm

LDFLAGS := -L/usr/lib64 -lmlx -lXext -lX11

CFLAGS	+= -I./include -W -Wall -Wextra

OBJ	:= $(SRC:.c=.o)

all:	   $(NAME)

$(NAME):   $(OBJ)
	   $(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	   $(RM) $(OBJ)

fclean:	   clean
	   $(RM) $(OBJ) $(NAME)

re:	   fclean all

.PHONY:    all clean fclean re
