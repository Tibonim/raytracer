#include "rtracer.h"

void		init_fptr(t_content *c)
{
  c->intersec_list[PLAN] = inter_plan;
  c->intersec_list[SPHERE] = inter_sphere;
  c->intersec_list[CYLINDER] = inter_cyl;
  c->intersec_list[CONE] = inter_cone;
  c->intersec_list[HYPERBOOL] = inter_hyperbool;
  c->intersec_list[PARABOOL] = inter_parab;
  c->intersec_list[NUMBER_OBJECTS] = NULL;
}

int		intersec(t_content *c, t_eye *eye, int id_ignore)
{
  t_obj         *it;
  unsigned int	start_color;

  it = c->o->nx;
  start_color = eye->inter.color;
  while (it != c->o)
    {
      default_eye(eye);
      trans_rot(eye, it);
      c->intersec_list[it->type](eye, it, id_ignore);
      it = it->nx;
    }
  if (eye->inter.color == start_color)
    return (1);
  else
    return (0);
}
