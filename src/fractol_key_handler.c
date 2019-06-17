/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:32:54 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/14 11:30:56 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	move_handler(int key, t_args *args)
{
	if (key == ARROW_LEFT)
		args->mx -= 0.1 * args->zoom * 100;
	else if (key == ARROW_RIGHT)
		args->mx += 0.1 * args->zoom * 100;
	else if (key == ARROW_DOWN)
		args->my += 0.1 * args->zoom * 100;
	else if (key == ARROW_UP)
		args->my -= 0.1 * args->zoom * 100;
}

static void	it_handler(int key, t_args *args)
{
	if (key == MINUS)
		args->it -= 1;
	else if (key == PLUS)
		args->it += 1;
}

static void	julia_mouse_x_handler(int key, t_args *args)
{
	if (args->fractal == 2)
	{
		if (key == PAGE_UP && args->mouse_move_x < 30)
			args->mouse_move_x++;
		if (key == PAGE_DOWN && args->mouse_move_x > 1)
			args->mouse_move_x--;
	}
}

static void	color_handler(int key, t_args *args)
{
	if (key == 18 || key == 83)
		args->theme = 1;
	if (key == 19 || key == 84)
		args->theme = 2;
	if (key == 20 || key == 85)
		args->theme = 3;
}

int			fractol_key_handler(int key, t_args *args)
{
	if (key == ESC)
	{
		free(args);
		exit(0);
	}
	if (args->fractal)
	{
		if (key == CLR)
			init_args(args);
		if (key == SPACE)
			args->mouse_move = (args->mouse_move ? 0 : 1);
		if (key == TAB)
			args->mouse_move_stop = (args->mouse_move_stop ? 0 : 1);
		move_handler(key, args);
		it_handler(key, args);
		color_handler(key, args);
		julia_mouse_x_handler(key, args);
		mlx_destroy_image(args->mlx_ptr, args->image);
		expose_handler(args);
	}
	return (0);
}
