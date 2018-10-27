#include "rtracer.h"
#include "parsing.h"
#include "get_next_line.h"

int		eye_position(char *str, struct s_parsing *parsing,
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
	      i == 0 ? content->e->pv->def.pt.x = nb : i == 1 ?
		content->e->pv->def.pt.y = nb : (content->e->pv->def.pt.z = nb);
	    }
	  else
	    my_fputstr("Error with number for position eye\n");
	}
      i++;
    }
  return (1);
}

int		eye_aliasing(char *str, struct s_parsing *parsing,
			struct s_content *content)
{
  char		*aliasing;
  double	nb;

  aliasing = end_token(str, END_ALIASING, parsing);
  aliasing = epur_str(aliasing);
  if (aliasing[0] != '\0')
    {
      if (my_str_isnum(aliasing) != 1)
	my_fputstr("Argument for aliasing is not a number\n");
      nb = my_atoi_base(aliasing, "0123456789");
      if (nb == 0 || nb == 1)
	content->e->pv->aliasing = nb;
      else
	my_fputstr("Argument for aliasing must be 0 or 1\n");
    }
  return (1);
}

int		eye_fast(char *str, struct s_parsing *parsing,
			struct s_content *content)
{
  char		*fast;
  double	nb;

  fast = end_token(str, END_FAST, parsing);
  fast = epur_str(fast);
  if (fast[0] != '\0')
    {
      if (my_str_isnum(fast) != 1)
	my_fputstr("Argument for fast is not a number\n");
      nb = my_atoi_base(fast, "0123456789");
      if (nb == 0 || nb == 1)
	content->e->pv->fast = nb;
      else
	my_fputstr("Argument for fast must be 0 or 1\n");
    }
  return (1);
}

int		eye_rotation(char *str, struct s_parsing *parsing,
			struct s_content *content)
{
  char		*rotation;
  char		**tab;
  int		i;
  double	nb;

  i = -1;
  rotation = end_token(str, END_ROTATION, parsing);
  rotation = epur_str(rotation);
  tab = my_str_to_wordtab(rotation, " ");
  while (tab != NULL && tab[++i] != NULL)
    {
      if (i == 0 || i == 1 || i == 2)
	{
	  if (my_str_isnum(tab[i]) == 1)
	    {
	      nb = atof(tab[i]);
	      i == 0 ? content->e->pv->def.rot.x = nb : i == 1 ?
		content->e->pv->def.rot.y = nb : \
		(content->e->pv->def.rot.z = nb);
	    }
	  else
	    my_fputstr("Error with number for position eye\n");
	}
    }
  return (1);
}
