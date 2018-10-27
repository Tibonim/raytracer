#include "rtracer.h"

void		init_img(t_content *c)
{
  t_eye		*it;

  it = c->e->nx;
  while (it != c->e)
    {
      it->img.scene = mlx_new_image(c->p.mlx_ptr, WIN_X, WIN_Y);
      it->loading.scene = mlx_new_image(c->p.mlx_ptr, WIN_X, WIN_Y);
      it->img.data = mlx_get_data_addr(it->img.scene,
				       &c->p.bpp, &c->p.sizeline,
				       &c->p.endian);
      it->loading.data = mlx_get_data_addr(it->loading.scene,
					   &c->p.bpp, &c->p.sizeline,
					   &c->p.endian);
      it = it->nx;
    }
}

void		init_scene(t_content *c, char *file)
{
  t_eye		*it;

  c->eyes_num = 0;
  c->eye_select = 1;
  c->e = e_create(c->e);
  c->o = o_create(c->o);
  c->l = l_create(c->l);
  main_parse(c, file);
  init_fptr(c);
  it = c->e->nx;
  while (it != c->e)
    {
      c->eyes_num++;
      it = it->nx;
    }
  init_img(c);
}
