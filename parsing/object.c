#include "rtracer.h"
#include "parsing.h"
#include "get_next_line.h"

int		object_ang(char *str, struct s_parsing *parsing,
			   struct s_content *content)
{
  char		*ang;

  ang = end_token(str, END_ANG, parsing);
  ang = epur_str(ang);
  if (ang[0] != '\0')
    {
      if (my_str_isnum(ang) != 1)
	my_fputstr("Argument for angle is not a number\n");
      content->o->pv->ang = atof(ang);
    }
  return (1);
}

int		object_color(char *str, struct s_parsing *parsing,
			     struct s_content *content)
{
  char		*color;

  color = end_token(str, END_COLOR, parsing);
  color = epur_str(color);
  if (color[0] != '\0')
    {
      content->o->pv->color = my_atoi_base(color, "0123456789ABCDEF");
    }
  return (1);
}

int		object_rotation(char *str, struct s_parsing *parsing,
				struct s_content *content)
{
  char		*rotation;
  char		**tab;
  int		i;
  double	nb;

  i = 0;
  rotation = end_token(str, END_ROTATION, parsing);
  rotation = epur_str(rotation);
  tab = my_str_to_wordtab(rotation, " ");
  while (tab != NULL && tab[i] != NULL)
    {
      if (i == 0 || i == 1 || i == 2)
	{
	  if (my_str_isnum(tab[i]) == 1)
	    {
	      nb = atof(tab[i]);
	      i == 0 ? content->o->pv->rot.x = nb : i == 1 ?
		content->o->pv->rot.y = nb : (content->o->pv->rot.z = nb);
	    }
	  else
	    my_fputstr("Error with number for rotation obj\n");
	}
      i++;
    }
  return (1);
}

int		object_position(char *str, struct s_parsing *parsing,
			struct s_content *content)
{
  char		*position;
  char		**tab;
  int		i;
  double	nb;

  i = 0;
  position = end_token(str, END_POSITION, parsing);
  position = epur_str(position);
  tab = my_str_to_wordtab(position, " ");
  while (tab != NULL && tab[i] != NULL)
    {
      if (i == 0 || i == 1 || i == 2)
	{
	  if (my_str_isnum(tab[i]) == 1)
	    {
	      nb = atof(tab[i]);
	      i == 0 ? content->o->pv->pt.x = nb : i == 1 ?
		content->o->pv->pt.y = nb : (content->o->pv->pt.z = nb);
	    }
	  else
	    my_fputstr("Error with number for position obj\n");
	}
      i++;
    }
  return (1);
}

int	object_type(char *str, struct s_parsing *parsing, struct s_content
		    *content)
{
  char	*type;

  type = end_token(str, END_TYPE, parsing);
  type = epur_str(type);
  if (my_strcmp(type, "sphere") == 1)
    content->o->pv->type = 1;
  else if (my_strcmp(type, "plan") == 1)
    content->o->pv->type = 0;
  else if (my_strcmp(type, "cylinder") == 1)
    content->o->pv->type = 2;
  else if (my_strcmp(type, "cone") == 1)
    content->o->pv->type = 3;
  else if (my_strcmp(type, "hyperbool") == 1)
    content->o->pv->type = 4;
  else if (my_strcmp(type, "parabool") == 1)
    content->o->pv->type = 5;
  else
    my_fputstr("Unknown type for object\n");
  return (1);
}
