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
#define SCALE						2

void				put_pix_to_img(t_vec3i *v, t_image *i)
{
	int				off_x;
	int				off_y;

	off_x = (v->x + (W_WIDTH) / 2);
	off_y = ((W_HEIGHT) / 2 - v->y) * W_WIDTH;
	ft_printf("x: %d\ty: %d\n", off_x, off_y);
	if (v->x < -(i->view.xmax) || v->y > -(i->view.ymax)
		|| v->x > i->view.xmax || v->y < i->view.ymax)
		return ;
	CAST(int *, i->data)[(off_x + off_y)] = v->z;
}



void				draw(t_image *image, t_vect *vert2d)
{
	t_vec3i			*v;
	size_t 			i;

	i = 0;
	while (i < vert2d->size)
	{
		v = ft_vect_at(vert2d, i);
		//print_vec3i(v);
		put_pix_to_img(v, image);
		i++;
	}
}
