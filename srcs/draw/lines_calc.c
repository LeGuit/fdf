/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:57:11 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/02 14:59:39 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

#define CAST(type, ptr)				((type)(ptr))

void				draw_lines(t_vec3i *v1, t_vec3i *v2, t_image *i)
{
	t_vec3i			vl;
	int				err;

	err = ABS(v2->x - v1->x) - ABS(v2->y - v1->y);
	vl = (t_vec3i){v1->x, v1->y, v1->z};
	while (1)
	{
		put_pix_to_img(&vl, i);
		if (vl.x == v2->x && vl.y == v2->y)
			break ;
		if (2 * err > -ABS(v2->y - v1->y))
		{
			err -= ABS(v2->y - v1->y);
			vl.x += v1->x < v2->x ? 1 : -1;
		}
		if (2 * err < ABS(v2->x - v1->x))
		{
			err += ABS(v2->x - v1->x);
			vl.y += v1->y < v2->y ? 1 : -1;
			vl.z = v2->z;
		}
	}
}

void				line_calc(t_data *data, t_mlx *mlx, int index,
					t_vec3i *screen_coord)
{
	t_vec3i			screen_coord2;
	t_vec4f			view_coord2;

	view_coord2 = CAST(t_vertex *, ft_vect_at(&data->vertices, index))->pos;
	world_to_view(&view_coord2);
	view_to_screen(&view_coord2, &screen_coord2,
		&data->v_world, &mlx->v_screen);
	draw_lines(screen_coord, &screen_coord2, &mlx->screen);
}
