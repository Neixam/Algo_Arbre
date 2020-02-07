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
	Arbre	tmp1;
	Rech	data;
	int		i;
	int		ret;

	strcpy(data.f_nom, "arbresTP2/arbre1");
	for (i = 0; i < 8; i++)
	{
		if (!(data.fichier = fopen(data.f_nom, "r")))
		{
			data.err_val = 3;
			return (affiche_err(data));
		}
		if (genereArbre(&a, data.fichier))
		{
			data.err_val = 2;
			return (affiche_err(data));
		}
		fclose(data.fichier);
		ret = verif_bin_rech(a);
		printf("%s : %s.\n", data.f_nom, (ret) ? "est binaire de recherche" : "n'est pas binaire de recherche");
		if (ret)
		{
			tmp = Recherche(a, 25);
			if (!tmp)
				printf("\t25 n'est pas dans l'arbre\n");
			else
			{
				printf("\t25 est dans l'arbre\n");
				tmp = extrait(&a, 25);
				if (tmp)
				{
					printf("\t%d n'est plus dans l'arbre\n", tmp->val);
					free(tmp);
				}
			}
			tmp1 = extraitMax(&a);
			tmp = extraitMin(&a);
			if (tmp)
			{
				printf("\t%d était la valeur minimal de l'arbre\n", tmp->val);
				if (ajout(&a, tmp->val) == 0)
					printf("\t%d est déjà dans l'arbre\n", tmp->val);
				else
					printf("\t%d est de nouveau la valeur minimal de l'arbre\n", tmp->val);
				free(tmp);
			}
			if (tmp1)
			{
				printf("\t%d était la valeur maximal de l'arbre\n", tmp1->val);
				if (ajout(&a, tmp1->val) == 0)
					printf("\t%d est déjà dans l'arbre\n", tmp1->val);
				else
					printf("\t%d est de nouveau la valeur maximal de l'arbre\n", tmp1->val);
				free(tmp1);
			}
		}
		libereArbre(a);
		data.f_nom[15]++;
	}
	return (0);
}
