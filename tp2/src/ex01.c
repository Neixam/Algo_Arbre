#include "tp2.h"

Arbre	alloueNoeud(int val)
{
	Arbre	ret;

	if (!(ret = (Arbre)malloc(sizeof(Noeud))))
		return (NULL);
	ret->valeur = val;
	ret->fg = NULL;
	ret->fd = NULL;
	return (ret);
}
