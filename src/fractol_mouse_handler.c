/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:32:34 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/14 11:32:26 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			fractol_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int			mouse_movement(int x, int y, t_args *args)
{
	double	ret;

	(void)x;
	(void)y;
	ret = 0.001;
	if (args->fractal == 2 && args->mouse_move_stop)
	{
		args->tmp_c[RE] += (args->mouse_move ? ret * args->mouse_move_x
				: -ret * args->mouse_move_x);
		args->tmp_c[IM] += (args->mouse_move ? ret * args->mouse_move_x
				: -ret * args->mouse_move_x);
		mlx_destroy_image(args->mlx_ptr, args->image);
		expose_handler(args);
	}
	return (0);
}

static void	zoom_handler(int button, int x, int y, t_args *args)
{
	double		retx;
	double		rety;
	static int	i = 0;
	static int	j = 0;

	retx = ((double)(ft_absolute(500 - x)) / 500) / (0.01 / args->zoom);
	rety = ((double)(ft_absolute(500 - y)) / 500) / (0.01 / args->zoom);
	if (button == MOUSE_DOWN)
	{
		args->mx += (x > 500 ? retx : -retx);
		args->my += (y > 500 ? rety : -rety);
		args->zoom *= 0.9;
		if (++i == 10 && ++args->it)
			i = 0;
	}
	else if (button == MOUSE_UP)
	{
		args->zoom *= 1.1;
		if (++j == 10 && --args->it)
			j = 0;
	}
}

static void	fractal_handler(int x, int y, t_args *args)
{
	if (x > 1165 && x < 1220 && y > 260 && y < 290 && args->fractal != 1)
	{
		init_args(args);
		args->fractal = 1;
	}
	if (x > 1180 && x < 1220 && y > 300 && y < 330 && args->fractal != 2)
	{
		init_args(args);
		args->fractal = 2;
	}
	if (x > 1175 && x < 1220 && y > 340 && y < 370 && args->fractal != 3)
	{
		init_args(args);
		args->fractal = 3;
	}
	if (x > 1145 && x < 1200 && y > 380 && y < 410 && args->fractal != 4)
	{
		init_args(args);
		args->fractal = 4;
	}
}

int			fractol_mouse_handler(int button, int x, int y, t_args *args)
{
	fractal_handler(x, y, args);
	if (args->fractal)
	{
		zoom_handler(button, x, y, args);
		if (args->image)
			mlx_destroy_image(args->mlx_ptr, args->image);
		expose_handler(args);
	}
	return (0);
}
