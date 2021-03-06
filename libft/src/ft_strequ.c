/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:41:16 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/05 10:54:32 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strequ(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
