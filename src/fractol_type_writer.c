/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_type_writer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:21:10 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/14 11:32:34 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractol_type_writer(t_args *args)
{
	int	x;
	int	y;

	x = WIN_S + 190;
	while (++x < WIN_S + 500 - 4)
	{
		y = 90;
		while (++y < 110)
			mlx_pixel_put(args->mlx_ptr, args->win_ptr, x, y, DARK_RED);
	}
	if (args->fractal == 1)
		mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 190, 90,
				WHITE, "MANDELBROT");
	else if (args->fractal == 2)
		mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 190, 90,
				WHITE, "JULIA");
	else if (args->fractal == 3)
		mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 190, 90,
				WHITE, "NEWTON");
	else if (args->fractal == 4)
		mlx_string_put(args->mlx_ptr, args->win_ptr, WIN_S + 190, 90,
				WHITE, "BURNING SHIP");
}
