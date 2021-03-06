/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_proj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 19:14:44 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/03 19:22:58 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#define CAST(type, ptr)				((type)(ptr))

void				view_to_screen(t_vec4f *v4f, t_vec3i *v3i,
						t_data *data, t_view *v_screen)
{
	v3i->x = (int)(((v4f->x - data->v_world.xmin)
		/ (data->v_world.xmax - data->v_world.xmin))
		* (v_screen->xmax - v_screen->xmin) + v_screen->xmin);
	v3i->y = (int)(((v4f->y - data->v_world.ymin)
		/ (data->v_world.ymax - data->v_world.ymin))
		* (v_screen->ymax - v_screen->ymin) + v_screen->ymin);
	v3i->z = mix_color(C_MIN, C_MAX, (v4f->z - data->zmin)
		/ (data->zmax - data->zmin));
}

void				world_to_view(t_vec4f *v)
{
	float			tmpx;

	tmpx = v->x;
	v->x = (sqrt(2.f) / 2.f * (tmpx - v->y));
	v->y = (sqrt(2.f / 3.f) * (v->z)
				- (1.f / sqrt(6.f)) * (tmpx + v->y));
}
