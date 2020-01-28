#ifndef TP2_H
# define TP2_H

typedef struct	noeud
{
	int 			valeur;
	struct noeud	*fg;
	struct noeud	*fd;
}				Noeud,
				*Arbre;

Arbre			alloueNoeud(int val);


#endif
