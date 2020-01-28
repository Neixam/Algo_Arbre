#include "tp1.h"

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
	return (s1[i] - s2[i]);
}

int		AjouteListe(ListeM *lst, char *mot)
{
	ListeM	tmp;
	ListeM	tmp2;
	int		test;

	if (!(*lst))
	{
		if (!(*lst = AlloueCellule(mot)))
			return (0);
		return (1);
	}
	if ((test = ft_strcmp((*lst)->mot, mot)) >= 0)
	{
		if (test == 0)
		{
			(*lst)->nombre++;
			return (1);
		}
		tmp = *lst;
		if (!(*lst = AlloueCellule(mot)))
		{
			*lst = tmp; 
			return (0);
		}
		(*lst)->suivant = tmp;
		return (1);
	}
	for (tmp = *lst; (*lst)->suivant; (*lst) = (*lst)->suivant)
	{
		if ((test = ft_strcmp((*lst)->suivant->mot, mot)) >= 0)
		{
			tmp2 = (*lst)->suivant;
			if (test == 0)
			{
				tmp2->nombre++;
				*lst = tmp;
				return (1);
			}
			if (!((*lst)->suivant = AlloueCellule(mot)))
			{
				*lst = tmp;
				return (0);
			}
			(*lst)->suivant->suivant = tmp2;
			*lst = tmp;
			return (1);
		}
	}
	if (!((*lst)->suivant = AlloueCellule(mot)))
	{
		*lst = tmp;
		return (0);
	}
	*lst = tmp;
	return (1);
}
