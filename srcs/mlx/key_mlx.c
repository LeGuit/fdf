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

#include <stdio.h>

int					key_value(int keycode)
{
	ft_printf("key code: %d\n", keycode);
	return (keycode);
}

int					key_esc()
{
	ft_printf("ESC pressed:\nEXIT SUCCESS");
	exit(0);
}

int					key_zoom_in(void *params)
{
	((t_data *)params)->v_world.xmin++;
	((t_data *)params)->v_world.ymin++;
	((t_data *)params)->v_world.xmax--;
	((t_data *)params)->v_world.ymax--;
	return (0);
}

int					key_zoom_out(void *params)
{
	((t_data *)params)->v_world.xmin--;
	((t_data *)params)->v_world.ymin--;
	((t_data *)params)->v_world.xmax++;
	((t_data *)params)->v_world.ymax++;
	return (0);
}
