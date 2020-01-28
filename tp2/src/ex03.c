#include "tp2.h"

int		est_nombre(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int		est_strict_bin(Arbre a)
{
	if (a == NULL)
		return (0);
	if (!a->fd && !a->fg)
		return (1);
	return (est_strict_bin(a->fd) && est_strict_bin(a->fg));
}

int		creation_arbre(Arbre *a, FILE *file)
{
	int		chr;
	int		val;

	for (chr = getc(file); chr != EOF; chr = getc(file))
	{
		if (est_nombre(chr))
		{
			for (val = 0; chr != EOF && est_nombre(chr); chr = getc(file))
				val = (val * 10) + (chr - '0');
			if (val == 0)
				return (0);
			if ((*a = alloueNoeud(val)) == NULL)
				return (1);
			return (creation_arbre(&((*a)->fg), file) || creation_arbre(&((*a)->fd), file));
		}
	}
	return (0);
}
