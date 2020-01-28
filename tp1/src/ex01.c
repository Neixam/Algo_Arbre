#include "tp1.h"

int		ft_strlen(char *s)
{
	int		len;

	for (len = 0; s[len]; len++);
	return (len);
}

char	*ft_strdup(char *s)
{
	int		len;
	int		i;
	char 	*ret;

	len = ft_strlen(s);
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	for (i = 0; i < len; i++)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

ListeM	AlloueCellule(char *mot)
{
	ListeM	ret;

	if (!(ret = (ListeM)malloc(sizeof(CelluleM))))
		return (NULL);
	if ((ret->mot = ft_strdup(mot)) == NULL)
	{
		free(ret);
		return (NULL);
	}
	ret->nombre = 1;
	ret->suivant = NULL;
	return (ret); 
}
