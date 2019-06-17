/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:56:06 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/05 11:52:00 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], fd);
	ft_putchar_fd('\n', fd);
}
