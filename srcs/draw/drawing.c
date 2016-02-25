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

void				put_pix_to_img(t_vec3i *v, t_image *i)
{
	int				off_x;
	int				off_y;

	if (v->x < 0 || v->y < 0 || v->x > i->xmax || v->y > i->ymax)
		return ;
	off_x = (v->x + (W_WIDTH) / 2);
	off_y = ((W_HEIGHT) / 2 - v->y) * W_WIDTH;
	CAST(int *, i->data)[off_x + off_y] = v-z;
}



void				draw(t_image *image, t_vect *vert2d)
{
	t_vec3i			*v;
	size_t 			i;

	i = 0;
	while (i < vert2d->size)
	{
		v = ft_vect_at(vert2d, i);
		// ft_printf("PIXEL_OFFSET: %d\n", (int)PIXEL_OFFSET(v->x, v->y, I_WIDTH));
		print_vec3i(v);
		put_pix_to_img(v, image);
		i++;
	}
}
