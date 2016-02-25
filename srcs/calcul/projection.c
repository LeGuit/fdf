
#include <math.h>
#include "fdf.h"

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