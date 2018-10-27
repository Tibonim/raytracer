#include "rtracer.h"

void		set_pos(t_eye_pos *p)
{
  set_point(&p->pt);
  set_point(&p->rot);
  set_point(&p->vec);
}

void		set_img(t_img *i)
{
  i->scene = NULL;
  i->data = NULL;
  i->i = 0;
  set_point(&i->pos);
}

t_eye           *e_create(t_eye *root)
{
  if ((root = malloc(sizeof *root)) == NULL)
    sys_failed("Malloc", 1);
  if (root != NULL)
    {
      root->lock = -1;
      set_pos(&root->pos);
      set_pos(&root->def);
      root->id = 0;
      set_img(&root->img);
      set_img(&root->loading);
      root->id = 0;
      root->fast = 0;
      root->aliasing = 1;
      root->final_color = 0x000000;
      root->pv = root;
      root->nx = root;
      set_point(&root->inter.norm);
      set_point(&root->inter.pt);
      root->inter.k = 0;
      root->inter.id = 0;
      root->inter.color = 0x000000;
    }
  return (root);
}

void            e_add_before(t_eye *element)
{
  t_eye         *new;

  if ((new = malloc(sizeof *new)) == NULL)
    sys_failed("Malloc", 1);
  new->lock = 0;
  set_pos(&new->pos);
  set_pos(&new->def);
  set_img(&new->img);
  set_img(&new->loading);
  new->aliasing = 1;
  new->fast = 0;
  new->final_color = 0x000000;
  new->pv = new;
  new->nx = new;
  set_point(&new->inter.norm);
  set_point(&new->inter.pt);
  new->inter.k = 0;
  new->inter.id = 0;
  new->inter.color = 0x000000;
  new->pv = element->pv;
  new->nx = element;
  element->pv->nx = new;
  element->pv = new;
  new->id = new->pv->id + 1;
}
