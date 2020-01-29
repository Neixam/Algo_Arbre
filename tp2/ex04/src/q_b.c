#include "tp2.h"

int     ecritArbreQuelconque(Arbre a, FILE *out)
{
    if (a == NULL)
        return (1);
    if (a->fd && a->fg)
    {
        if (fprintf(out, "3 %d ", a->valeur) < 0)
            return (0);
    }
    else if (a->fd)
    {
        if (fprintf(out, "1 %d ", a->valeur) < 0)
            return (0);
    }
    else if (a->fg)
    {
        if (fprintf(out, "2 %d ", a->valeur) < 0)
            return (0);
    }
    else
        if (fprintf(out, "0 %d ", a->valeur) < 0)
            return (0);
    return (ecritArbreQuelconque(a->fg, out) &&
            ecritArbreQuelconque(a->fd, out));
}
