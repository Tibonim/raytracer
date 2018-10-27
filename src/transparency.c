#include "rtracer.h"

float	get_trans(t_content *c, t_eye *e)
{
  t_obj	*ptr;

  ptr = c->o->nx;
  while (ptr != c->o)
    {
      if (e->inter.id == ptr->id)
	return (ptr->opacity);
      ptr = ptr->nx;
    }
  return (1);
}

int	fill_trans(t_coords *trans, t_eye *new, float scal)
{
  trans->x = N_REFRAC *
    new->def.vec.x + (N_REFRAC * scal -
		      sqrt(1.0 + ((N_REFRAC * N_REFRAC) *
				  ((scal * scal) - 1.0))) * new->inter.norm.x);
  trans->y = N_REFRAC *
    new->def.vec.y + (N_REFRAC * scal -
		      sqrt(1.0 + ((N_REFRAC * N_REFRAC) *
				  ((scal * scal) - 1.0))) * new->inter.norm.y);
  trans->z = N_REFRAC *
    new->def.vec.z + (N_REFRAC * scal -
		      sqrt(1.0 + ((N_REFRAC * N_REFRAC) *
				  ((scal * scal) - 1.0))) * new->inter.norm.z);
  return (0);
}

unsigned int	transparency(t_content *c, t_eye *e)
{
  t_coords	trans;
  t_eye		new;
  float		value;
  float		scal;

  new = (*e);
  if ((value = 1 - get_trans(c, e)) == 0)
    return (e->final_color);
  normalizing(&(new.inter.norm));
  scal = new.inter.norm.x * new.pos.vec.x + new.inter.norm.y * \
    new.def.vec.y + new.inter.norm.z * new.def.vec.z;
  fill_trans(&(trans), &new, scal);
  init_reflect(&(new), &(trans));
  if (intersec(c, &new, e->inter.id) == 0)
    {
      new.final_color = new.inter.color;
      new.final_color = light(&new, c->l);
      new.final_color = transparency(c, &new);
      new.final_color = shadow(&new, c);
      new.final_color = reflect(c, &new);
      return (get_new_ref(new.final_color, e->final_color, value));
    }
  return (get_new_ref(0, e->final_color, value));
}
