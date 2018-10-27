#include "rtracer.h"

void		inter_hyperbool(t_eye *e, t_obj *obj, int id)
{
  float         d;
  float         a;
  float         b;
  float         c;
  float		k;

  if (id == obj->id && id != -1)
    return ;
  a = pow(e->pos.vec.x, 2) + pow(e->pos.vec.y, 2) -
    (pow(e->pos.vec.z, 2) / pow(tanf(3.1415 * obj->ang / 180.f), 2));
  b = 2 * ((e->pos.pt.x * e->pos.vec.x) + (e->pos.pt.y * e->pos.vec.y) -
	   ((e->pos.pt.z * e->pos.vec.z) /
	    pow(tanf(3.1415 * obj->ang / 180), 2)));
  if (tanf(3.1415 * obj->ang / 180.f) == 0 || !a)
    return ;
  c = pow(e->pos.pt.x, 2) + pow(e->pos.pt.y, 2) -
    (pow(e->pos.pt.z, 2) / pow(tanf(3.1415 * obj->ang / 180.f), 2)) - 3000;
  d = (b * b) - (4.f * a * c);
  if (d < 0.0000001)
    return ;
  k = (-b - sqrt(d)) / (2.f * a);
  if (k > ((-b + sqrt(d)) / (2.f * a)))
    k = (-b + sqrt(d)) / (2.f * a);
  if (k > 0.0000001 && (k <= e->inter.k || e->inter.k < 0.0000001))
    fill_inter(e, obj, k);
}

void		inter_parab(t_eye *e, t_obj *obj, int id)
{
  float         d;
  float         a;
  float         b;
  float         c;
  float		k;

  if (id == obj->id && id != -1)
    return ;
  a = pow(e->pos.vec.x, 2) + pow(e->pos.vec.y, 2) -
    (pow(e->pos.vec.z, 2) / pow(tanf(3.1415 * obj->ang / 180.f), 2));
  b = 2 * ((e->pos.pt.x * e->pos.vec.x) + (e->pos.pt.y * e->pos.vec.y) -
	   ((e->pos.pt.z * e->pos.vec.z) /
	    pow(tanf(3.1415 * obj->ang / 180), 2)));
  if (tanf(3.1415 * obj->ang / 180.f) == 0 || !a)
    return ;
  c = pow(e->pos.pt.x, 2) + pow(e->pos.pt.y, 2) -
    (pow(e->pos.pt.z, 2) / pow(tanf(3.1415 * obj->ang / 180.f), 2)) + 3000;
  d = (b * b) - (4.f * a * c);
  if (d < 0.0000001)
    return ;
  k = (-b - sqrt(d)) / (2.f * a);
  if (k > ((-b + sqrt(d)) / (2.f * a)))
    k = (-b + sqrt(d)) / (2.f * a);
  if (k > 0.0000001 && (k <= e->inter.k || e->inter.k < 0.0000001))
    fill_inter(e, obj, k);
}
