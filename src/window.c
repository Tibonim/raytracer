#include "rtracer.h"

int		gere_expose(void *params)
{
  t_content	*c;

  c = params;
  view_selected_eye(c);
  return (0);
}

int		gere_key(int keycode, void *params)
{
  t_content	*c;

  c = params;
  if (keycode == 115)
    {
      my_bmp(c);
      return (keycode);
    }
  else if (keycode == 65307)
    {
      mlx_destroy_window(c->p.mlx_ptr, c->p.win_ptr);
      exit(1);
    }
  else if (keycode == 65363)
    c->eye_select = (((c->eye_select + 1) % c->eyes_num) == 0) ?
      c->eyes_num : ((c->eye_select + 1) % c->eyes_num);
  else if (keycode == 65361)
    c->eye_select = (((c->eye_select - 1) % c->eyes_num) == 0) ?
      c->eyes_num : ((c->eye_select - 1) % c->eyes_num);
  view_selected_eye(c);
  return (keycode);
}

void		win_define(t_content *c)
{
  c->p.mlx_ptr = mlx_init();
  if (c->p.mlx_ptr == NULL)
    {
      write(2, "Missing graphical environnement.\n", 33);
      exit(-1);
    }
  c->p.win_ptr = mlx_new_window(c->p.mlx_ptr, WIN_X, WIN_Y, "Badass RT");
}
