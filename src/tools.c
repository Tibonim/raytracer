#include "rtracer.h"

int		my_get_nbr(char *str, int i)
{
  int		nb;
  int		sign;

  nb = 0;
  sign = 0;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    if (str[i++] == '-')
      ++sign;
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    nb = (nb * 10) + (str[i++] - 48);
  return (((sign % 2) == 1) ? ((nb) * (-1)) : (nb));
}

int		my_strcmp(char *str, char *find)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (find[j])
    {
      if (str[i] != find[j])
	return (0);
      i++;
      j++;
    }
  return (1);
}
