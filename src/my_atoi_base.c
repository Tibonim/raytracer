#include "rtracer.h"

int		base_len(char *bs)
{
  int		i;

  i = 0;
  while (bs[i])
    i++;
  return (i);
}

int		my_pow(int i, int p)
{
  int		tp;

  tp = i;
  if (p == 0)
    return (1);
  while (p > 1)
    {
      i = i * tp;
      p--;
    }
  return (i);
}

int		get_num(char c, char *base)
{
  int		i;

  i = 0;
  while (base[i] != c && base[i])
    i++;
  return (i);
}

int		my_atoi_base(char *str, char *base)
{
  int		res;
  int		i;
  int		p;
  int		l;

  res = 0;
  i = 0;
  p = 0;
  l = base_len(base);
  while (str[i])
    i++;
  i--;
  while (i >= 0)
    {
      res = res + (my_pow(l, p) * get_num(str[i], base));
      p++;
      i--;
    }
  return (res);
}
