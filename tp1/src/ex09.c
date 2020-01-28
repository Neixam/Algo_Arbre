#include "tp1.h"

void	tab_info(Compte data)
{
	int		count_null;
	int		i;
	int		count;
	int		count_max;
	ListeM	tmp;
	double	avg_no_null;

	count_null = 0;
	count_max = 0;
	avg_no_null = 0.;
	for (i = 0; i < data.len_twd; i++)
	{
		if (data.tab_wd[i] == NULL)
			count_null++;
		count = 0;
		for (tmp = data.tab_wd[i]; tmp; tmp = tmp->suivant)
			count++;
		if (count > count_max)
			count_max = count;
		avg_no_null += count;
	}
	avg_no_null = avg_no_null / (data.len_twd - count_null);
	fprintf(data.file_wr, "Nombre de liste vide : %d\nTaille maximal des listes %d\
\nMoyenne des tailles des listes non vide %f\n", count_null, count_max, avg_no_null);
}
