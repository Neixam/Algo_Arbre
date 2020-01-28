#include "tp1.h"

int		main(int ac, char **av)
{
	Compte	data;

	init_data(&data);
	if ((data.error_val = parsing_enter(ac, av, &data)))
		return (put_error(data));
	if ((data.error_val = count_word(data)))
		return (put_error(data));
	return (0);
}
