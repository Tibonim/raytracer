#include "rtracer.h"

void		do_waves_plane(t_eye *e)
{
  e->inter.norm.z = 0.0;
  e->inter.norm.y = e->inter.norm.y + (cos((e->inter.pt.y) / 10.0) +
     ((sqrt(e->inter.norm.x * e->inter.norm.x + e->inter.norm.y *
	    e->inter.norm.y + e->inter.norm.z * e->inter.norm.z)) / 10.0));
  e->inter.norm.z = 100.0;
}

void		do_chess_plane(t_eye *e)
{
  if ((abs((int)e->inter.pt.x % 100) >= 50) && \
      (abs((int)e->inter.pt.y % 100) >= 50))
    e->inter.color = 0x000000;
  else if ((abs((int)e->inter.pt.x % 100) <= 50) && \
	   (abs((int)e->inter.pt.y % 100) <= 50))
    e->inter.color = 0xFFFFFF;
}
