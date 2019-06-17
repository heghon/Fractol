/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_newton_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:18:41 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/14 10:00:54 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	newton_calculations(t_data *data)
{
	data->n = -1;
	while (data->b[RE] > 0.000001 && ++data->n < data->it)
	{
		data->tmp_c[RE] = data->c[RE];
		data->tmp_c[IM] = data->c[IM];
		data->b[RE] = (data->c[RE] * data->c[RE] + data->c[IM] * data->c[IM])
			* (data->c[RE] * data->c[RE] + data->c[IM] * data->c[IM]);
		data->c[RE] = (2 * data->c[RE] * data->b[RE] + data->c[RE] *
				data->c[RE] - data->c[IM] * data->c[IM]) / (3.0 * data->b[RE]);
		data->c[IM] = (2 * data->c[IM] * (data->b[RE] - data->tmp_c[RE])) /
			(3.0 * data->b[RE]);
		data->b[RE] = (data->c[RE] - data->tmp_c[RE]) * (data->c[RE]
				- data->tmp_c[RE]) + (data->c[IM] - data->tmp_c[IM]) *
			(data->c[IM] - data->tmp_c[IM]);
	}
}

static void	*draw_the_fractal(void *tab)
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
			data->b[RE] = 3.0;
			newton_calculations(data);
			data->z = data->c[RE] * data->c[RE] + data->c[IM] * data->c[IM];
			if (data->n < data->it)
				fractol_drawing(data, data->args);
		}
		data->y_min++;
	}
	pthread_exit(0);
}

void		fractol_newton_handler(t_args *args)
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
		pthread_create(&(thr[i]), NULL, draw_the_fractal, (void *)&(data[i]));
	}
	fractol_type_writer(args);
	i = -1;
	while (++i < THREAD_NUMBER)
		pthread_join(thr[i], NULL);
}
