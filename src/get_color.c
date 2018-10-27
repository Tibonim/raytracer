#include "rtracer.h"

unsigned int	get_one_px(t_content *c, t_eye *eye, int i)
{
  eye->img.pos.y = i / WIN_X;
  eye->img.pos.x = i - (eye->img.pos.y * WIN_X);
  eye->inter.k = -1.0;
  first_eye(eye);
  eye->final_color = 0x000000;
  eye->inter.color = 0x000000;
  if (intersec(c, eye, -1) == 0)
    {
      eye->final_color = eye->inter.color;
      eye->final_color = light(eye, c->l);
      eye->final_color = shadow(eye, c);
      eye->final_color = reflect(c, eye);
      eye->final_color = transparency(c, eye);
    }
  return (eye->final_color);
}

unsigned int	get_color(t_content *c, t_eye *eye, int i)
{
  unsigned int  col1;
  unsigned int  col2;
  unsigned int  col3;
  unsigned int  col4;
  unsigned int  col5;

  col1 = get_one_px(c, eye, i);
  if (eye->aliasing == 1)
    {
      col2 = get_one_px(c, eye, i - WIN_X - 1);
      col3 = get_one_px(c, eye, i - WIN_X + 1);
      col4 = get_one_px(c, eye, i + WIN_X - 1);
      col5 = get_one_px(c, eye, i + WIN_X + 1);
      col1 = createRGB((((col1 >> 16) & 0xFF) + ((col2 >> 16) & 0xFF) +
			((col3 >> 16) & 0xFF) + ((col4 >> 16) & 0xFF) +
			((col5 >> 16) & 0xFF)) / 5,
		       (((col1 >> 8) & 0xFF) + ((col2 >> 8) & 0xFF) +
			((col3 >> 8) & 0xFF) + ((col4 >> 8) & 0xFF) +
			((col5 >> 8) & 0xFF)) / 5,
		       (((col1) & 0xFF) + ((col2) & 0xFF) +
			((col3) & 0xFF) + ((col4) & 0xFF) +
			((col5) & 0xFF)) / 5);
    }
  return (col1);
}
