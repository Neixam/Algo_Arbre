#include "tp4.h"

int     main(int ac, char **av)
{
    Dess    data;
    Arbre   a = NULL;

    init_data(&data);
    parseur_entrer(ac, av, &data);
    creePDF("visualise.dot", "visualise.pdf", a);
    system("evince visualise.pdf &");
    if (genere_arbre(&a, data.in, &a))
        return (1);
    fclose(data.in);
    return (0);
}
