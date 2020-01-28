#include "tp1.h"

int		AjouteDico(ListeM *T, char *mot, int len)
{
	return (AjouteListe(&T[hachage(mot) % len], mot));
/* Commentez le premier return pour tester les autres fonctions de hachage.   */
	return (AjouteListe(&T[hach_1(mot) % len], mot));  
	return (AjouteListe(&T[hach_2(mot) % len], mot));
}
