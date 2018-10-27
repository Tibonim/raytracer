#include <sys/stat.h>
#include <fcntl.h>
#include "rtracer.h"
#include "parsing.h"

void			check_end_parse(struct s_parsing *parsing)
{
  if (parsing->scene != 0)
    my_fputstr("No end of token scene\n");
}

int			fill_parse(struct s_content *content, int fd)
{
  struct s_parsing	parsing;
  int			i;

  parsing.cam = 0;
  parsing.light = 0;
  parsing.obj = 0;
  parsing.str = NULL;
  parsing.fd = fd;
  while ((parsing.str = get_next_line(fd)))
    {
        i = 0;
	while (parsing.str[i] != '\0')
	  {
	    if (my_strncmp(&(parsing.str[i]), SCENE, my_strlen(SCENE)) == 0)
	      {
		parsing.scene = 1;
		parsing.str = &(parsing.str[i + my_strlen(SCENE)]);
		begin_scene(&(parsing), content);
		check_end_parse(&(parsing));
		return (1);
	      }
	    i++;
	  }
    }
  return (0);
}

int	parsing(char *str, struct s_content *parser)
{
  int	len;
  int	fd;

  len = my_strlen(str);
  if (len >= 5)
    {
      if (my_strcmp(&(str[len - 4]), ".xml") == 1)
	{
	  if ((fd = open(str, O_RDONLY)) == -1)
	    my_fputstr("Error with open in check_extension\n");
	  if (fill_parse(parser, fd) == 0)
	    my_fputstr("No scene found in file\n");
	  parser->file = str;
	  close(fd);
	}
      else
	my_fputstr("Error with extension in arguments\n");
  }
  return (0);
}
