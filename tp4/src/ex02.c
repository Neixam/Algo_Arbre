#include "tp4.h"

void    ecrireArbre(FILE *f, Arbre a)
{
    if (a == NULL)
        return ;
    fprintf(f, "\n\tn%p [label=\"<gauche> | <valeur> %d | <droit>\"];", (void*)a, a->val);
    if (a->fg)
    {
        fprintf(f, "\n\tn%p:gauche:c -> n%p:valeur;", (void*)a, (void*)a->fg);
        ecrireArbre(f, a->fg);
    }
    if (a->fd)
    {
        fprintf(f, "\n\tn%p:droit:c -> n%p:valeur;", (void*)a, (void*)a->fd);
        ecrireArbre(f, a->fd);
    }
}
