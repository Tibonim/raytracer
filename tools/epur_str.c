/#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parsing.h"

int	check_fin(char *str, int i)
{
  while (str[i] != '\0')
    {
      if (str[i] != '\t' && str[i] != ' ')
	return (0);
      i++;
    }
  return (1);
}

int	my_strlen_epur2(char *str, int i, int j)
{
  while (str[i] != '\0')
    {
      if (check_fin(str, i) == 1)
	{
	  while (str[i] != '\0')
	    {
	      i++;
	      j++;
	    }
	  return (i - j);
	}
      if (str[i] == ' ' || str[i] == '\t')
	{
	  if (str[i - 1] == ' ' || str[i - 1] == '\t')
	    j++;
	}
      i++;
    }
  return (i - j);
}

int	my_strlen_epur(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (str[0] == ' ' || str[0] == '\t')
    {
      i++;
      j++;
    }
  while (str[i] == ' ' || str[i] == '\t')
    {
      i++;
      j++;
    }
  return (my_strlen_epur2(str, i, j));
}

char	*my_dest(char *str, char *dest, int i, int j)
{
  if (i == 0 && str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	dest[j++] = str[i];
      i++;
    }
  while (str[i] != '\0')
    {
      if (check_fin(str, i) == 1)
	{
	  dest[j] = '\0';
	  free (str);
	  return (dest);
	}
      if (str[i] != ' ' && str[i] != '\t')
	dest[j++] = str[i];
      else if ((str[i] == ' ' || str[i] == '\t')
	       && (str[i - 1] != ' ' && str[i - 1] != '\t'))
	dest[j++] = ' ';
      i++;
    }
  free (str);
  dest[j] = '\0';
  return (dest);
}

char	*epur_str(char *str)
{
  int	i;
  char	*dest;
  int	j;

  i = 0;
  j = 0;
  if ((dest = malloc(sizeof(char) * (my_strlen_epur(str) + 1))) == NULL)
    my_fputstr("error with malloc in epur_str\n");
  while (str[i] == '\t' || str[i] == ' ')
    i++;
  return (my_dest(str, dest, i, j));
}
