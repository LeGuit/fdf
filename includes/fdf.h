/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:36:36 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/24 10:44:39 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include "libft.h"
# define C_VEC4(ptr)		((t_vec4 const *)ptr)
# define WIDTH				600
# define HEIGHT				400

typedef struct		s_data
{
	t_vect			vertices;
	int				nrow;
	int				ncol;
}					t_data;

typedef struct		s_image
{
	void			*ptr;
	int				bpp;
	int				size_line;
	int				endian;
	char			*data;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			screen;
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
void				error_map(void);

void				print_vertex(t_vertex const *vec);
void				print_vec4(t_vec4 const *vec);

void				get_file(char *av, t_data *data);
void				mlx_start(t_data *data);
int					ft_mlx_image_init(void *mlx_ptr, t_image *image,
					int width, int height);

int					key_value(int keycode, void *params);
int					key_esc(int keycode, void *params);
int					key_call(int keycode, void *params);
void				error_args(void);

#endif
