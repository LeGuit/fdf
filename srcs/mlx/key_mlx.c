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

int					key_value(int keycode, void *params)
{
	(void)params;
	ft_printf("key code: %d\n", keycode);
	return (keycode);
}

int					key_esc(int keycode, void *params)
{
	(void)params;
	(void)keycode;
	ft_printf("ESC pressed:\nEXIT SUCCESS");
	exit(0);
}
