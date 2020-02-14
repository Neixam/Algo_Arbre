#ifndef __TP3__
# define __TP3__
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>

typedef struct  ecrire
{
    FILE    *in;
}               Dess;

typedef struct  arbre
{
    int             val;
    struct arbre    *fd;
    struct arbre    *fg;
}               Noeud,
                *Arbre;

void    init_data(Dess *data);
void    ecrireDebut(FILE *f);
void    ecrireArbre(FILE *f, Arbre a);
void    creePDF(char *dot, char *pdf, Arbre a);
void    ecrireFin(FILE *f);
void    dessine(FILE *f, Arbre a);
int     parseur_entrer(int ac, char **av, Dess *data);
int     genere_arbre(Arbre *a, FILE *in, Arbre *racine);
char    *ft_strjoin(char *s1, char *s2, int boo);

#endif
