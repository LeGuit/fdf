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

static int			set_color(int z)
{
	if (z < -5)
		return (0x8100E5);
	if (z < -4)
		return (0x7C13CE);
	if (z < -3)
		return (0x7726B7);
	if (z < -2)
		return (0x7339A0);
	if (z < -1)
		return (0x6E4C89);
	if (z < 0)
		return (0x6A5F72);
	if (z < 1)
		return (0x65725B);
	if (z < 2)
		return (0x608544);
	if (z < 3)
		return (0x5C982D);
	if (z < 4)
		return (0x57AB16);
	if (z < 5)
		return (0x53BF00);
	else
		return (0xFFFFFF);
}

static int			grad_color(int z1, int z2 , int grad)
{
	float			space;
	float			f1;
	float			f2;

	f1 = (float)z1;
	f2 = (float)z2;

	f1 = (f1 + 5) / 10 * (f2 - f1) + f1;
	f2 = (f2 + 5) / 10 * (f2 - f1) + f1;
	space = fabs(f1 - f2) * grad / 200;
	// ft_printf("z1: %d\t z2: %d\t space: %d\n", z1, z2, space);
	return (set_color((int)space));

}

int					get_color(int z1, int z2, int grad)
{
	// int				color1;
	// int				color2;

	if (z1 == z2)
	{	
		z1 = ((float)z1 - (-5))/(10) * ((float)z2 - (float)z1) + (float)z1;
		return (set_color(z1));
	}
	// color1 = set_color(z1);
	// color2 = set_color(z2);
	return (grad_color(z1, z2, grad));
}
