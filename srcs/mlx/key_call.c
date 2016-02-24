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
	if (keycode == 53)
		key_esc(keycode, params);
	// else if (keycode == 123)
	// 	key_trans_left();
	// else if (keycode == 124)
	// 	key_trans_right();
	// else if (keycode == 125)
	// 	key_trans_down();
	// else if (keycode == 126)
	// 	key_trans_up();
	// else if (keycode == 2)
	// 	key_rot_right();
	// else if (keycode == 0)
	// 	key_rot_left();
	// else if (keycode == 13)
	// 	key_rot_up();
	// else if (keycode == 1)
	// 	key_rot_down();
	// else if (keycode == 69)
	// 	key_zoom_im();
	// else if (keycode == 78)
	// 	key_zoom_out();
	else
		key_value(keycode, params);
	return (0);
}
