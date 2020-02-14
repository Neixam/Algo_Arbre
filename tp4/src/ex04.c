#include "tp4.h"

void    dessine(FILE *f, Arbre a)
{
    ecrireDebut(f);
    ecrireArbre(f, a);
    ecrireFin(f);
}
