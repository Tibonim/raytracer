#include "rtracer.h"
#include "parsing.h"

void	my_end_error(char *token)
{
  write(2, "No end of token for ", 20);
  write(2, token, my_strlen(token));
  my_fputstr("\n");
}

char	*realloc_token(char *tmp, char c)
{
  char	*str;
  int	i;

  if ((str = malloc(sizeof(char) * (my_strlen(tmp) + 2))) == NULL)
    my_fputstr("Error with malloc in realloc_token\n");
  i = 0;
  while (tmp[i] != '\0')
    {
      str[i] = tmp[i];
      i++;
    }
  str[i++] = c;
  str[i] = '\0';
  if (tmp != NULL)
    free (tmp);
  return (str);
}

void	unexpected_token(char *token)
{
  write(2, "Error unexpected token this one: ", 33);
  write(2, token, my_strlen(token));
  my_fputstr(" was expected.\n");
}

char	*end_token(char *str, char *token, struct s_parsing *parsing)
{
  int	i;
  char	*tmp;

  i = 0;
  if ((tmp = malloc(sizeof(char) * 1)) == NULL)
    my_fputstr("Error with malloc in end_token\n");
  tmp[0] = '\0';
  while (str != NULL && my_strncmp(&(str[i]), token, my_strlen(token)) != 0)
    {
      if (str[i] != '\0')
	tmp = realloc_token(tmp, str[i]);
      if (str[i] == '<')
	unexpected_token(token);
      if (str[i] == '\0')
	{
	  str = get_next_line(parsing->fd);
	  parsing->str = str;
	  i = -1;
	}
      i++;
    }
  if (str == NULL)
    my_end_error(token);
  parsing->str = &(str[i + my_strlen(token) - 1]);
  return (tmp);
}
