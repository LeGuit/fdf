/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:02:41 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/26 18:03:01 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define CAST(type, ptr)	((type)(ptr))
#define VPOS(i)			CAST(t_vertex *, ft_vect_at(&data->vertices, i))->pos	

void				matrix_calcul(t_data *data, t_matrix *mat)
{
	size_t			i;

	i = 0;
	while (i < data->vertices.size)
	{
		VPOS(i).x = mat->m[0] * VPOS(i).x + mat->m[1] * VPOS(i).y
					+ mat->m[2] * VPOS(i).z + mat->m[3] * VPOS(i).w;
		VPOS(i).y = mat->m[4] * VPOS(i).x + mat->m[5] * VPOS(i).y
					+ mat->m[6] * VPOS(i).z + mat->m[7] * VPOS(i).w;
		VPOS(i).z = mat->m[8] * VPOS(i).x + mat->m[9] * VPOS(i).y
					+ mat->m[10] * VPOS(i).z + mat->m[11] * VPOS(i).w;
		VPOS(i).w = mat->m[12] * VPOS(i).x + mat->m[13] * VPOS(i).y 
					+ mat->m[14] * VPOS(i).z + mat->m[15] * VPOS(i).w;
		i++;
	}
}

int					key_hook(int keycode, void *data)
{
	// t_matrix		mat;

	if (keycode == PLUS)
		key_zoom_in(data);
	else if (keycode == MINUS)
		key_zoom_out(data);
	else if (keycode == ESC)
		key_esc();
	else if (keycode == LARROW)
		key_larrow(data);
	else if (keycode == RARROW)
		key_rarrow(data);
	else if (keycode == UARROW)
		key_uarrow(data);
	else if (keycode == DARROW)
		key_darrow(data);
	else
		key_value(keycode);
	return (0);
	// {
	// 	ft_bzero(&mat, 16);
	// 	// else if (keycode == D_KEY)
	// 	// 	key_rot_right();
	// 	// else if (keycode == A_KEY)
	// 	// 	key_rot_left();
	// 	// else if (keycode == W_KEY)
	// 	// 	key_rot_up();
	// 	// else if (keycode == S_KEY)
	// 	// 	key_rot_down();
	// 	matrix_calcul(data, &mat);
	// }
	// return (0);
}
