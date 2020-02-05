#include "tp3.h"

Arbre	alloueNoeud(int n)
{
	Arbre	nouveau;

	if (!(nouveau = (Arbre)malloc(sizeof(Noeud))))
		return (NULL);
	nouveau->val = n;
	nouveau->fg = NULL;
	nouveau->fd = NULL;
	return (nouveau);
}

Arbre	Recherche(Arbre a, int n)
{
	if (a == NULL)
		return (NULL);
	if (a->val == n)
		return (a);
	if (a->val > n)
		return (Recherche(a->fg, n));
	return (Recherche(a->fd, n));
}
