#include "tp3.h"

void	init_data(Rech *data)
{
	data->fichier = NULL;
	data->f_nom = NULL;
	data->err_val = 0;
}

void	libere_data(Rech *data)
{
	if (data->fichier)
		fclose(data->fichier);
	if (data->f_nom)
		free(data->f_nom);
}
