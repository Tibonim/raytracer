#include "rtracer.h"

int		get_current_ld(t_eye *e)
{
  int		res;

  res = (e->img.i * 100) / (WIN_X * WIN_Y);
  return (res);
}

int		get_total_ld(t_content *c)
{
  int		res;
  int		i;
  t_eye		*it;

  it = c->e->nx;
  i = 0;
  while (it != c->e)
    {
      i = i + it->img.i;
      it = it->nx;
    }
  res = (i * 100) / ((WIN_X * WIN_Y) * c->eyes_num);
  return (res);
}

void		put_cur_ld_nx(int cur, t_eye *e, int j)
{
  int		x;
  int		y;

  x = (WIN_X / 2) + 50;
  y = (WIN_Y / 2) + 50;
  while ((j <= cur) && (x >= ((WIN_X / 2) - 50)))
    {
      my_pixel_put_to_image((WIN_X * y) + x, 0xFFFFFF, e->loading.data);
      j++;
      x--;
    }
  while ((j <= cur) && (y >= ((WIN_Y / 2) - 50)))
    {
      my_pixel_put_to_image((WIN_X * y) + x, 0xFFFFFF, e->loading.data);
      j++;
      y--;
    }
}

void		put_cur_ld(int cur, t_eye *e)
{
  int		j;
  int		x;
  int		y;

  x = (WIN_X / 2) - 50;
  y = (WIN_Y / 2) - 50;
  j = 0;
  while ((j <= cur) && (x <= ((WIN_X / 2) + 50)))
    {
      my_pixel_put_to_image((WIN_X * y) + x, 0xFFFFFF, e->loading.data);
      j++;
      x++;
    }
  while ((j <= cur) && (y <= ((WIN_Y / 2) + 50)))
    {
      my_pixel_put_to_image((WIN_X * y) + x, 0xFFFFFF, e->loading.data);
      j++;
      y++;
    }
  if (j <= cur)
    put_cur_ld_nx(cur, e, j);
}

int		put_loads(int cur, int total, t_eye *e, t_content *c)
{
  int		i;
  int		max;

  i = 0;
  c = c;
  max = (total * WIN_X) / 100;
  while (i <= max)
    {
      my_pixel_put_to_image((WIN_X * (WIN_Y - 2)) + i, 0xFFFFFF, e->img.data);
      my_pixel_put_to_image((WIN_X * (WIN_Y - 2)) + i, 0xFFFFFF,
			    e->loading.data);
      my_pixel_put_to_image((WIN_X * (WIN_Y - 2)) + i, 0xFFFFFF, e->img.data);
      my_pixel_put_to_image((WIN_X * (WIN_Y - 1)) + i, 0xFFFFFF,
			    e->loading.data);
      i++;
    }
  put_cur_ld(cur * 4, e);
  if (cur != 100)
    return (0);
  else
    return (1);
}
