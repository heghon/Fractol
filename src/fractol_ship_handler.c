/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_ship_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:01:44 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/14 11:32:56 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ship_calculations(t_data *data)
{
	data->n = -1;
	while (++data->n < data->it && (data->c[RE] * data->c[RE]
				+ data->c[IM] * data->c[IM]) < 4)
	{
		data->b[RE] = data->c[RE] * data->c[RE];
		data->b[IM] = data->c[IM] * data->c[IM];
		data->c[IM] = fabs(data->c[RE] * data->c[IM]) * 2.0 + data->tmp_c[IM];
		data->c[RE] = data->b[RE] - data->b[IM] + data->tmp_c[RE];
	}
}

static void	*launch_the_fractal(void *tab)
{
	t_data	*data;

	data = (t_data *)tab;
	while (data->y_min < data->y_max)
	{
		data->x = -1;
		while (++data->x < WIN_S)
		{
			data->c[RE] = (data->x - WIN_S / 2.0) * data->zoom + data->mx;
			data->c[IM] = (data->y_min - WIN_S / 2.0) * data->zoom + data->my;
			data->tmp_c[RE] = data->c[RE];
			data->tmp_c[IM] = data->c[IM];
			ship_calculations(data);
			data->z = data->c[RE] * data->c[RE] + data->c[IM] * data->c[IM];
			if (data->n < data->it)
				fractol_drawing(data, data->args);
		}
		data->y_min++;
	}
	pthread_exit(0);
}

void		fractol_ship_handler(t_args *args)
{
	pthread_t	thr[THREAD_NUMBER];
	t_data		data[THREAD_NUMBER];
	int			i;

	i = -1;
	while (++i < THREAD_NUMBER)
	{
		data[i].zoom = args->zoom;
		data[i].y_max = 50 * (i + 1);
		data[i].y_min = data[i].y_max - 50;
		data[i].mx = args->mx;
		data[i].my = args->my;
		data[i].it = args->it;
		data[i].theme = args->theme;
		data[i].args = args;
		pthread_create(&(thr[i]), NULL, launch_the_fractal, (void *)&(data[i]));
	}
	fractol_type_writer(args);
	i = -1;
	while (++i < THREAD_NUMBER)
		pthread_join(thr[i], NULL);
}
