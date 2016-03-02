
#include "fdf.h"
#include "mlx.h"

int					key_larrow(void *params)
{
	((t_data *)params)->v_world.xmin++;
	((t_data *)params)->v_world.xmax++;
	return (0);
}

int					key_rarrow(void *params)
{
	((t_data *)params)->v_world.xmin--;
	((t_data *)params)->v_world.xmax--;
	return (0);
}

int					key_uarrow(void *params)
{
	((t_data *)params)->v_world.ymin--;
	((t_data *)params)->v_world.ymax--;
	return (0);
}

int					key_darrow(void *params)
{
	((t_data *)params)->v_world.ymin++;
	((t_data *)params)->v_world.ymax++;
	return (0);
}