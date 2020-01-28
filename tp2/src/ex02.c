#include "tp2.h"

int		hauteur(Arbre a)
{
	int		g;
	int		d;

	if (a == NULL)
		return (0);
	return (1 + ((g = hauteur(a->fg)) >= (d = hauteur(a->fd)) ? g : d));
}

int		nb_noeud(Arbre a)
{
	if (a == NULL)
		return (0);
	return (1 + nb_noeud(a->fg) + nb_noeud(a->fd));
}

int		nb_interne(Arbre a)
{
	if (a == NULL)
		return (0);
	if (!(a->fd) && !(a->fg))
		return (0);
	return (1 + nb_interne(a->fg) + nb_interne(a->fd));
}

int		nb_feuille(Arbre a)
{
	if (a == NULL)
		return (0);
	if (!(a->fd) && !(a->fg))
		return (1);
	return (nb_feuille(a->fg) + nb_feuille(a->fd));
}

int		nb_interne_2f(Arbre a)
{
	if (a == NULL)
		return (0);
	if (!(a->fd) && !(a->fg))
		return (0);
	if (!a->fd)
		return (nb_interne_2f(a->fg));
	if (!a->fg)
		return (nb_interne_2f(a->fg));
	return (1 + nb_interne_2f(a->fg) + nb_interne_2f(a->fd));
}
