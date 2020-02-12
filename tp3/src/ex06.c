#include "tp3.h"

int		est_bin_rech(Arbre a, int max, int min)
{
	if (a == NULL)
		return (1);
    if (a->val < min || a->val > max)
        return (0);
    if (!a->fg && !a->fd)
        return (1);
    return (est_bin_rech(a->fg, a->val - 1, min) &&
            est_bin_rech(a->fd, max, a->val + 1));
}

int     verif_bin_rech(Arbre a)
{
	if (a == NULL)
		return (1);
    return (est_bin_rech(a, a->val, a->val));
}
