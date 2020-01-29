#include "tp2.h"

void    affiche_arbre(Arbre a)
{
    if (a == NULL)
        return ;
    printf("%d ", a->valeur);
    affiche_arbre(a->fg);
    affiche_arbre(a->fd);
}

int		main(int ac, char **av)
{
	Qlc		data;
    Arbre   a;

	init_data(&data);
	if ((data.error_val = parsing_enter(ac, av, &data)))
		return (put_error(data));
    if (construireArbreQuelconque(&data.qlc, data.in) == 0)
    {
        data.error_val = 2;
        free_data(&data);
        return (put_error(data));
    }
    rewind(data.in);
    if (creation_arbre(&a, data.in))
    {
        data.error_val = 2;
        free_data(&data);
        freeArbre(a);
        return (put_error(data));
    }
    if (ecritArbreQuelconque(a, data.out) == 0)
    {
        data.error_val = 4;
        return (put_error(data));
    }
    fprintf(data.out, "\n");
    free_data(&data);
    freeArbre(a);
	return (0);
}
