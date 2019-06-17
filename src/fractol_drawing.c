/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:55:08 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/14 11:30:22 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_color	*init_color(t_data *data)
{
	t_color *color;

	if (!(color = malloc(sizeof(t_color))))
		return (0);
	color->phase = 5;
	color->width = 110;
	color->center = 135;
	if (data->theme == 2)
	{
		color->phase = 2;
		color->width = 110;
		color->center = 135;
	}
	if (data->theme == 3)
	{
		color->phase = 4;
		color->width = 135;
		color->center = 120;
	}
	return (color);
}

void			fractol_drawing(t_data *data, t_args *args)
{
	int		i;
	t_color	*color;
	double	j;

	color = init_color(data);
	i = (data->x * (args->bpp / 8)) + (data->y_min * args->s_line);
	j = ((double)data->n + 1) - (1 / data->z);
	color->freq = M_PI * 2 / data->it;
	args->pics[i] = sin(color->freq * j + 4 + color->phase) *
		color->width + color->center;
	args->pics[i + 1] = sin(color->freq * j + 2 + color->phase) *
		color->width + color->center;
	args->pics[i + 2] = sin(color->freq * j + 1 + color->phase) *
		color->width + color->center;
	free(color);
}
