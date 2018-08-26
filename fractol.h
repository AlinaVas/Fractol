/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:35:28 by afesyk            #+#    #+#             */
/*   Updated: 2018/04/01 18:35:30 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include "libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define DWIDTH 1200
# define THREAD_NUM 8
# define ZOOM_IN 0.95
# define ZOOM_OUT 1.05
# define STEP 12
# define MAX_ITER 250
# define MIN_ITER 40

typedef int		(*t_functions)(int, int, void *);

typedef enum	e_keys
{
	esc = 53,
	plus_r = 69,
	plus_l = 24,
	minus_r = 78,
	minus_l = 27,
	arr_left = 123,
	arr_right = 124,
	arr_up = 126,
	arr_down = 125,
	space = 49
}				t_keys;

typedef enum	e_mouse
{
	scroll_up = 4,
	scroll_down = 5,
	scroll_left = 6,
	scroll_right = 7,
	press_left = 1,
	press_right = 2

}				t_mouse;

typedef struct	s_pack
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			size_line;
	int			bits_per_pixel;
	int			endian;
	double		zoom;
	double		x_shift;
	double		y_shift;
	double		xmouse_adj;
	double		ymouse_adj;
	double		shift_by;
	double		max_iter;
	double		c_real;
	double		c_imaginary;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		re_factor;
	double		im_factor;
	int			fractol_type;
	int			modify_julia;
	double		x_center;
	double		y_center;
	double		dx;
	double		dy;
	char		*display_iter;
	t_functions	func[8];
}				t_pack;

typedef struct	s_args
{
	t_pack		*p;
	int			start;
	int			end;
	double		c_re;
	double		c_im;
	double		old_re;
	double		old_im;
	double		new_re;
	double		new_im;
}				t_args;

void			redraw_image(t_pack *p);
void			error_exit(int n);
int				deal_key(int key, t_pack *p);
int				julia(int x, int y, void *as);
int				burning_ship(int x, int y, void *argset);
int				mandelbrot(int x, int y, void *argset);
int				mandelbrot_4th(int x, int y, void *argset);
int				celtic_mandelbrot(int x, int y, void *argset);
int				heart_mandelbrot(int x, int y, void *argset);
int				tricorn(int x, int y, void *argset);
int				buffalo(int x, int y, void *argset);
int				just_exit(t_pack *p);
int				mouse_motion_julia(int x, int y, t_pack *p);
int				mouse_buttons(int button, int x, int y, t_pack *p);
void			make_threads(t_pack *p);
void			put_description(t_pack *p);
t_pack			*create_pack(char *argv);
void			define_fractol(t_pack *p, char *argv);
void			fill_pack(t_pack *p);

#endif
