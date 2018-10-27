#ifndef RTRACER_H_
# define RTRACER_H_

# define WIN_X 1080
# define WIN_Y 720
# define EYE_VEC_LEN 4000
# define DEF_EYE_POS -1200
# define PLAN 0
# define SPHERE 1
# define CYLINDER 2
# define CONE 3
# define HYPERBOOL 4
# define PARABOOL 5
# define NUMBER_OBJECTS 6
# define N_REFRAC 1

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <X11/Xlib.h>
#include <mlx.h>
#include "get_next_line.h"

typedef struct		s_coords
{
  float			x;
  float			y;
  float			z;
}			t_coords;

typedef struct		s_obj
{
  int			type;
  int			id;
  t_coords		pt;
  t_coords		rot;
  unsigned int		color;
  float			reflect;
  float			opacity;
  float			shine;
  float			ray;
  float			ray_in;
  int			wave;
  int			chess;
  float			ang;
  struct s_obj		*nx;
  struct s_obj		*pv;
}			t_obj;

typedef struct		s_light
{
  t_coords		pt;
  unsigned int		color;
  int			id;
  struct s_light	*nx;
  struct s_light	*pv;
}			t_light;

typedef struct		s_inter
{
  t_coords		norm;
  t_coords		pt;
  float			k;
  float			shine;
  int			id;
  unsigned int		color;
}			t_inter;

typedef struct		s_eye_pos
{
  t_coords		pt;
  t_coords		vec;
  t_coords		rot;
}			t_eye_pos;

typedef struct		s_img
{
  void			*scene;
  char			*data;
  int			i;
  t_coords		pos;
}			t_img;

typedef struct		s_eye
{
  int			lock;
  t_eye_pos		pos;
  t_eye_pos		def;
  t_img			img;
  t_img			loading;
  int			aliasing;
  int			fast;
  int			id;
  unsigned int		final_color;
  t_inter		inter;
  struct s_eye		*nx;
  struct s_eye		*pv;
}			t_eye;

typedef struct		s_param
{
  void			*mlx_ptr;
  void			*win_ptr;
  int			bpp;
  int			sizeline;
  int			endian;
  int			fd;
}			t_param;

typedef struct		s_content
{
  t_param		p;
  t_obj			*o;
  t_eye			*e;
  t_light		*l;
  int			eye_select;
  char			*file;
  int			eyes_num;
  void			(*intersec_list[NUMBER_OBJECTS])
  (t_eye *e, t_obj *o, int id_ignore);
}			t_content;

void			inter_parab(t_eye *e, t_obj *obj, int id);
void			inter_hyperbool(t_eye *e, t_obj *obj, int id);
int			fill_inter(t_eye *e, t_obj *obj, float k);
int			normalizing(t_coords *pt);
unsigned int		transparency(t_content *c, t_eye *e);
unsigned int		reflect(t_content *c, t_eye *e);
int			my_get_nbr(char *str, int i);
int			my_strcmp(char *str, char *find);
int			my_atoi_base(char *str, char *base);
t_eye			*e_create(t_eye *root);
t_obj			*o_create(t_obj *root);
int			get_is_shadow(int);
void			e_add_before(t_eye *element);
void			o_add_before(t_obj *element);
void			l_add_before(t_light *element);
void			rotate_x(t_coords *eye, int r);
void			rotate_y(t_coords *eye, int r);
void			rotate_z(t_coords *eye, int r);
int			default_eye(t_eye *e);
int			intersec(t_content *c, t_eye *eye, int id_ignore);
void			inter_plan(t_eye *e, t_obj *obj, int id_ignore);
void			inter_sphere(t_eye *e, t_obj *obj, int id_ignore);
void			inter_cyl(t_eye *e, t_obj *obj, int id_ignore);
void			inter_cone(t_eye *e, t_obj *obj, int id_ignore);
void			inter_cube(t_eye *e, t_obj *obj, int id_ignore);
int			gere_key(int keycode, void *params);
int			gere_expose(void *params);
void			get_inter_inf(t_eye *e, t_obj *o);
void			my_pixel_put_to_image(int i, unsigned int color, char *data);
void			first_eye(t_eye *e);
t_light			*l_create(t_light *root);
t_obj			*o_create(t_obj *root);
t_eye			*e_create(t_eye *root);
int			main_parse(struct s_content *parser, char *file);
void			init_fptr(t_content *c);
void			trans_rot(t_eye *e, t_obj *o);
void			set_point(t_coords *xyz);
void			sys_failed(char *fun, int op);
void			set_pos(t_eye_pos *p);
void			view_selected_eye(t_content *c);
void			error_msg(char *str);
int			get_current_ld(t_eye *e);
int			get_total_ld(t_content *c);
int			put_loads(int cur, int total, t_eye *e, t_content *c);
void			init_reflect(t_eye *eye, t_coords *ray);
unsigned int		get_new_ref(unsigned int col, unsigned int col2, float ref);
unsigned int		get_color(t_content *c, t_eye *eye, int i);
void			win_define(t_content *c);
void			init_scene(t_content *c, char *file);
void			usage();
int			my_strlen(char *str);
void			my_fputstr(char *str);
void			error_main_token(char *token);
int			shadow(t_eye *e, t_content *c);
unsigned int		light(t_eye *e, t_light *root);
unsigned int		createRGB(int r, int g, int b);
unsigned int		go_dark(unsigned int col);
void			do_waves_plane(t_eye *e);
void			do_chess_plane(t_eye *e);
void			my_bmp(struct s_content *c);
void			my_putstr(char *str);

#endif /* !RTRACER_H */
