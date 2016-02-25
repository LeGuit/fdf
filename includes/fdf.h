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
# define W_WIDTH				600
# define W_HEIGHT				400
# define I_WIDTH				600
# define I_HEIGHT				400

# define ESC				53
# define LARROW				123
# define RARROW				124
# define DARROW				125
# define UARROW				126
# define D_KEY				2
# define A_KEY				0
# define W_KEY				13
# define S_KEY				1
# define PLUS				69
# define MINUS				78

typedef struct		s_data
{
	t_vect			vertices;
	t_vect			vert2d;
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
	t_viewport		view;
}					t_image;

typedef struct		s_viewport
{
	int				xmax;
	int				ymax;
}					t_viewport;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			screen;
}					t_mlx;

typedef struct		s_vec3i
{
	int				x;
	int				y;
	int				z;
}					t_vec3i;

typedef struct		s_matrix
{
	float			m[16];
}					t_matrix;

typedef struct		s_vec4f
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4f;

typedef struct		s_vertex
{
	t_vec4f			pos;
}					t_vertex;

void				error_open(void);
void				error_file(int error);
void				error_map(void);

void				print_vertex(t_vertex const *vec);
void				print_vec4f(t_vec4f const *vec);
void				print_vec3i(t_vec3i const *vec);

void				get_file(char *av, t_data *data);
void				mlx_start(t_data *data);
int					ft_mlx_image_init(void *mlx_ptr, t_image *image,
					int width, int height);

int					key_value(int keycode, void *params);
int					key_esc(int keycode, void *params);
int					key_call(int keycode, void *params);
void				error_args(void);

void				projection(t_vect *vertices, t_vect *vert2d);
void				draw(t_image *image, t_vect *vert2d);
void				put_pix_to_img(t_vec3i *v, t_image *i);

#endif
