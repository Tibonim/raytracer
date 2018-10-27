#include "rtracer.h"
#include "bitmap.h"

void		init_bmp(t_header *header, t_image *image)
{
  header->magic = 0x4d42;
  header->folder_size = sizeof(*header);
  header->reserved = 0;
  header->offset = sizeof(*header) + sizeof(*image);
  image->size_head = sizeof(*image);
  image->image_width = WIN_X;
  image->image_height = WIN_Y;
  image->plans = 1;
  image->deep_color = 24;
  image->comp_met = 0;
  image->size_image = WIN_X * WIN_Y * 4;
  image->res_x = 0;
  image->res_y = 0;
  image->nb_color = 0;
  image->color_imp = 0;
}

void		fill_bmp(struct s_content *c, int fd, t_eye *e)
{
  int		x;
  int		y;

  my_putstr("Loading...\n");
  y = WIN_Y - 1;
  while (y >= 0)
    {
      x = 0;
      while (x < WIN_X)
	{
	  write(fd, &(e->img.data[(x * 4) +
					 (y * c->p.sizeline)]), 3);
	  x++;
	}
      y--;
    }
  my_putstr("Loading completed\n");
}

t_eye		*get_eye(struct s_content *c)
{
  int		i;
  t_eye		*tmp;

  i = 0;
  tmp = c->e;
  while (i < c->eye_select)
    {
      tmp = tmp->nx;
      i++;
    }
  return (tmp);
}

void		my_bmp(struct s_content *c)
{
  char		*file;
  int		len;
  t_header	header;
  t_image	image;
  int		fd;
  t_eye		*e;

  file = c->file;
  len = my_strlen(file);
  file[len - 1] = 'p';
  file[len - 2] = 'm';
  file[len - 3] = 'b';
  fd = open(file, O_CREAT | O_WRONLY, 0666);
  if ((access(file, W_OK)) == -1)
    my_fputstr("Error with access for bitmap\n");
  if (fd <= 1)
    my_fputstr("Error with open for bitmap\n");
  init_bmp(&(header), &(image));
  e = get_eye(c);
  write(fd, &header, sizeof(header));
  write(fd, &image, sizeof(image));
  fill_bmp(c, fd, e);
}
