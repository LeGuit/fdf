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
#include "mlx.h"
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
	t_matrix		mat;

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
	{ 
		ft_bzero(&mat, 16);
		if (keycode == D_KEY)
			rot_x(&mat, 10);
		else if (keycode == A_KEY)
			rot_x(&mat, -10);
		else if (keycode == W_KEY)
			rot_y(&mat, 10);
		else if (keycode == S_KEY)
			rot_y(&mat, -10);
		matrix_calcul(data, &mat);

	}
	return (0);
}
