#ifndef PARSING_H_
# define PARSING_H_

#include "rtracer.h"

# define SCENE "<scene>"
# define END_SCENE "</scene>"
# define OBJECT "<object>"
# define END_OBJECT "</object>"
# define CAMERA "<camera"
# define END_CAMERA "</camera"
# define TYPE "<type>"
# define END_TYPE "</type>"
# define LIGHT "<light>"
# define END_LIGHT "</light>"
# define POSITION "<position>"
# define END_POSITION "</position>"
# define ROTATION "<rotation>"
# define END_ROTATION "</rotation>"
# define COLOR "<color>"
# define END_COLOR "</color>"
# define OPACITY "<opacity>"
# define END_OPACITY "</opacity>"
# define SHINE "<shine>"
# define END_SHINE "</shine>"
# define RAY "<ray>"
# define END_RAY "</ray>"
# define RAY_IN "<ray_in>"
# define END_RAY_IN "</ray_in>"
# define ALIASING "<aliasing>"
# define END_ALIASING "</aliasing>"
# define ANG "<ang>"
# define END_ANG "</ang>"
# define VEC "<vector>"
# define END_VEC "</vector>"
# define REFLECT "<reflect>"
# define END_REFLECT "</reflect>"
# define WAVE "<wave>"
# define END_WAVE "</wave>"
# define FAST "<fast>"
# define END_FAST "</fast>"
# define CHESS "<chess>"
# define END_CHESS "</chess>"

typedef struct	s_parsing
{
  int		cam;
  int		light;
  int		obj;
  int		scene;
  char		*str;
  int		fd;
}		t_parsing;

int			parsing(char *str,struct s_content *parser);
int			fill_parse(struct s_content *parser, int fd);
int			my_strlen(char *str);
int			my_strcmp(char *s1, char *s2);
void			my_fputstr(char *str);
void			begin_scene(struct s_parsing *parsing,
				    struct s_content *content);
void			fill_object(struct s_content *parser, int fd);
char			*epur_str(char *str);
int			my_strncmp(char *s1, char *s2, int n);
int			token_scene(char *str, struct s_parsing *parsing,
				    struct s_content *content);
int			token_object(char *str, struct s_parsing *parsing,
				     struct s_content *content);
int			object_type(char *str, struct s_parsing *parsing,
				    struct s_content *content);
char			*end_token(char *str, char *token, struct s_parsing *parsing);
char			**my_str_to_wordtab(char *str, char *delim);
int			object_position(char *str, struct s_parsing *parsing,
					struct s_content *content);
int			my_str_isnum(char *str);
int			object_rotation(char *str, struct s_parsing *parsing, struct
					s_content *content);
int			object_ray(char *str, struct s_parsing *parsing,
				   struct s_content *content);
int			object_ray_in(char *str, struct s_parsing *parsing,
				   struct s_content *content);
int			object_shine(char *str, struct s_parsing *parsing,
				     struct s_content *content);
int			object_opacity(char *str, struct s_parsing *parsing,
				       struct s_content *content);
int			object_wave(char *str, struct s_parsing *parsing,
				       struct s_content *content);
int			object_color(char *str, struct s_parsing *parsing,
				     struct s_content *content);
int			object_ang(char *str, struct s_parsing *parsing,
				   struct s_content *content);
int			light_color(char *str, struct s_parsing *parsing,
				    struct s_content *content);
int			light_position(char *str, struct s_parsing *parsing,
				       struct s_content *content);
int			light_vector(char *str, struct s_parsing *parsing,
				     struct s_content *content);
int			eye_position(char *str, t_parsing *parsing,
				     t_content *content);
int			eye_fast(char *str, t_parsing *parsing,
				     t_content *content);
int			eye_aliasing(char *str, t_parsing *parsing,
				     t_content *content);
int			eye_rotation(char *str, t_parsing *parsing,
				     t_content *content);
int			object_reflect(char *str, struct s_parsing *parsing,
			       struct s_content *content);
int			object_chess(char *str, struct s_parsing *parsing,
			       struct s_content *content);
#endif
