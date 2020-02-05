#include "tp3.h"

int		verif_bin_rech(Arbre a)
{
	if (a == NULL)
		return (1);
	return ((verif_bin_rech(a->fg) < a->val) &&
			(a->val < verif_bin_rech(a->fd)));
}
