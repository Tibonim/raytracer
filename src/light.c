#include "rtracer.h"

unsigned int	get_new_col(unsigned int col, float cos)
{
  unsigned int  r;
  unsigned int  g;
  unsigned int  b;

  r = ((col >> 16) & 0xFF) * cos;
  g = ((col >> 8) & 0xFF) * cos;
  b = ((col) & 0xFF) * cos;
  return (createRGB(r, g, b));
}

unsigned int	add_col(unsigned int col1, unsigned int col2)
{
  unsigned int  r;
  unsigned int  g;
  unsigned int  b;

  r = (((col1 >> 16) & 0xFF) + ((col2 >> 16) & 0xFF)) / 2;
  g = (((col1 >> 8) & 0xFF) + ((col2 >> 8) & 0xFF)) / 2;
  b = (((col1) & 0xFF) + ((col2) & 0xFF)) / 2;
  return (createRGB(r, g, b));
}

unsigned int	shine(unsigned int col, float shine,
		      unsigned int spot, float cos)
{
  unsigned int  r;
  unsigned int  g;
  unsigned int  b;

  r = ((col >> 16) & 0xFF) + (shine * ((spot >> 16) & 0xFF) * cos);
  g = ((col >> 8) & 0xFF) + (shine * ((spot >> 8) & 0xFF) * cos);
  b = ((col) & 0xFF) + (shine * ((spot) & 0xFF) * cos);
  if (r > 255)
    r = 255;
  if (g > 255)
    g = 255;
  if (b > 255)
    b = 255;
  return (createRGB(r, g, b));
}

unsigned int	get_spot_light(t_eye *e, t_light *it)
{
  float		cos;
  float		scal;
  float		norm;
  float		lum;
  unsigned int	col;

  scal = (e->inter.norm.x * (it->pt.x - e->inter.pt.x))
    + (e->inter.norm.y * (it->pt.y - e->inter.pt.y))
    + (e->inter.norm.z * (it->pt.z - e->inter.pt.z));
  norm = (sqrt(pow(e->inter.norm.x, 2) + pow(e->inter.norm.y, 2)
	       + pow(e->inter.norm.z, 2)));
  lum = (sqrt(pow((it->pt.x - e->inter.pt.x), 2)
	      + pow((it->pt.y - e->inter.pt.y), 2)
	      + pow((it->pt.z - e->inter.pt.z), 2)));
  if (norm * lum)
    cos = (scal / (norm * lum));
  else
    cos = 0;
  if (cos < 0.00001)
    cos = 0;
  col = shine(get_new_col(e->final_color, cos),
  	      e->inter.shine, it->color, cos);
  return (col);
}

unsigned int	light(t_eye *e, t_light *root)
{
  t_light	*it;
  t_eye		new;
  unsigned int	comp;

  new = (*e);
  it = root->nx;
  if (it == root)
    return (new.final_color);
  comp = get_spot_light(&new, it);
  it = it->nx;
  while (it != root)
    {
      comp = add_col(get_spot_light(&new, it), comp);
      it = it->nx;
    }
  return (comp);
}
