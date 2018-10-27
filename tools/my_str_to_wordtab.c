#include "parsing.h"
#include "rtracer.h"

int     check_delim(char c, char *delim)
{
  int   i;

  i = 0;
  if (c != 0)
    {
      while (delim[i] != 0)
	{
	  if (c != delim[i])
	    i++;
	  else
	    return (1);
	}
    }
  return (0);
}

int     count_char(char *str, char *delim, int i)
{
  int	size;

  size = 0;
  while (str[i] != 0 && check_delim(str[i], delim) == 0)
    {
      i++;
      size++;
    }
  return (size);
}

int     count_word(char *str, char *delim)
{
  int   nb;
  int   i;

  nb = 1;
  i = 0;
  while (str[i] != 0)
    {
      if (check_delim(str[i], delim) == 0 && \
      	  check_delim(str[i + 1], delim) == 1)
        {
          nb++;
          while (check_delim(str[i], delim) == 0 \
      		 && check_delim(str[i + 1], delim) == 1)
            i++;
        }
      i++;
    }
  return (nb);
}

void	init_a_b(int *a, int *b)
{
  *a = 0;
  *b = 0;
}

char    **my_str_to_wordtab(char *str, char *delim)
{
  char	**wordtab;
  int	i;
  int	ct_tab;
  int	j;

  init_a_b(&i, &ct_tab);
  if (str[0] == 0 || str == NULL)
    return (NULL);
  if ((wordtab = malloc((count_word(str, delim) + 1) \
			* sizeof(*wordtab))) == NULL)
    return (NULL);
  while (str[i] && ct_tab < count_word(str, delim))
    {
      while (check_delim(str[i], delim) == 1 && str[i++]);
      j = 0;
      if ((wordtab[ct_tab] = malloc(count_char(str, delim, i) + 1)) == NULL)
	return (NULL);
      while (check_delim(str[i], delim) == 0 && str[i])
	wordtab[ct_tab][j++] = str[i++];
      wordtab[ct_tab][j] = '\0';
      while (check_delim(str[i], delim) == 1 && str[i++]);
      ct_tab++;
    }
  wordtab[ct_tab] = NULL;
  return (wordtab);
}
