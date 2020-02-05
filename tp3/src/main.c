#include "tp3.h"

void	affiche_arbre(Arbre a, int g, int d)
{
	if (a == NULL)
		return ;
	printf("%d %d %d\n",g, d, a->val);
	affiche_arbre(a->fg, g + 1, d);
	affiche_arbre(a->fd, g, d + 1);
}

int		main(int ac, char **av)
{
	Arbre	a;
	Arbre	tmp;

	a = NULL;
	printf("%d %d\n", 12, ajout(&a, 12));
	printf("%d %d\n", 7, ajout(&a, 7));
	printf("%d %d\n", 24, ajout(&a, 24));
	printf("%d %d\n", 12, ajout(&a, 12));
	printf("%d %d\n", 13, ajout(&a, 13));
	printf("%d %d\n", 15, ajout(&a, 15));
	printf("%d %d\n", 24, ajout(&a, 24));
	printf("%d %d\n", 37, ajout(&a, 37));
	printf("%d %d\n", 6, ajout(&a, 6));
	printf("%d %d\n", 1, ajout(&a, 1));
	printf("%d %d\n", 45, ajout(&a, 45));
	printf("%d %d\n", 45, ajout(&a, 45));
	printf("%d %d\n", 5, ajout(&a, 5));
	tmp = Recherche(a, 12);
	if (tmp != NULL)
		printf("val = %d\n", tmp->val);
	else
		printf("NULL\n");
	affiche_arbre(a, 0, 0);
	tmp = extraitMin(&a);
	if (tmp != NULL)
		printf("min %d\n", tmp->val);
	else
		printf("NULL\n");
	affiche_arbre(a, 0, 0);
	tmp = extraitMax(&a);
	if (tmp != NULL)
		printf("max %d\n", tmp->val);
	else
		printf("NULL\n");
	affiche_arbre(a, 0, 0);
	tmp = extrait(&a, 12);
	if (tmp != NULL)
		printf("extrait %d\n", tmp->val);
	else
		printf("NULL\n");
	tmp = extrait(&a, 25);
	if (tmp != NULL)
		printf("extrait %d\n", tmp->val);
	else
		printf("NULL\n");
	affiche_arbre(a, 0, 0);
	return (0);
}
