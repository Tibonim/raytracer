#include "rtracer.h"

void		get_norm(t_eye *e, t_obj *o)
{
  e->inter.norm.x = e->inter.pt.x;
  e->inter.norm.y = e->inter.pt.y;
  if (o->type == SPHERE)
    e->inter.norm.z = e->inter.pt.z;
  else if (o->type == CYLINDER)
    e->inter.norm.z = 0;
  else if (o->type == PLAN)
    {
      e->inter.norm.x = 0;
      e->inter.norm.y = 0;
      e->inter.norm.z = 100;
      if (o->wave == 1)
	do_waves_plane(e);
      if (o->chess == 1)
	do_chess_plane(e);
    }
  else if (o->type == CONE || o->type == HYPERBOOL || o->type == PARABOOL)
    e->inter.norm.z = e->inter.pt.z * -tanf(o->ang);
  rotate_x(&e->inter.norm, (o->rot.x));
  rotate_y(&e->inter.norm, (o->rot.y));
  rotate_z(&e->inter.norm, (o->rot.z));
}

void		get_inter_inf(t_eye *e, t_obj *o)
{
  e->inter.pt.x = e->def.pt.x + (e->inter.k * e->def.vec.x);
  e->inter.pt.y = e->def.pt.y + (e->inter.k * e->def.vec.y);
  e->inter.pt.z = e->def.pt.z + (e->inter.k * e->def.vec.z);
  get_norm(e, o);
  e->inter.shine = o->shine;
}
