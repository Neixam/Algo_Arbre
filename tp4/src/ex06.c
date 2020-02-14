#include "tp4.h"

void    creePDF(char *dot, char *pdf, Arbre a)
{
    FILE    *out;
    char    *cmd;

    out = fopen(dot, "w");
    dessine(out, a);
    fclose(out);
    cmd = ft_strjoin("dot -Tpdf ", dot, 0);
    cmd = ft_strjoin(cmd, " -o ", 1);
    cmd = ft_strjoin(cmd, pdf, 1);
    system(cmd);
    free(cmd);
}
