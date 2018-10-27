#include "rtracer.h"

void		init_shadow(t_eye *new, t_light *l, t_eye *e)
{
  new->def.pt.x = e->inter.pt.x;
  new->def.pt.y = e->inter.pt.y;
  new->def.pt.z = e->inter.pt.z;
  new->def.vec.x = l->pt.x - e->inter.pt.x;
  new->def.vec.y = l->pt.y - e->inter.pt.y;
  new->def.vec.z = l->pt.z - e->inter.pt.z;
  new->def.rot.x = 0;
  new->def.rot.y = 0;
  new->def.rot.z = 0;
}

unsigned int	createRGB(int r, int g, int b)
{
  return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

unsigned int	go_dark(unsigned int col)
{
  unsigned int  r;
  unsigned int  g;
  unsigned int  b;
  float		fac;

  fac = 2;
  r = ((col >> 16) & 0xFF) / fac;
  g = ((col >> 8) & 0xFF) / fac;
  b = ((col) & 0xFF) / fac;
  return (createRGB(r, g, b));
}

int		shadow(t_eye *e, t_content *c)
{
  t_light	*it;
  t_eye		new;
  int		i;

  i = 0;
  it = c->l->nx;
  while (it != c->l)
    {
      new = (*e);
      init_shadow(&new, it, e);
      intersec(c, &new, e->inter.id);
      if (new.inter.k < 1.0 && new.inter.k > 0.00001 &&
	  e->inter.id != new.inter.id)
	i++;
      it = it->nx;
    }
  while (i > 0)
    {
      new.final_color = go_dark(new.final_color);
      i--;
    }
  return (new.final_color);
}
