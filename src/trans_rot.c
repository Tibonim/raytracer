#include "rtracer.h"

void		rotate_x(t_coords *eye, int r)
{
  t_coords	coords;

  coords.x = eye->x;
  coords.y = (eye->y * cos((3.1415 * r) / 180.0))
    + (eye->z * (-sin((3.1415 * r) / 180.0)));
  coords.z = (eye->y * sin((3.1415 * r) / 180.0))
    + (eye->z * cos((3.1415 * r) / 180.0));
  eye->x = coords.x;
  eye->y = coords.y;
  eye->z = coords.z;
}

void		rotate_y(t_coords *eye, int r)
{
  t_coords	coords;

  coords.x = (eye->x * cos((3.1415 * r) / 180.0))
    + (eye->z * sin((3.1415 * r) / 180.0));
  coords.y = eye->y;
  coords.z = (eye->x * (-sin((3.1415 * r) / 180.0)))
    + (eye->z * cos((3.1415 * r) / 180.0));
  eye->x = coords.x;
  eye->y = coords.y;
  eye->z = coords.z;
}

void		rotate_z(t_coords *eye, int r)
{
  t_coords	coords;

  coords.x = (eye->x * cos((3.1415 * r) / 180.0))
    + (eye->y * (-sin((3.1415 * r) / 180.0)));
  coords.y = (eye->x * sin((3.1415 * r) / 180.0))
    + (eye->y * cos((3.1415 * r) / 180.0));
  coords.z = eye->z;
  eye->x = coords.x;
  eye->y = coords.y;
  eye->z = coords.z;
}

void		trans_rot(t_eye *e, t_obj *o)
{
  e->pos.pt.x = e->pos.pt.x - o->pt.x;
  e->pos.pt.y = e->pos.pt.y - o->pt.y;
  e->pos.pt.z = e->pos.pt.z - o->pt.z;
  rotate_x(&e->pos.vec, -(o->rot.x));
  rotate_y(&e->pos.vec, -(o->rot.y));
  rotate_z(&e->pos.vec, -(o->rot.z));
  rotate_x(&e->pos.pt, -(o->rot.x));
  rotate_y(&e->pos.pt, -(o->rot.y));
  rotate_z(&e->pos.pt, -(o->rot.z));
}
