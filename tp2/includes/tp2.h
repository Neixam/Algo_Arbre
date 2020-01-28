#ifndef TP2_H
# define TP2_H
# include <stdlib.h>
# include <stdio.h>

typedef struct	noeud
{
	int 			valeur;
	struct noeud	*fg;
	struct noeud	*fd;
}				Noeud,
				*Arbre;

Arbre			alloueNoeud(int val);
int				hauteur(Arbre a);
int				nb_noeud(Arbre a);
int				nb_interne(Arbre a);
int				nb_feuille(Arbre a);
int				nb_interne_2f(Arbre a);
int				est_strict_bin(Arbre a);
int				est_nombre(int c);
int				creation_arbre(Arbre *a, FILE *file);

#endif
