#include "tp3.h"

int		verif_bin_rech(Arbre a)
{
	if (a == NULL)
		return (1);
	if (a->fg)
		return (verif_bin_rech(a->fg) < a->val);
	if (a->fd)
		return (a->val < verif_bin_rech(a->fd));
	return (a->val);
}
