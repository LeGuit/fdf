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
#include <stdio.h>

#define CAST(type, ptr)				((type)(ptr))

void				put_pix_to_img(t_vec3i *v, t_image *i)
{
	int				off_x;
	int				off_y;

	off_x = (v->x);
	off_y = (W_HEIGHT - v->y) * W_WIDTH;
	if (v->x < 0 || v->y < 0
		|| v->x > W_WIDTH || v->y > W_HEIGHT)
		return ;
	CAST(int *, i->data)[off_x + off_y] = v->z;
}

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

void				draw(t_data *data, t_mlx *mlx)
{
	int				i;
	t_vec3i			screen_coord;
	t_vec4f			view_coord;

	i = 0;
	while (i + 1 < (int)data->vertices.size)
	{
		view_coord = CAST(t_vertex *, ft_vect_at(&data->vertices, i))->pos;
		world_to_view(&view_coord);
		view_to_screen(&view_coord, &screen_coord,
			data, &mlx->v_screen);
		if (i < (int)data->vertices.size - data->ncol)
		{
			line_calc(data, mlx, i + data->ncol, &screen_coord);
		}
		if ((i + 1) % data->ncol == 0 && i != 0)
		{
			i++;
			continue ;
		}
		line_calc(data, mlx, i + 1, &screen_coord);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->screen.ptr, 0, 0);
}
