/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:23:45 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/23 16:53:08 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static void		get_nbrs(char *line, t_data *data)
{
	int			i;
	t_vertex	vertex;
	char		*tmp_line;

	i = 0;
	tmp_line = line;
	while (i < data->ncol)
	{
		while (*tmp_line == ' ' && *tmp_line)
			tmp_line++;
		vertex.pos.x = (float)i;
		vertex.pos.y = (float)data->nrow;
		vertex.pos.z = (float)(ft_atoi(tmp_line));
		vertex.pos.w = (float)1;
		ft_vect_push_back(&data->vertices, &vertex);
		while (ft_isdigit(*tmp_line) || *tmp_line == '-')
			tmp_line++;
		i++;
	}
	free(line);
}

static int		check_line(char *line, t_data *data)
{
	int			i;

	i = 0;
	if (((int)ft_nb_words(line, ' ') != data->ncol))
		return (2);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n' || line[i] == '-')
			i++;
		else if (!ft_isdigit(line[i]))
			return (1);
		i++;
	}
	return (0);
}

void			get_file(char *av, t_data *data)
{
	int			fd;
	char		*line;
	int			ret;

	if ((fd = open(av, O_RDONLY)) == -1)
		error_open();
	while ((ret = get_next_line(fd, &line) > 0))
	{
		data->nrow++;
		if (data->nrow == 0)
			data->ncol = ft_nb_words(line, ' ');
		if ((ret = check_line(line, data)))
			error_file(ret);
		get_nbrs(line, data);
	}
	close(fd);
	ft_vect_print(&data->vertices, &print_vertex);
}
