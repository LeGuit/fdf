/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:39:35 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/24 13:39:37 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

#define PIXEL_OFFSET(x, y, w)	((int)((y) * (w) + (x)))
#define CAST(type, ptr)			((type)(ptr))

void				projection(t_vect *vertices, t_vect *vert2d)
{
	size_t			i;
	t_vec3i			v3i;
	t_vertex		*v;

	i = 0;
	while (i < vertices->size)
	{
		v = ft_vect_at(vertices, i);
		v3i.x = (int)fabs(sqrt(2) / 2 * (v->pos.x - v->pos.y));
		v3i.y = (int)fabs(sqrt(2) / 3 * v->pos.z - 1 / sqrt(6) * (v->pos.x + v->pos.y));
		v3i.z = v->pos.z > 0 ? 0xFF0000 : 0xFFFFFF;
		i++;
		ft_vect_push_back(vert2d, &v3i);
		// print_vec3i(&v3i);
	}
	// ft_vect_print(vert2d, &print_vertex);
}

void				try_draw(t_image *image, t_vect *vert2d)
{
	t_vec3i			*v;
	size_t 			i;

	i = 0;
	while (i < vert2d->size)
	{
		v = ft_vect_at(vert2d, i);
		ft_printf("PIXEL_OFFSET: %d\n", (int)PIXEL_OFFSET(v->x, v->y, I_WIDTH));
		print_vec3i(v);
		CAST(int*, image->data)[PIXEL_OFFSET(v->x, v->y, I_WIDTH) * 10] = v->z;
		i++;
	}
}
