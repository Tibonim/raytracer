#include "rtracer.h"

int             normalizing(t_coords *pt)
{
  float         norm;

  norm = sqrt((pt->x * pt->x) + (pt->y * pt->y) + (pt->z * pt->z));
  pt->x /= norm;
  pt->y /= norm;
  pt->z /= norm;
  return (0);
}
