#include "rtracer.h"

void		my_pixel_put_to_image(int i, unsigned int color, char *data)
{
  ((unsigned int *)data)[i] = color;
}

void		view_selected_eye(t_content *c)
{
  t_eye		*it;
  int		current;
  int		total;

  total = 0;
  current = 0;
  it = c->e->nx;
  while (it->id != c->eye_select)
    {
      if (it == c->e)
	error_msg("Error : No eye founded...\n");
      it = it->nx;
    }
  while (total != 100)
    {
      current = get_current_ld(it);
      total = get_total_ld(c);
      if (put_loads(current, total, it, c) == 1)
  	mlx_put_image_to_window(c->p.mlx_ptr,
				c->p.win_ptr, it->img.scene, 0, 0);
      else
  	mlx_put_image_to_window(c->p.mlx_ptr, c->p.win_ptr,
				it->loading.scene, 0, 0);
    }
  mlx_put_image_to_window(c->p.mlx_ptr, c->p.win_ptr, it->img.scene, 0, 0);
}

void		*view_thread(void *threadarg)
{
  t_content	*c;
  t_eye		*it;

  c = (t_content *)threadarg;
  it = c->e->nx;
  while (it != c->e)
    {
      if (it->lock == 0)
	{
	  it->lock = 1;
	  while (it->img.i <= (WIN_X * WIN_Y))
	    {
	      my_pixel_put_to_image(it->img.i, get_color(c, it, it->img.i),
				    it->img.data);
	      it->img.i = (it->fast == 1) ? (it->img.i + 2) : (it->img.i + 1);
	    }
	  return (NULL);
	}
      it = it->nx;
    }
  return (NULL);
}

void		view(t_content *c)
{
  t_eye		*it;
  pthread_t	tid[c->eyes_num];
  int		i;

  i = 0;
  it = c->e->nx;
  while (it != c->e)
    {
      pthread_create(&tid[i], NULL, view_thread, (void *)c);
      it = it->nx;
    }
  view_selected_eye(c);
}

int		main(int ac, char **av)
{
  t_content	c;

  if (ac >= 2)
    {
      if ((c.p.fd = open(av[1], O_RDONLY)) == -1)
      	sys_failed("Open", 1);
      win_define(&c);
      init_scene(&c, av[1]);
      if (close(c.p.fd) == -1)
      	sys_failed("Close", 1);
      view(&c);
      mlx_hook(c.p.win_ptr, KeyPress, KeyPressMask, &gere_key, &c);
      mlx_expose_hook(c.p.win_ptr, &gere_expose, &c);
      mlx_loop(c.p.mlx_ptr);
    }
  else
    usage();
  return (0);
}
