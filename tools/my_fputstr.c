#include "rtracer.h"

void	error_main_token(char *token)
{
  write(2, "Error in parsing: token ", 24);
  write(2, token, my_strlen(token));
  write(2, " found but no ", 14);
  if (my_strcmp(token, "</camera>") == 1)
    write(2, "camera", 6);
  if (my_strcmp(token, "</light>") == 1)
    write(2, "light", 5);
  if (my_strcmp(token, "</object>") == 1)
    write(2, "object", 6);
  my_fputstr(" initialized\n");
}

void	my_fputstr(char *str)
{
  write(2, str, my_strlen(str));
  exit(EXIT_FAILURE);
}
