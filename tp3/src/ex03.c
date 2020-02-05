#include "tp3.h"

Arbre	extraitMin(Arbre *a)
{
	Arbre	ret;

	if (*a == NULL)
		return (NULL);
	if ((*a)->fg != NULL)
		return (extraitMin(&((*a)->fg)));
	ret = *a;
	if ((*a)->fd)
		(*a) = (*a)->fd;
	else
		(*a) = NULL;
	return (ret);
}
