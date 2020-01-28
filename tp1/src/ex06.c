#include "tp1.h"

int		nb_mot_in_lst(ListeM lst)
{
	int		nb_mot;

	for (nb_mot = 0; lst; lst = lst->suivant)
		nb_mot += lst->nombre;
	return (nb_mot);
}

int		NombreMot(ListeM *T, int len)
{
	int		i;
	int		nb_mot;

	nb_mot = 0;
	for (i = 0; i < len; i++)
		nb_mot += nb_mot_in_lst(T[i]);
	return (nb_mot);
}
