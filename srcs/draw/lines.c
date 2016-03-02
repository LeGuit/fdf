

#include "fdf.h"
#include "mlx.h"

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
