/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:51:41 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/14 11:06:00 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>

# define A 0
# define B 11
# define C 8
# define D 2
# define E 14
# define F 3
# define G 5
# define H 4
# define I 34
# define J 38
# define K 40
# define L 37
# define M 46
# define N 45
# define O 31
# define P 35
# define Q 12
# define R 15
# define S 1
# define T 17
# define U 32
# define V 9
# define W 13
# define X 7
# define Y 16
# define Z 6
# define ESC 53
# define TAB 48
# define RETURN 36
# define L_SHIFT 257
# define R_SHIFT 258
# define SPACE 49
# define ARROW_UP 126
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define MOUSE_UP 5
# define MOUSE_DOWN 4
# define PAGE_UP 116
# define PAGE_DOWN 121
# define PLUS 69
# define MINUS 78
# define CLR 71

# define WIN_S 1000
# define THREAD_NUMBER 20

# define BROWN 0x825C26
# define DARK_RED 0x820E0E
# define RED 0xFF3700
# define ORANGE 0xFF8C00
# define YELLOW 0xFFD52A
# define LIGHT_YELLOW 0xFFFF00
# define WHITE 0xFFFFFF
# define PURPLE_ASSEMBLY 0x9359AF

# define RE 0
# define IM 1

typedef struct		s_color
{
	int				phase;
	int				width;
	int				center;
	double			freq;
}					t_color;

typedef struct		s_args
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*image;
	char			*pics;
	int				it;
	int				fractal;
	int				theme;
	int				s_line;
	int				bpp;
	int				endian;
	int				line_x;
	int				line_y;
	int				mouse_move;
	int				mouse_move_x;
	int				mouse_move_stop;
	double			mx;
	double			my;
	double			z;
	double			zoom;
	double			tmp_c[2];
}					t_args;

typedef struct		s_data
{
	t_args			*args;
	int				x;
	int				n;
	int				y_min;
	int				y_max;
	int				it;
	int				fractal;
	int				theme;
	double			mx;
	double			my;
	double			z;
	double			zoom;
	double			b[2];
	double			c[2];
	double			tmp_c[2];
}					t_data;

int					expose_handler(t_args *args);
int					fractol_key_handler(int key, t_args *args);
int					fractol_mouse_handler(int button,
		int x, int y, t_args *args);
void				fractol_define_window(t_args *data);
int					fractol_close(void *param);
void				fractol_choose_fractal(t_data *data);
void				fractol_pxl_to_img(t_data *data, int i, int j, int color);
void				fractol_newton_handler(t_args *args);
void				fractol_mandelbrot_handler(t_args *args);
void				fractol_julia_handler(t_args *args);
void				fractol_ship_handler(t_args *args);
void				init_fractal(t_args *args);
void				init_calculation(t_args *args);
void				fractol_clear_image(t_data *data);
void				init_args(t_args *args);
void				fractol_drawing(t_data *data, t_args *args);
int					mouse_movement(int x, int y, t_args *args);
void				fractol_type_writer(t_args *args);

#endif
