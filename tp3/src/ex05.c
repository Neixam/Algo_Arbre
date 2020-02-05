#include "tp3.h"

Arbre	extrait(Arbre *a, int n)
{
	Arbre	ret;
	Arbre	tmp;

	if (*a == NULL)
		return (NULL);
	if ((*a)->val > n)
		return (extrait(&((*a)->fg), n));
	if ((*a)->val < n)
		return (extrait(&((*a)->fd), n));
	ret = *a;
	if ((*a)->fg && (*a)->fd)
	{
		for (tmp = (*a)->fg; tmp && tmp->fd; tmp = tmp->fd);
		tmp->fd = (*a)->fd;
		*a = (*a)->fg;
	}
	else if ((*a)->fg)
		*a = (*a)->fg;
	else if ((*a)->fd)
		*a = (*a)->fd;
	else
		*a = NULL;
	return (ret);
}
