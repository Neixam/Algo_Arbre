#include "tp3.h"

void	libereArbre(Arbre a)
{
	if (a == NULL)
		return ;
	libereArbre(a->fg);
	libereArbre(a->fd);
	free(a);
}

int		est_chiffre(int c)
{
	return (c <= '9' && c >= '0');
}

int		genereArbre(Arbre *a, FILE *entrer)
{
	int		chr;
	int		val;

	for (chr = getc(entrer); chr != EOF; chr = getc(entrer))
	{
		if (est_chiffre(chr))
		{
			for (val = 0; chr != EOF && est_chiffre(chr); chr = getc(entrer))
				val = val * 10 + (chr - '0');
			if (val == 0)
				return (0);
			if (!(*a = alloueNoeud(val)))
				return (1);
			return (genereArbre(&((*a)->fg), entrer) ||
					genereArbre(&((*a)->fd), entrer));
		}
	}
	return (0);
}
