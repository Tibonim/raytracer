#include "rtracer.h"

int		default_eye(t_eye *e)
{
  e->pos.vec.x = e->def.vec.x;
  e->pos.vec.y = e->def.vec.y;
  e->pos.vec.z = e->def.vec.z;
  e->pos.pt.x = e->def.pt.x;
  e->pos.pt.y = e->def.pt.y;
  e->pos.pt.z = e->def.pt.z;
  return (0);
}

void		first_eye(t_eye *e)
{
  e->def.vec.x = EYE_VEC_LEN;
  e->def.vec.y = (WIN_X / 2) - e->img.pos.x;
  e->def.vec.z = (WIN_Y / 2) - e->img.pos.y;
  rotate_x(&e->def.vec, e->def.rot.x);
  rotate_y(&e->def.vec, e->def.rot.y);
  rotate_z(&e->def.vec, e->def.rot.z);
  default_eye(e);
}
