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
						t_view *v_world, t_view *v_screen)
{
	v3i->x = (int)(((v4f->x - v_world->xmin) / (v_world->xmax - v_world->xmin))
					* (v_screen->xmax - v_screen->xmin) + v_screen->xmin);
	v3i->y = (int)(((v4f->y - v_world->ymin) / (v_world->ymax - v_world->ymin))
					* (v_screen->ymax - v_screen->ymin) + v_screen->ymin);
	v3i->z = v4f->z > 0 ? 0xFFFFFF : 0xFF0000;
}

void				world_to_view(t_vec4f *v)
{
	float			tmpx;

	tmpx = v->x;
	v->x = (sqrt(2.f) / 2.f * (tmpx - v->y));
	v->y = (sqrt(2.f / 3.f) * (v->z)
				- (1.f / sqrt(6.f)) * (tmpx + v->y));
}

void				draw_lines(t_vec3i *v1, t_vec3i *v2, t_image *i)
{

// 	t_vec3i			vl;
// 	int				dx;
// 	int				dy;
// 	int				eps;


// 	vl = (t_vec3i){v1->x, v1->y, v1->z};
// 	dx = v2->x - v1->x;
// 	dy = v2->y - v1->y;
// 	eps = 0;
// 	while (vl.x <= v2->x)
// 	{
// 		put_pix_to_img(&vl, i);
// 		vl.x++;
// 		eps += dy;
// 		if (eps >= dx)
// 		{
// 			vl.y++;
// 			eps -= dx;
// 		}
// 	}
	t_vec3i			vl;

	vl = (t_vec3i){v1->x, v1->y, v1->z};
	while (vl.x <= v2->x)
	{
		put_pix_to_img(&vl, i);
		vl.x++;
		vl.y = (v2->y - v1->y) / (v2->x - v1->x);
	}
}

void				draw(t_data *data, t_mlx *mlx)
{
	size_t			i;
	t_vec3i			screen_coord;
	t_vec4f			view_coord;
	t_vec3i			screen_coord2;
	t_vec4f			view_coord2;

	i = 0;
	while (i < data->vertices.size)
	{
		view_coord = CAST(t_vertex *, ft_vect_at(&data->vertices, i))->pos;
		// if (i + 1 != data->vertices.size)
			view_coord2 = CAST(t_vertex *, ft_vect_at(&data->vertices, i + 1))->pos;
		world_to_view(&view_coord);
		world_to_view(&view_coord2);
		view_to_screen(&view_coord, &screen_coord,
						&data->v_world, &mlx->v_screen);
		view_to_screen(&view_coord2, &screen_coord2,
						&data->v_world, &mlx->v_screen);
		draw_lines(&screen_coord, &screen_coord2, &mlx->screen);
		//put_pix_to_img(&screen_coord, &mlx->screen);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->screen.ptr, 0, 0);
}
