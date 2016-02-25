
#include "fdf.h"
#include <math.h>

void				rot_x(t_matrix *mat, int theta)
{
	mat->m[0] = 1;
	mat->m[5] = cos(theta);
	mat->m[6] = -sin(theta);
	mat->m[9] = sin(theta);
	mat->m[10] = cos(theta);
	mat->m[15] = 1;
}

void				rot_y(t_matrix *mat, int theta)
{
	mat->m[5] = 1;
	mat->m[0] = cos(theta);
	mat->m[8] = -sin(theta);
	mat->m[2] = sin(theta);
	mat->m[10] = cos(theta);
	mat->m[15] = 1;
}

void				trans_v(t_matrix *mat, int keycode)
{
	t_vertex		v;

	if (keycode == LARROW)
		v = {-1, 0, 0, 1};
	else if (keycode == RARROW)
		v = {1, 0, 0, 1};
	else if (keycode == UARROW)
		v = {0, 1, 0, 1};
	else if (keycode == DARROW)
		v = {0, -1, 0, 1};
	mat->m[0] = 1;
	mat->m[5] = 1
	mat->m[10] = 1
	mat->m[15] = 1
	mat->m[3] = v->pos->x;
	mat->m[7] = v->pos->y;
	mat->m[11] = v->pos->z;
}