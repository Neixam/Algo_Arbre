#include "tp3.h"

int		affiche_err(Rech data)
{
	if (data.err_val == 1)
		fprintf(stderr, "bad usage :\n./tp3 \n");
	if (data.err_val == 2)
		fprintf(stderr, "Error allocation\n");
	if (data.err_val == 3)
		fprintf(stderr, "Error file %s doesn't exist\n", data.f_nom);
	return (1);
}
