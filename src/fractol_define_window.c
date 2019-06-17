/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_define_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:19:45 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/14 11:30:42 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	trace_line(t_args *args, int x, int y)
{
	if (args->line_x == 0)
	{
		while (x != y)
		{
			mlx_pixel_put(args->mlx_ptr, args->win_ptr, x, args->line_y, WHITE);
			x += (x < y ? 1 : -1);
		}
	}
	else
	{
		while (x != y)
		{
			mlx_pixel_put(args->mlx_ptr, args->win_ptr, args->line_x, x, WHITE);
			x += (x < y ? 1 : -1);
		}
	}
}

static void	trace_lines(t_args *args)
{
	args->line_x = WIN_S + 496;
	while (++args->line_x < WIN_S + 501)
		trace_line(args, 0, WIN_S);
	args->line_x = WIN_S - 1;
	while (++args->line_x < WIN_S + 3)
		trace_line(args, 0, WIN_S);
	args->line_x = 0;
	args->line_y = 3;
	while (--args->line_y >= 0)
		trace_line(args, WIN_S + 1, WIN_S + 500);
	args->line_y = 50;
	while (++args->line_y < 54)
		trace_line(args, WIN_S + 1, WIN_S + 500);
	args->line_y = 146;
	while (++args->line_y < 151)
		trace_line(args, WIN_S + 1, WIN_S + 500);
	args->line_y = 596;
	while (++args->line_y < 601)
		trace_line(args, WIN_S + 1, WIN_S + 500);
	args->line_y = 996;
	while (++args->line_y < 1001)
		trace_line(args, WIN_S + 1, WIN_S + 500);
}

static void	write_other_stuff(t_args *args)
{
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S - 250, 300,
			WHITE, "Time to choose -->");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 140, 800,
			WHITE, "------------------");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 175, 825,
			WHITE, "For Julia :");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 60, 850,
			WHITE, "Mouse movement -> change the parameter");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 10, 875,
			WHITE, "PAGE UP/DOWN -> accelerate/decelerate the change");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 100, 900,
			WHITE, "SPACE -> reverse the change");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 110, 925,
			WHITE, "TAB -> stop the change");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 160, 16,
			WHITE, "Fract'ol project");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 100, 775,
			WHITE, "Clear -> reset the fractal");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 60, 675,
			WHITE, "1 / 2 / 3 -> Change the color");
}

static void	write_stuff(t_args *args)
{
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 169, 60,
			WHITE, "Type of fractal :");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 139, 160,
			WHITE, "Choose your fractal :");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 165, 260,
			WHITE, "(1) Mandelbrot");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 180, 300,
			WHITE, "(2) Julia");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 175, 340,
			WHITE, "(3) Newton");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 145, 380,
			WHITE, "(4) Burning ship");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 165, 610,
			WHITE, "Instructions : ");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 60, 650,
			WHITE, "ESC / Red cross -> quit the program");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 100, 700,
			WHITE, "Arrows -> move the drawing");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 110, 725,
			WHITE, "Scroll -> zoom / dezoom");
	mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 50, 750,
			WHITE, "PLUS / MINUS -> add / remove iterations");
	write_other_stuff(args);
}

void		fractol_define_window(t_args *args)
{
	args->line_x = WIN_S + 1;
	while (++args->line_x < WIN_S + 500 + 1)
	{
		args->line_y = -1;
		while (++args->line_y < WIN_S)
			mlx_pixel_put(args->mlx_ptr, args->win_ptr, args->line_x,
					args->line_y, DARK_RED);
	}
	args->line_x = 0;
	args->line_y = 0;
	trace_lines(args);
	write_stuff(args);
}
