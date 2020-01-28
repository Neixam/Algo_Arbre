#ifndef TP1_H
# define TP1_H
# include <stdlib.h>
# include <stdio.h>

typedef struct	celmot
{
	char			*mot;
	int				nombre;
	struct celmot	*suivant;
}				CelluleM,
				*ListeM;

typedef struct	compte
{
	char	*file_nm;
	char	*cpt_nm;
	FILE	*file_rd;
	FILE	*file_wr;
	ListeM	*tab_wd;
	int		error_val;
	int		len_twd;
}				Compte;

ListeM			AlloueCellule(char *mot);
int				AjouteListe(ListeM *lst, char *mot);
int				AjouteDico(ListeM *T, char *mot, int len);
unsigned int	hachage(char *mot);
unsigned int	hach_1(char *mot);
unsigned int	hach_2(char *mot);
int				ft_strcmp(char *s1, char *s2);
int				RechercheDico(ListeM *T, char *mot, int len);
int				NombreMot(ListeM *T, int len);
int				parsing_enter(int ac, char **av, Compte *data);
int				put_error(Compte data);
int				count_word(Compte data);
char			*ft_strdup(char *s1);
void			init_data(Compte *data);
void			free_data(Compte *data);
void			tab_info(Compte data);

#endif
