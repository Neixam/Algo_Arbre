#include "tp2.h"
/*
void	affiche_arbre(Arbre a)
{

	if (a == NULL)
	{
		printf("0 ");
		return ;
	}
	printf("%d ", a->valeur);
	affiche_arbre(a->fg);
	affiche_arbre(a->fd);
}*/

int		main(int ac, char **av)
{
	FILE	*file;
	Arbre	a;

	a = NULL;
	if (ac != 2)
		return (1);
	if ((file = fopen(av[1], "r")) == NULL)
		return (2);
	if (creation_arbre(&a, file))
		return (3);
	printf("h = %d\nn = %d\ni = %d\nf = %d\ni2 = %d\n%d\n", hauteur(a), nb_noeud(a), nb_interne(a), nb_feuille(a), nb_interne_2f(a), est_strict_bin(a));
	return (0);
}
