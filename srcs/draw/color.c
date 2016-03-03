/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:29:31 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/03 10:29:31 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

#define GET_R(color)			(color & 0xFF0000 >> 16)
#define GET_G(color)			(color & 0x00FF00 >> 8)
#define GET_B(color)			(color & 0x0000FF)

#define SET_R(dst, src)			dst |= ((src & 0xFF) << 16)
#define SET_G(dst, src)			dst |= ((src & 0xFF) << 8)
#define SET_B(dst, src)			dst |= ((src & 0xFF)

// int					mix_color(int c1, int c2, float lambda)
// {

// }

static int			set_color(int z)
{
	if (z < 0)
		return (0xFF0000);
	if (z == 0)
		return (0x8100E5);
	if (z == 1)
		return (0x7C13CE);
	if (z == 2)
		return (0x7726B7);
	if (z == 3)
		return (0x7339A0);
	if (z == 4)
		return (0x6E4C89);
	if (z == 5)
		return (0x6A5F72);
	if (z == 6)
		return (0x65725B);
	if (z == 7)
		return (0x608544);
	if (z == 8)
		return (0x5C982D);
	if (z == 9)
		return (0x57AB16);
	if (z == 10)
		return (0x53BF00);
	else
		return (0xFFFFFF);
}

static int			grad_color(int z1, int z2 , int grad, int gradmax)
{
	float			space;
	float			f1;
	float			f2;

	f1 = (float)z1;
	f2 = (float)z2;

	f1 = (f1 + 5) / 10 * (f2 - f1) + f1;
	f2 = (f2 + 5) / 10 * (f2 - f1) + f1;
	space = fabs(f1 - f2) * grad / gradmax;
	return (set_color((int)fcol));

}

int					get_color(int z1, int z2, int grad, int gradmax)
{
	if (z1 == z2)
	{	
		z1 = ((float)z1 - (-5.f))/(10.f) * ((float)z2 - (float)z1) + (float)z1;
		return (set_color(z1));
	}
	return (grad_color(z1, z2, grad, gradmax));
}
