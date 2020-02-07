#ifndef TP3_H
# define TP3_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct  recherche
{
    int     err_val;
    FILE    *fichier;
    char    f_nom[17];
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
int		verif_bin_rech(Arbre a);
int     ajout(Arbre *a, int n);
int     genereArbre(Arbre *a, FILE *entrer);
void    init_data(Rech *data);
void    libere_data(Rech *data);
void	libereArbre(Arbre a);

#endif
