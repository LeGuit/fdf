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

#define CAST(type, ptr)				((type)(ptr))
#define PIX_OFF_Y(y, h)				((-y) + (h) / 2)
#define PIX_OFF_X(x, w)				((x) + (w) / 2)
// #define PIXEL_OFFSET(x, y, w, h)	CAST(int, PIX_OFF_Y(y, h) * (w) + PIX_OFF_X(x, w))
#define PIXEL_OFFSET(x, y, w, h)	CAST(int, (h / 2 - y) * w + w / 2 + x)//PIX_OFF_Y(y, h) * (w) + PIX_OFF_X(x, w))

// void				translation(int x, int y, t_vect *vert2d)
// {
// 	size_t			i;
// 	t_vec3i			*v;

// 	i = 0;
// 	while (i < vert2d->size)
// 	{
// 		v = ft_vect_at(vert2d, i);
// 		v->x += ABS(x);
// 		v->y += ABS(y);
// 		i++;
// 		ft_printf("translation: ");
// 		print_vec3i(v);
// 	}
// }

void				projection(t_vect *vertices, t_vect *vert2d)
{
	size_t			i;
	t_vec3i			v3i;
	t_vertex		*v;
	// int				minx = 0;
	// int				miny = 0;

	i = 0;
	while (i < vertices->size)
	{
		v = ft_vect_at(vertices, i);
		v3i.x = (int)(sqrt(2.f) / 2.f * (v->pos.x - v->pos.y));
		v3i.y = (int)(sqrt(2.f) / 3.f * (v->pos.z) - 1.f / sqrt(6.f) * (v->pos.x + v->pos.y));
		v3i.z = v->pos.z > 0 ? 0xFF0000 : 0xFFFFFF;
		// minx = MIN(minx, v3i.x);
		// miny = MIN(miny, v3i.y);
		i++;
		ft_vect_push_back(vert2d, &v3i);
		 print_vec3i(&v3i);
	}
	// translation(minx, miny, vert2d);
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
		// ft_printf("PIXEL_OFFSET: %d\n", (int)PIXEL_OFFSET(v->x, v->y, I_WIDTH));
		print_vec3i(v);
		CAST(int*, image->data)[PIXEL_OFFSET(v->x, v->y, I_WIDTH, I_HEIGHT) * 10] = v->z;
		i++;
	}
}
