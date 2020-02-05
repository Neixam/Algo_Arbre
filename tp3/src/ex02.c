#include "tp3.h"

int		ajout(Arbre *a, int n)
{
	if (*a == NULL)
	{
		if (!(*a = alloueNoeud(n)))
			return (0);
		return (1);
	}
	if ((*a)->val == n)
		return (0);
	if ((*a)->val > n)
		return (ajout(&((*a)->fg), n));
	return (ajout(&((*a)->fd), n));
}
