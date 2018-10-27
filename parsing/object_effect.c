#include "rtracer.h"
#include "parsing.h"

int		object_wave(char *str, struct s_parsing *parsing,
			struct s_content *content)
{
  char		*wave;
  int		nb;

  wave = end_token(str, END_WAVE, parsing);
  wave = epur_str(wave);
  if (wave[0] != '\0')
    {
      if (my_str_isnum(wave) != 1)
	my_fputstr("Argument for wave is not a number\n");
      nb = my_atoi_base(wave, "0123456789");
      if (nb == 0 || nb == 1)
	content->o->pv->wave = nb;
      else
	my_fputstr("Argument for wave must be 0 or 1\n");
    }
  return (1);
}

int		object_chess(char *str, struct s_parsing *parsing,
			struct s_content *content)
{
  char		*chess;
  int		nb;

  chess = end_token(str, END_CHESS, parsing);
  chess = epur_str(chess);
  if (chess[0] != '\0')
    {
      if (my_str_isnum(chess) != 1)
	my_fputstr("Argument for chess is not a number\n");
      nb = my_atoi_base(chess, "0123456789");
      if (nb == 0 || nb == 1)
	content->o->pv->chess = nb;
      else
	my_fputstr("Argument for chess must be 0 or 1\n");
    }
  return (1);
}
