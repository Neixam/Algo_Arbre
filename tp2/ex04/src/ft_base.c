#include "tp2.h"

int 	ft_strlen(char *s)
{
	int		len;

	for (len = 0; s[len]; len++);
	return (len);
}

char	*ft_strdup(char *s)
{
	char	*ret;
	int		i;
	int		len;

	len = ft_strlen(s);
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	for (i = 0; i < len; i++)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

char    *ft_strjoin(char *s1, char *s2, int boo)
{
    int     i;
    int     j;
    int     len;
    char    *ret;

    len = ft_strlen(s1) + ft_strlen(s2);
    if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    for (i = 0; s1[i]; i++)
        ret[i] = s1[i];
    for (j = 0; i + j < len; j++)
        ret[i + j] = s2[j];
    ret[i + j] = '\0';
    if (boo == 1 || boo == 3)
        free(s1);
    if (boo > 1)
        free(s2);
    return (ret);
}

int     parsing_enter(int ac, char **av, Qlc *data)
{
    if (ac != 2)
        return (1);
    if ((data->in_name = ft_strdup(av[1])) == NULL)
        return (2);
    if ((data->in = fopen(data->in_name, "r")) == NULL)
        return (3);
    if ((data->out_name = ft_strjoin(data->in_name, "-new", 0)) == NULL)
        return (2);
    if ((data->out = fopen(data->out_name, "w")) == NULL)
        return (4);
    return (0);
}

int     put_error(Qlc data)
{
    if (data.error_val == 1)
        fprintf(stderr, "Bad usage :\n./exercice4 \"file\"\n");
    if (data.error_val == 2)
        fprintf(stderr, "Error allocation failed\n");
    if (data.error_val == 3)
        fprintf(stderr, "Error file %s doesn't exist\n", data.in_name);
    if (data.error_val == 4)
        fprintf(stderr, "Error you don't have permission to write in file %s\n", data.out_name);
    return (1);
}

void	init_data(Qlc *data)
{
	data->in = NULL;
	data->out = NULL;
	data->in_name = NULL;
	data->out_name = NULL;
	data->qlc = NULL;
	data->error_val = 0;
}

void    freeArbre(Arbre a)
{
    if (a == NULL)
        return ;
    freeArbre(a->fg);
    freeArbre(a->fd);
    free(a);
}

void	free_data(Qlc *data)
{
    if (data->out != NULL)
        fclose(data->out);
    if (data->in != NULL)
        fclose(data->in);
    if (data->in_name != NULL)
        free(data->in_name);
    if (data->out_name != NULL)
        free(data->out_name);
    if (data->qlc != NULL)
        freeArbre(data->qlc);
}
