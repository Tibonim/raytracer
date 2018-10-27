#include "rtracer.h"

void		set_point(t_coords *xyz)
{
  xyz->x = 0;
  xyz->y = 0;
  xyz->z = 0;
}

t_obj           *o_create(t_obj *root)
{
  if ((root = malloc(sizeof *root)) == NULL)
    sys_failed("Malloc", 1);
  if (root != NULL)
    {
      root->type = -1;
      root->id = 0;
      set_point(&root->pt);
      set_point(&root->rot);
      root->color = 0x000000;
      root->opacity = 1;
      root->chess = 0;
      root->wave = 0;
      root->shine = 0;
      root->ray = 200;
      root->ray_in = 100;
      root->ang = 20;
      root->reflect = 0;
      root->pv = root;
      root->nx = root;
    }
  return (root);
}

void            o_add_before(t_obj *element)
{
  t_obj         *new;

  if ((new = malloc(sizeof *new)) == NULL)
    sys_failed("Malloc", 1);
  if (new != NULL)
    {
      new->type = -1;
      set_point(&new->pt);
      set_point(&new->rot);
      new->color = 0x000000;
      new->opacity = 1;
      new->shine = 0;
      new->ray = 200;
      new->wave = 0;
      new->chess = 0;
      new->reflect = 0;
      new->ang = 20;
      new->ray_in = 100;
      new->pv = element->pv;
      new->nx = element;
      element->pv->nx = new;
      element->pv = new;
      new->id = new->pv->id + 1;
    }
}
