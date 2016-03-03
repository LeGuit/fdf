/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:15:36 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/24 10:45:28 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int					key_value(int keycode)
{
	ft_printf("key code: %d\n", keycode);
	return (keycode);
}

int					key_esc(void)
{
	ft_printf("ESC pressed:\nEXIT SUCCESS");
	exit(0);
}

int					key_zoom_in(t_data *data)
{
	data->v_world.xmin /= 1.1f;
	data->v_world.ymin /= 1.1f;
	data->v_world.xmax /= 1.1f;
	data->v_world.ymax /= 1.1f;
	return (0);
}

int					key_zoom_out(t_data *data)
{
	data->v_world.xmin *= 1.1f;
	data->v_world.ymin *= 1.1f;
	data->v_world.xmax *= 1.1f;
	data->v_world.ymax *= 1.1f;
	return (0);
}

int					key_return(t_data *data)
{
	data->v_world.xmin = -(data->ncol) / 1.3f;
	data->v_world.xmax = (data->ncol) / 1.3f;
	data->v_world.ymin = -(data->nrow) / 1.3f;
	data->v_world.ymax = (data->nrow) / 1.3f;
	return (0);
}
