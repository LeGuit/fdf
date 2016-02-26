
#include <math.h>
#include "fdf.h"
#include <stdio.h>

#define SCALE		2.f

// static void			scaling(t_vertex *v)
// {
// 	t_matrix		mat;
// 	ft_bzero(&mat, 16);
// 	mat.m[0] = SCALE;
// 	mat.m[5] = SCALE;
// 	mat.m[10] = SCALE;
// 	mat.m[15] = 1;
// 	matrix_calcul(v, &mat);
// }


void				projection(t_vect *vertices, t_vect *vert2d, t_viewport *view)
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
//scaling(v);
		v3i.x = (int)(sqrt(2.f) / 2.f * (v->pos.x - v->pos.y));
		v3i.y = (int)(sqrt(2.f) / 3.f * (v->pos.z) - 1.f / sqrt(6.f) * (v->pos.x + v->pos.y));
		printf("ybase: %f\typroj: %d\n", v->pos.y, v3i.y);
		v3i.z = v->pos.z > 0 ? 0xFF0000 : 0xFFFFFF;
		i++;
		ft_vect_push_back(vert2d, &v3i);
	//	 print_vec3i(&v3i);
	}
	view->xmax = (int)(sqrt(2.f) / 2.f * (W_WIDTH - W_HEIGHT));
	view->ymax = (int)((-1.f) / sqrt(6.f) * (W_WIDTH + W_HEIGHT)) * W_WIDTH;
	ft_printf("xmax: %d\tymax: %d\n", view->xmax, view->ymax);
	// ft_vect_print(vert2d, &print_vertex);
}
