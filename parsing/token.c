#include "rtracer.h"
#include "parsing.h"

int	token_end_scene(char *str, struct s_parsing *parsing)
{
  if (my_strncmp(str, SCENE, my_strlen(SCENE)) == 0)
    {
      if (parsing->scene == 1)
	my_fputstr("Error in parsing token scene into an other\n");
      parsing->scene = 1;
      return (1);
    }
  if (my_strncmp(str, END_SCENE, my_strlen(END_SCENE)) == 0)
    {
      if (parsing->scene == 0)
	my_fputstr(END_SCENE);
      parsing->scene = 0;
      return (1);
    }
  return (0);
}

int	token_eye(char *str, struct s_parsing *parsing,
		   struct s_content *content)
{
  if (parsing->cam == 1)
    {
      if (my_strncmp(str, POSITION, my_strlen(POSITION)) == 0)
	return (eye_position(&(str[my_strlen(POSITION)]), parsing, content));
      if (my_strncmp(str, ROTATION, my_strlen(ROTATION)) == 0)
	return (eye_rotation(&(str[my_strlen(ROTATION)]), parsing, content));
      if (my_strncmp(str, ALIASING, my_strlen(ALIASING)) == 0)
	return (eye_aliasing(&(str[my_strlen(ALIASING)]), parsing, content));
      if (my_strncmp(str, FAST, my_strlen(FAST)) == 0)
	return (eye_fast(&(str[my_strlen(FAST)]), parsing, content));
    }
  return (token_end_scene(str, parsing));
}

int	token_light(char *str, struct s_parsing *parsing,
		   struct s_content *content)
{
  if (parsing->light == 1)
    {
      if (my_strncmp(str, POSITION, my_strlen(POSITION)) == 0)
	return (light_position(&(str[my_strlen(POSITION)]), parsing, content));
      if (my_strncmp(str, COLOR, my_strlen(COLOR)) == 0)
	return (light_color(&(str[my_strlen(COLOR)]), parsing, content));
    }
  return (token_eye(str, parsing, content));
}

int	token_object_effect(char *str, struct s_parsing *parsing,
		   struct s_content *content)
{
  if (my_strncmp(str, REFLECT, my_strlen(REFLECT)) == 0)
    return (object_reflect(&(str[my_strlen(REFLECT)]), parsing, content));
  if (my_strncmp(str, CHESS, my_strlen(CHESS)) == 0)
    return (object_chess(&(str[my_strlen(CHESS)]), parsing, content));
  if (my_strncmp(str, WAVE, my_strlen(WAVE)) == 0)
    return (object_wave(&(str[my_strlen(WAVE)]), parsing, content));
  return (0);
}

int	token_object(char *str, struct s_parsing *parsing,
		   struct s_content *content)
{
  if (parsing->obj == 1)
    {
      if (my_strncmp(str, TYPE, my_strlen(TYPE)) == 0)
	return (object_type(&(str[my_strlen(TYPE)]), parsing, content));
      if (my_strncmp(str, POSITION, my_strlen(POSITION)) == 0)
	return (object_position(&(str[my_strlen(POSITION)]), parsing, content));
      if (my_strncmp(str, ROTATION, my_strlen(ROTATION)) == 0)
	return (object_rotation(&(str[my_strlen(ROTATION)]), parsing, content));
      if (my_strncmp(str, COLOR, my_strlen(COLOR)) == 0)
	return (object_color(&(str[my_strlen(COLOR)]), parsing, content));
      if (my_strncmp(str, OPACITY, my_strlen(OPACITY)) == 0)
	return (object_opacity(&(str[my_strlen(OPACITY)]), parsing, content));
      if (my_strncmp(str, SHINE, my_strlen(SHINE)) == 0)
	return (object_shine(&(str[my_strlen(SHINE)]), parsing, content));
      if (my_strncmp(str, RAY, my_strlen(RAY)) == 0)
	return (object_ray(&(str[my_strlen(RAY)]), parsing, content));
      if (my_strncmp(str, RAY_IN, my_strlen(RAY_IN)) == 0)
	return (object_ray_in(&(str[my_strlen(RAY_IN)]), parsing, content));
      if (my_strncmp(str, ANG, my_strlen(ANG)) == 0)
	return (object_ang(&(str[my_strlen(ANG)]), parsing, content));
      if (token_object_effect(str, parsing, content) == 1)
	return (1);
    }
  return (token_light(str, parsing, content));
}
