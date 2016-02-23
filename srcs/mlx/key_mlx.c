/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:15:36 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/23 18:15:38 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int					key_value(int keycode, void *params)
{
	(void)params;
	ft_printf("key code: %d\n", keycode);
	return (0);
}

int					key_esc(int keycode, void *params)
{
	ft_printf("ESC pressed:\n EXIT SUCCESS");
	exit(0);
}
