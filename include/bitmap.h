#ifndef BITMAP_H_
# define BITMAP_H_

typedef struct __attribute__((__packed__))	s_header
{
  short						magic;
  int						folder_size;
  int						reserved;
  int						offset;
}						t_header;

typedef struct __attribute__((__packed__))	s_image
{
  int						size_head;
  int						image_width;
  int						image_height;
  short						plans;
  short						deep_color;
  int						comp_met;
  int						size_image;
  int						res_x;
  int						res_y;
  int						nb_color;
  int						color_imp;
}						t_image;

#endif
