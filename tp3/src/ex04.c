#include "tp3.h"

Arbre extraitMax(Arbre *a)
{
	Arbre	ret;

	if (*a == NULL)
		return (NULL);
	if ((*a)->fd != NULL)
		return (extraitMax(&((*a)->fd)));
	ret = *a;
	if ((*a)->fg)
		(*a) = (*a)->fg;
	else
		(*a) = NULL;
	return (ret);
}
