#ifndef TP3_H
# define TP3_H
# include <stdlib.h>
# include <stdio.h>

typedef struct  recherche
{
    int     err_val;
    FILE    *fichier;
    char    *f_nom;
}               Rech;

typedef struct  noeud
{
    int             val;
    struct noeud    *fg;
    struct noeud    *fd;
}               Noeud,
                *Arbre;

Arbre   alloueNoeud(int n);
Arbre   extraitMin(Arbre *a);
Arbre   extraitMax(Arbre *a);
Arbre   extrait(Arbre *a, int n);
Arbre   Recherche(Arbre a, int n);
int     affiche_err(Rech data);
int     ajout(Arbre *a, int n);
void    init_data(Rech *data);
void    libere_data(Rech *data);

#endif
