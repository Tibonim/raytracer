#include "parsing.h"
#include "rtracer.h"
#include "get_next_line.h"

void	token_unknown(char *token)
{
  int	i;

  i = 0;
  write(2, "Token : ", 8);
  while (token[i] != '\0' && token[i] != '>')
    {
      write(2, &(token[i]), 1);
      i++;
    }
  if (token[i] == '>')
    write(2, &(token[i]), 1);
  my_fputstr(" is unknown or wrongly placed\n");
}

int	check_token_scene(struct s_parsing *parsing)
{
  int	nb;

  nb = 0;
  if (parsing->obj == 1)
    nb++;
  if (parsing->cam == 1)
    nb++;
  if (parsing->light == 1)
    nb++;
  if (nb > 1)
    my_fputstr("Multiple Token Content: one found into an other\n");
  return (1);
}

int	token_scene_2(char *str, struct s_parsing *parsing,
		      struct s_content *content)
{
  if (my_strncmp(str, END_LIGHT, my_strlen(END_LIGHT)) == 0)
    {
      if (parsing->light == 0)
	error_main_token(END_LIGHT);
      parsing->light = 0;
      return (check_token_scene(parsing));
    }
  if (my_strncmp(str, OBJECT, my_strlen(OBJECT)) == 0)
    {
      if (parsing->obj == 1)
	my_fputstr("Error in parsing token object into an other\n");
      parsing->obj = 1;
      o_add_before(content->o);
      return (check_token_scene(parsing));
    }
  if (my_strncmp(str, END_OBJECT, my_strlen(END_OBJECT)) == 0)
    {
      if (parsing->obj == 0)
	error_main_token(END_OBJECT);
      parsing->obj = 0;
      if (content->o->pv->type == -1)
	my_fputstr("No type entered for object\n");
      return (check_token_scene(parsing));
    }
  return (token_object(str, parsing, content));
}

int	token_scene(char *str, struct s_parsing *parsing,
		    struct s_content *content)
{
  if (my_strncmp(str, CAMERA, my_strlen(CAMERA)) == 0)
    {
      if (parsing->cam == 1)
	my_fputstr("Error in parsing token camera into an other\n");
      parsing->cam = 1;
      e_add_before(content->e);
      return (check_token_scene(parsing));
    }
  if (my_strncmp(str, END_CAMERA, my_strlen(END_CAMERA)) == 0)
    {
      if (parsing->cam == 0)
	error_main_token(END_CAMERA);
      parsing->cam = 0;
      return (check_token_scene(parsing));
    }
  if (my_strncmp(str, LIGHT, my_strlen(LIGHT)) == 0)
    {
      if (parsing->light == 1)
	my_fputstr("Error in parsing token light into an other\n");
      parsing->light = 1;
      l_add_before(content->l);
      return (check_token_scene(parsing));
    }
  return (token_scene_2(str, parsing, content));
}

void	begin_scene(struct s_parsing *parsing, struct s_content *content)
{
  while (*parsing->str)
    {
      if (*parsing->str == '<')
	if (token_scene(&(*parsing->str), parsing, content) == 0)
	  token_unknown(&(*parsing->str));
      parsing->str++;
    }
  while ((parsing->str = get_next_line(parsing->fd)))
    {
      if (parsing->str[0] != '#')
	{
	  while (*parsing->str)
	    {
	      if (*parsing->str == '<')
		if (token_scene(&(*parsing->str), parsing, content) == 0)
		  token_unknown(&(*parsing->str));
	      parsing->str++;
	    }
	}
    }
}
