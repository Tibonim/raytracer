#include "rtracer.h"

void		usage()
{
  write(2, "Usage: ./rt <[file].sc>\n", 24);
}

void		put_err(char c)
{
  write(2, &c, 1);
}

void		error_msg(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    put_err(str[i++]);
}

void		sys_failed(char *fun, int op)
{
  int		i;

  i = 0;
  write(2, "Error: ", 7);
  while (fun[i])
    {
      put_err(fun[i]);
      i++;
    }
  write(2, " failed.\n", 9);
  if (op == 1)
    exit(-1);
}
