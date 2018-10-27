#include "rtracer.h"

int		my_len(char *str, int i)
{
  int		l;

  l = 0;
  while (str[i] && str[i] != '\n')
    {
      l++;
      i++;
    }
  return (l);
}

char		*my_realloc(char *str, int l)
{
  char		*new;
  int		i;

  if (l == 0)
    return (str);
  if ((new = malloc(my_len(str, 0) + l + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      new[i] = str[i];
      i++;
    }
  free(str);
  return (new);
}

int		line_maker(t_line *s, char *buff)
{
  static int	i = 0;
  static int	j = 0;
  int		l;

  l = my_len(buff, i);
  if (j == 0)
    {
      if ((s->line = malloc(sizeof(char) * l + 1)) == NULL)
	return (-1);
      s->line[l] = '\0';
    }
  else
    s->line = my_realloc(s->line, l);
  while (buff[i] != '\n')
    {
      if (buff[i] == '\0')
	{
	  i = 0;
	  return (0);
	}
      s->line[j++] = buff[i++];
    }
  i++;
  j = 0;
  return (1);
}

char		*get_next_line(const int fd)
{
  static char	buff[SIZE + 1];
  static int	r = -1;
  t_line	s;

  if (r >= 0)
    if (line_maker(&s, buff) == 1)
      {
	if (s.line[0] == '\0')
	  return (s.line);
	else
	  return (s.line);
      }
  while ((r = read(fd, buff, SIZE)) > 0)
    {
      buff[r] = '\0';
      if (line_maker(&s, buff) == 1)
	return (s.line);
    }
  return (NULL);
}
