#include "rtracer.h"

float	get_reflect(t_content *c, t_eye *e)
{
  t_obj	*ptr;

  ptr = c->o->nx;
  while (ptr != c->o)
    {
      if (e->inter.id == ptr->id)
	return (ptr->reflect);
      ptr = ptr->nx;
    }
  return (0);
}

void	init_reflect(t_eye *eye, t_coords *ray)
{
  eye->def.pt.x = eye->inter.pt.x;
  eye->def.pt.y = eye->inter.pt.y;
  eye->def.pt.z = eye->inter.pt.z;
  eye->def.vec.x = ray->x;
  eye->def.vec.y = ray->y;
  eye->def.vec.z = ray->z;
  eye->def.rot.x = 0.0;
  eye->def.rot.y = 0.0;
  eye->def.rot.z = 0.0;
  eye->inter.color = 0;
  eye->final_color = 0;
}

unsigned int    get_new_ref(unsigned int col, unsigned int col2, float ref)
{
  unsigned int  r;
  unsigned int  g;
  unsigned int  b;
  unsigned int	r2;
  unsigned int	g2;
  unsigned int	b2;

  r = ((col >> 16) & 0xFF);
  r2 = ((col2 >> 16) & 0xFF);
  g = ((col >> 8) & 0xFF);
  g2 = ((col2 >> 8) & 0xFF);
  b = ((col) & 0xFF);
  b2 = ((col2) & 0xFF);
  r = r * ref + r2 * (1 - ref);
  g = g * ref + g2 * (1 - ref);
  b = b * ref + b2 * (1 - ref);
  return (createRGB(r, g, b));
}

int	get_r_ray(t_coords *ray, float sca, t_coords *pt, t_coords *pt2)
{
  ray->x = -2.0 * pt->x * sca + pt2->x;
  ray->y = -2.0 * pt->y * sca + pt2->y;
  ray->z = -2.0 * pt->z * sca + pt2->z;
  return (0);
}

unsigned int	reflect(t_content *c, t_eye *e)
{
  t_coords	r_ray;
  float		scal;
  t_eye		new;
  float		refl;

  new = (*e);
  if ((refl = get_reflect(c, e)) == 0)
    return (e->final_color);
  normalizing(&(new.inter.norm));
  scal = new.inter.norm.x * new.def.vec.x + new.inter.norm.y *	\
    new.def.vec.y + new.inter.norm.z * new.def.vec.z;
  get_r_ray(&r_ray, scal, &(new.inter.norm), &(new.def.vec));
  init_reflect(&new, &(r_ray));
  if (intersec(c, &new, e->inter.id) == 0)
    {
      new.final_color = new.inter.color;
      new.final_color = light(&new, c->l);
      new.final_color = shadow(&new, c);
      new.final_color = reflect(c, &new);
      new.final_color = transparency(c, &new);
      return (get_new_ref(new.final_color, e->final_color, refl));
    }
  return (get_new_ref(0, e->final_color, refl));
}
