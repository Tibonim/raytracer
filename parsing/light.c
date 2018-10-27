#include "rtracer.h"
#include "parsing.h"
#include "get_next_line.h"

int		light_color(char *str, struct s_parsing *parsing,
			    struct s_content *content)
{
  char		*color;

  color = end_token(str, END_COLOR, parsing);
  color = epur_str(color);
  if (color[0] != '\0')
    {
      content->l->pv->color = my_atoi_base(color, "0123456789ABCDEF");
    }
  return (1);
}

int		light_position(char *str, struct s_parsing *parsing,
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
	      i == 0 ? content->l->pv->pt.x = nb : i == 1 ?
		content->l->pv->pt.y = nb : (content->l->pv->pt.z = nb);
	    }
	  else
	    my_fputstr("Error with number for position light\n");
	}
      i++;
    }
  return (1);
}
