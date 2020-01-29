#ifndef TP2_H
# define TP2_H
# include <stdlib.h>
# include <stdio.h>

typedef struct	noeud
{
	int 		    valeur;
	struct noeud	*fg;
	struct noeud	*fd;
}               Noeud,
		        *Arbre;

typedef struct	quelconque
{
	FILE	*in;
	FILE	*out;
	Arbre	qlc;
	char	*in_name;
	char	*out_name;
	int	    error_val;
}		        Qlc;

Arbre			alloueNoeud(int val);
char			*ft_strdup(char *s);
int 			ft_strlen(char *s);
int 			hauteur(Arbre a);
int 			nb_noeud(Arbre a);
int 			nb_interne(Arbre a);
int 			nb_feuille(Arbre a);
int 			nb_interne_2f(Arbre a);
int 			est_strict_bin(Arbre a);
int	    		est_nombre(int c);
int	    		creation_arbre(Arbre *a, FILE *file);
int	    		construireArbreQuelconque(Arbre *a, FILE *in);
int             ecritArbreQuelconque(Arbre a, FILE *out);
int	    		parsing_enter(int ac, char **av, Qlc *data);
int             put_error(Qlc data);
void			init_data(Qlc *data);
void			free_data(Qlc *data);
void			freeArbre(Arbre a);

#endif
