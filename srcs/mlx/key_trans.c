
#include "fdf.h"
#include "mlx.h"

int					key_larrow(t_data *data)
{
	data->v_world.xmin++;
	data->v_world.xmax++;
	return (0);
}

int					key_rarrow(t_data *data)
{
	data->v_world.xmin--;
	data->v_world.xmax--;
	return (0);
}

int					key_uarrow(t_data *data)
{
	data->v_world.ymin--;
	data->v_world.ymax--;
	return (0);
}

int					key_darrow(t_data *data)
{
	data->v_world.ymin++;
	data->v_world.ymax++;
	return (0);
}