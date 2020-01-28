#include "tp1.h"

int		RechercheDico(ListeM *T, char *mot, int len)
{
	ListeM	tmp;

	for (tmp = T[hachage(mot) % len]; tmp; tmp = tmp->suivant)
	{
		if (ft_strcmp(tmp->mot, mot) == 0)
			return (tmp->nombre);
	}
	return (0);
}
