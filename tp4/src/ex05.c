#include "tp4.h"

int     ft_strlen(char *s)
{
    int     len;

    for (len = 0; s[len]; len++);
    return (len);
}

int     est_chiffre(int c)
{
    if (c <= '9' && c >= '0')
        return (1);
    return (0);
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

void    init_data(Dess *data)
{
    data->in = NULL;
}

int     parseur_entrer(int ac, char **av, Dess *data)
{
    assert(ac == 2);
    data->in = fopen(av[1], "r");
    assert(data->in != NULL);
    return (1);
}

Arbre   alloueNoeud(int val)
{
    Arbre   ret;

    if (!(ret = (Arbre)malloc(sizeof(Noeud))))
        return (NULL);
    ret->val = val;
    ret->fg = NULL;
    ret->fd = NULL;
    return (ret);
}

int     genere_arbre(Arbre *a, FILE *in, Arbre *racine)
{
    int     chr;
    int     val;

    creePDF("visualise.dot", "visualise.pdf", *racine);
    for (chr = getc(in); chr != EOF; chr = getc(in))
    {
        if (est_chiffre(chr))
        {
            for (val = 0; chr != EOF && est_chiffre(chr); chr = getc(in))
                val = val * 10 + (chr - '0');
            if (val == 0)
                return (0);
            if (!(*a = alloueNoeud(val)))
                return (1);
            printf("Press enter");
            getchar();
            return (genere_arbre(&((*a)->fg), in, racine) ||
                    genere_arbre(&((*a)->fd), in, racine));
        }
    }
    return (0);
}
