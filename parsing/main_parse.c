#include "rtracer.h"
#include "parsing.h"

int		main_parse(struct s_content *parser, char *file)
{
  parsing(file, parser);
  if (parser->e->nx == parser->e)
    my_fputstr("No eye configured\n");
  return (0);
}
