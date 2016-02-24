/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:36:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/23 16:52:43 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				error_open(void)
{
	ft_putendl_fd("fdf: open fail!", 2);
	exit(0);
}

void				error_args(void)
{
	return ;
}

void				error_file(int error)
{
	if (error == 2)
		ft_putendl_fd("fdf: nbcol are not the same!", 2);
	else if (error == 1)
		ft_putendl_fd("fdf: wrong char in the file!", 2);
	exit(0);
}

void				error_map(void)
{
	ft_putendl_fd("fdf: map error!", 2);
	exit(0);
}