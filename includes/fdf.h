/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:36:36 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/23 16:38:16 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include "../libft/includes/libft.h"
# define C_VEC4(ptr)		((t_vec4 const *)ptr)

typedef struct		s_data
{
	t_vect			vertices;
	size_t			nrow;
	size_t			ncol;
}					t_data;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4;

typedef struct		s_vertex
{
	t_vec4			pos;
}					t_vertex;

void				error_open(void);
void				error_file(int error);

void				print_vertex(t_vertex const *vec);
void				print_vec4(t_vec4 const *vec);

void				get_file(char *av, t_data *data);
void				error_args(void);

#endif
