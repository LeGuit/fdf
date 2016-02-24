/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:46:03 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/24 10:46:05 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int					key_call(int keycode, void *params)
{
	if (keycode == ESC)
		key_esc(keycode, params);
	// else if (keycode == LARROW)
	// 	key_trans_left();
	// else if (keycode == RARROW)
	// 	key_trans_right();
	// else if (keycode == DARROW)
	// 	key_trans_down();
	// else if (keycode == UARROW)
	// 	key_trans_up();
	// else if (keycode == D_KEY)
	// 	key_rot_right();
	// else if (keycode == A_KEY)
	// 	key_rot_left();
	// else if (keycode == W_KEY)
	// 	key_rot_up();
	// else if (keycode == S_KEY)
	// 	key_rot_down();
	// else if (keycode == PLUS)
	// 	key_zoom_im();
	// else if (keycode == MINUS)
	// 	key_zoom_out();
	else
		key_value(keycode, params);
	return (0);
}
