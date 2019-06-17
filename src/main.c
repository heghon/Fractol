/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:53:09 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/15 15:35:53 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			init_args(t_args *args)
{
	args->zoom = 0.0035;
	args->mx = 0;
	args->my = 0;
	args->it = 20;
	args->tmp_c[RE] = 0;
	args->tmp_c[IM] = 0.8;
	args->theme = 1;
	args->mouse_move = 0;
	args->mouse_move_x = 1;
	args->mouse_move_stop = 1;
}

static int		compare_text(char *str)
{
	if (!ft_strcmp(str, "M"))
		return (1);
	else if (!ft_strcmp(str, "J"))
		return (2);
	else if (!ft_strcmp(str, "N"))
		return (3);
	else if (!ft_strcmp(str, "B"))
		return (4);
	return (0);
}

void			init_fractal(t_args *args)
{
	args->image = mlx_new_image(args->mlx_ptr, WIN_S, WIN_S);
	args->pics = mlx_get_data_addr(args->image, &(args->bpp),
			&(args->s_line), &(args->endian));
	if (args->fractal == 1)
		fractol_mandelbrot_handler(args);
	else if (args->fractal == 2)
		fractol_julia_handler(args);
	else if (args->fractal == 3)
		fractol_newton_handler(args);
	else if (args->fractal == 4)
		fractol_ship_handler(args);
	mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, args->image, 0, 0);
}

int				expose_handler(t_args *args)
{
	if (args->fractal)
		init_fractal(args);
	return (0);
}

int				main(int ac, char **av)
{
	t_args	*args;

	if (ac != 2 || compare_text(av[1]) == 0)
	{
		ft_putendl("usage : ./fractol M / J / N / B");
		exit(0);
	}
	args = ft_memalloc(sizeof(t_args));
	args->mlx_ptr = mlx_init();
	args->win_ptr = mlx_new_window(args->mlx_ptr, 1500, WIN_S, "fract'ol");
	args->fractal = compare_text(av[1]);
	init_args(args);
	fractol_define_window(args);
	mlx_expose_hook(args->win_ptr, expose_handler, args);
	mlx_hook(args->win_ptr, 2, 5, fractol_key_handler, args);
	mlx_mouse_hook(args->win_ptr, fractol_mouse_handler, args);
	mlx_hook(args->win_ptr, 17, 0L, fractol_close, (void*)0);
	mlx_hook(args->win_ptr, 6, 1L << 6, mouse_movement, args);
	mlx_loop(args->mlx_ptr);
	return (0);
}
