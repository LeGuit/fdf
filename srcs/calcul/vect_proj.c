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

void				build_vect(t_data *data, t_vec3i *v3i_ptr, t_mlx *mlx)
{
	t_vec4f			view_coord;
	t_vec3i			screen_coord;
	int				i;

	v3i_ptr = (t_vec3i)malloc(sizeof(t_vec3i) * (data->ncol * data->n));
	i = 0;
	while (i < (int)data->vertices.size)
	{
		view_coord = CAST(t_vertex *, ft_vect_at(&data->vertices, i))->pos;
		world_to_view(&view_coord);
		view_to_screen(&view_coord, &screen_coord, data, &mlx->v_screen);
		v3i_ptr[i] = screen_coord;
		i++;
	}
}