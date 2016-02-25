
#include "fdf.h"
#include <math.h>

void				rot_x(t_matrix *mat)
{
	mat->m[0] = 1;
	mat->m[5] = cos(THETA);
	mat->m[6] = -sin(THETA);
	mat->m[9] = sin(THETA);
	mat->m[10] = cos(THETA);
	mat->m[15] = 1;
}

void				rot_y(t_matrix *mat)
{
	mat->m[5] = 1;
	mat->m[0] = cos(THETA);
	mat->m[8] = -sin(THETA);
	mat->m[2] = sin(THETA);
	mat->m[10] = cos(THETA);
	mat->m[15] = 1;
}

void				rot_z(t_matrix *mat)
{
	mat->m[10] = 1;
	mat->m[0] = cos(THETA);
	mat->m[1] = -sin(THETA);
	mat->m[4] = sin(THETA);
	mat->m[5] = cos(THETA);
	mat->m[15] = 1;
}

void				trans_v(t_matrix *mat, t_vertex *v)
{
	mat->m[0] = 1;
	mat->m[5] = 1
	mat->m[10] = 1
	mat->m[15] = 1
	mat->m[3] = v->pos->x;
	mat->m[7] = v->pos->y;
	mat->m[11] = v->pos->z;
}