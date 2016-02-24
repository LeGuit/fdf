/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:31:09 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/23 16:51:43 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_vect.h"

static void		init_data(t_data *data)
{
	data->nrow = -1;
	data->ncol = 0;
	data->vertices = VECT_INI(t_vertex);
}

int				main(int ac, char **av)
{
	t_data		data;

	if (ac != 2)
		error_args();
	else
	{
		init_data(&data);
		get_file(av[1], &data);
		if (data.nrow == 0)
			error_map();
		mlx_start(&data);
	}
	return (0);
}
