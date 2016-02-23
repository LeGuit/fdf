/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:27:36 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/23 18:27:36 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int					key_call(void *win_ptr, void *params)
{
	int				keycode;

	keycode = mlx_key_hook(win_ptr, key_value, params);
	if (keycode == 53)
		mlx_key_hook(win_ptr, key_esc, params);
	return (0);
}

