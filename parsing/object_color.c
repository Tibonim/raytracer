#include "rtracer.h"
#include "parsing.h"
#include "get_next_line.h"

int		object_opacity(char *str, struct s_parsing *parsing,
			struct s_content *content)
{
  char		*opacity;

  opacity = end_token(str, END_OPACITY, parsing);
  opacity = epur_str(opacity);
  if (opacity[0] != '\0')
    {
      if (my_str_isnum(opacity) != 1)
	my_fputstr("Argument for opacity is not a number\n");
      content->o->pv->opacity = atof(opacity);
    }
  return (1);
}

int		object_ray_in(char *str, struct s_parsing *parsing,
			struct s_content *content)
{
  char		*ray;

  ray = end_token(str, END_RAY_IN, parsing);
  ray = epur_str(ray);
  if (ray[0] != '\0')
    {
      if (my_str_isnum(ray) != 1)
	my_fputstr("Argument for ray_in is not a number\n");
      content->o->pv->ray_in = atof(ray);
    }
  return (1);
}

int		object_shine(char *str, struct s_parsing *parsing,
			struct s_content *content)
{
  char		*shine;

  shine = end_token(str, END_SHINE, parsing);
  shine = epur_str(shine);
  if (shine[0] != '\0')
    {
      if (my_str_isnum(shine) != 1)
	my_fputstr("Argument for shine is not a number\n");
      content->o->pv->shine = atof(shine);
    }
  return (1);
}

int		object_reflect(char *str, struct s_parsing *parsing,
			struct s_content *content)
{
  char		*reflect;

  reflect = end_token(str, END_REFLECT, parsing);
  reflect = epur_str(reflect);
  if (reflect[0] != '\0')
    {
      if (my_str_isnum(reflect) != 1)
	my_fputstr("Argument for reflect is not a number\n");
      content->o->pv->reflect = atof(reflect);
      if (content->o->pv->reflect < 0 || content->o->pv->reflect > 1)
	my_fputstr("Argument for reflect is not between 0 and 1\n");
    }
  return (1);
}

int		object_ray(char *str, struct s_parsing *parsing,
			struct s_content *content)
{
  char		*ray;

  ray = end_token(str, END_RAY, parsing);
  ray = epur_str(ray);
  if (ray[0] != '\0')
    {
      if (my_str_isnum(ray) != 1)
	my_fputstr("Argument for ray is not a number\n");
      content->o->pv->ray = atof(ray);
    }
  return (1);
}
