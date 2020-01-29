#include "tp2.h"

int		main(int ac, char **av)
{
	Qlc		data;

	init_data(&data);
	if ((data->error_val = parsing_enter(ac, av, &data)))
		return (put_error(data));

		
	return (0);
}
