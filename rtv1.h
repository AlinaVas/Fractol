/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:12:49 by afesyk            #+#    #+#             */
/*   Updated: 2018/04/26 18:12:51 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include <mlx.h>
# include "libft/libft.h"

# define WIN_X 1200
# define WIN_Y 800
# define BACKGROUND_COLOR 0
# define TMAX 9999999

typedef enum		e_keys
{
	one = 83,
	two = 84,
	three = 85,
	four = 86,
	six = 88,
	eight = 91,
	esc = 53,
	arr_left = 123,
	arr_right = 124,
	arr_up = 126,
	arr_down = 125,
}					t_keys;

typedef enum		e_mouse
{
	scrollup = 4,
	scrolldown = 5
}					t_mouse;

typedef enum		e_otype
{
	plane = 0,
	sphere = 1,
	cylinder = 2,
	cone = 3,
}					t_otype;

typedef enum		e_ltype
{
	ambient = 5,
	point = 6,
	directional = 7
}					t_ltype;

typedef	double		(t_func1)(void *, t_xyz, t_xyz);

typedef	t_xyz		(t_func2)(void *);

typedef struct		s_obj
{
	t_xyz			center;
	double			radius;
	double			angle;
	int				color;
	double			specular;
	t_xyz			axis;
	t_xyz			normal;
	t_func1			*find_intersection;
	t_func2			*find_normal;
	int				error;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_light
{
	int				type;
	double			intensity;
	t_xyz			pos;
	t_xyz			dir;
	int				error;
	struct s_light	*next;
}					t_light;

typedef struct		s_closest
{
	double			scalar;
	t_obj			*obj;
	t_xyz			point;
}					t_closest;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				size_line;
	int				bits_per_pixel;
	int				endian;
	t_xyz			cam;
	t_xyz			camdir;
	double			d;
	double			viewport_x;
	double			viewport_y;
	t_obj			*scene;
	t_light			*light;
	t_xyz			rd;
	t_closest		intersect;
}					t_mlx;

int					just_exit(t_mlx *p);
void				error_exit(int n, t_mlx *p);
void				free_everything(t_mlx *p);
void				redraw_image(t_mlx *p);
void				validate_scene(t_obj *obj, t_light *l, t_mlx *p);
t_obj				*create_obj
					(int type, t_xyz center, int color, double specular);
t_light				*create_light(int type, double intensity, t_xyz vec);
t_xyz				vecscale(t_xyz a, double n);
t_xyz				vecadd(t_xyz a, t_xyz b);
t_xyz				vecsub(t_xyz a, t_xyz b);
t_xyz				vecnorm(t_xyz a);
double				veclen(t_xyz v);
t_xyz				ray_direction(double x, double y, t_mlx *p);
double				trace_viewing_ray(t_mlx *p);
double				trace_shadow_ray(t_light *l, t_mlx *p);
double				sphere_intersection
					(void *obj_params, t_xyz starting_point, t_xyz rd);
double				plane_intersection
					(void *obj_params, t_xyz starting_point, t_xyz rd);
double				cylinder_intersection
					(void *obj, t_xyz starting_point, t_xyz rd);
double				cone_intersection
					(void *obj_params, t_xyz starting_point, t_xyz rd);
t_xyz				sphere_normal(void *p_mlx);
t_xyz				plane_normal(void *p_mlx);
t_xyz				cylinder_normal(void *p_mlx);
t_xyz				cone_normal(void *p_mlx);
void				get_scene1(t_mlx *p);
void				get_scene2(t_mlx *p);
void				get_scene3(t_mlx *p);
void				get_scene4(t_mlx *p);
double				specular_reflection(t_mlx *p, t_light *l, t_xyz normal);
double				light_intensity(t_mlx *p, t_light *l, t_xyz normal);
int					apply_to_rgb(double li, int color);
int					compute_lighting(t_mlx *p);
int					deal_key(int key, t_mlx *p);
int					mouse_zoom(int button, int x, int y, t_mlx *p);
t_mlx				*create_struct(char *av);
void				render_img(t_mlx *p);
void				redraw_image(t_mlx *p);

#endif
