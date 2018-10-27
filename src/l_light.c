#include "rtracer.h"

t_light		*l_create(t_light *root)
{
  if ((root = malloc(sizeof *root)) == NULL)
    sys_failed("Malloc", 1);
  if (root != NULL)
    {
      set_point(&root->pt);
      root->id = 0;
      root->color = 0xFFFFFF;
      root->pv = root;
      root->nx = root;
    }
  return (root);
}

void		l_add_before(t_light *element)
{
  t_light	*new;

  if ((new = malloc(sizeof *new)) == NULL)
    sys_failed("Malloc", 1);
  if (new != NULL)
    {
      set_point(&new->pt);
      new->color = 0xFFFFFF;
      new->pv = element->pv;
      new->nx = element;
      element->pv->nx = new;
      element->pv = new;
      new->id = new->pv->id + 1;
    }
}
