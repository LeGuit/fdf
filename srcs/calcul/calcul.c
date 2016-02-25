

#include "fdf.h"



void				transfo_calcul(t_vertex *v, t_matrix *mat)
{
	v->pos->x = mat->m[0] * v->pos->x + mat->m[1] * v->pos->y
				+ mat->m[2] * v->pos->z + mat->m[3] * v->pos->w;
	v->pos->y = mat->m[4] * v->pos->x + mat->m[5] * v->pos->y
				+ mat->m[6] * v->pos->z + mat->m[7] * v->pos->w;
	v->pos->z = mat->m[8] * v->pos->x + mat->m[9] * v->pos->y
				+ mat->m[10] * v->pos->z + mat->m[11] * v->pos->w;
	v->pos->w = mat->m[12] * v->pos->x + mat->m[13] * v->pos->y 
				+ mat->m[14] * v->pos->z + mat->m[15] * v->pos->w;
}

void				transfo_vertex(t_vertex *v, void (transfo)())
{

}