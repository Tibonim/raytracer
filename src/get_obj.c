#include "rtracer.h"

t_obj		*get_obj_by_id(int id, t_obj *root)
{
  t_obj		*it;

  it = root->nx;
  while (it != root)
    {
      if (it->id == id)
	return (it);
      it = it->nx;
    }
  return (it);
}
