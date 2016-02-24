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

#define PIXEL_OFFSET(x, y, w)	((int)((y) * (w) + (x)))
#define CAST(type, ptr)			((type)(ptr))

void				try_draw(t_image *image, t_vect *vertices, t_data *data)
{
	t_vertex		*v;
	size_t i = 0;

	(void)data;
	int color = 0;
	ft_printf("col1: %d\n", color);
	while (i < vertices->size)
	{
		v = ft_vect_at(vertices, i);
		color = (v->pos.z > 0) ? 0xFF0000 : 0x0000FF;
		ft_printf("PIXEL_OFFSET: %d\n", (int)PIXEL_OFFSET(v->pos.x, v->pos.y, I_WIDTH));
		print_vertex(v);
		CAST(int*, image->data)[PIXEL_OFFSET(v->pos.x, v->pos.y, I_WIDTH)] = color;
		i++;
	}
}
