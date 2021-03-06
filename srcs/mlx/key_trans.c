/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 19:17:39 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/03 19:17:46 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int					key_larrow(t_data *data)
{
	data->v_world.xmin++;
	data->v_world.xmax++;
	return (0);
}

int					key_rarrow(t_data *data)
{
	data->v_world.xmin--;
	data->v_world.xmax--;
	return (0);
}

int					key_uarrow(t_data *data)
{
	data->v_world.ymin--;
	data->v_world.ymax--;
	return (0);
}

int					key_darrow(t_data *data)
{
	data->v_world.ymin++;
	data->v_world.ymax++;
	return (0);
}
