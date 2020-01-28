#include "tp1.h"

void	init_data(Compte *data)
{
	data->file_nm = NULL;
	data->cpt_nm = NULL;
	data->file_rd = NULL;
	data->file_wr = NULL;
	data->tab_wd = NULL;
	data->error_val = 0;
}

void	free_lstM(ListeM lst)
{
	if (lst == NULL)
		return ;
	free_lstM(lst->suivant);
	free(lst->mot);
	free(lst);
	lst = NULL;
}

void	free_tabM(ListeM *tab, int len)
{
	int		i;

	for (i = 0; i < len; i++)
		free_lstM(tab[i]);
	free(tab);
}

void	free_data(Compte *data)
{
	if (data->file_nm != NULL)
		free(data->file_nm);
	if (data->cpt_nm != NULL)
		free(data->cpt_nm);
	if (data->file_rd != NULL)
		fclose(data->file_rd);
	if (data->file_wr != NULL)
		fclose(data->file_wr);
	if (data->tab_wd != NULL)
		free_tabM(data->tab_wd, data->len_twd);
}

int		put_error(Compte data)
{
	switch (data.error_val)
	{
		case 1 : fprintf(stderr, "bad argument\n./Compte \"file name\"\
 \"new file name\"\n");
				return (1);
		case 2 : fprintf(stderr, "Error allocation\n");
				return (1);
		case 3 : fprintf(stderr, "Error %s doesn't exist\n", data.file_nm);
				return (1);
		case 4 : fprintf(stderr, "Error you can not write in %s\n", data.cpt_nm);
				return (1);
		default : return (1);
	}
}

int		parsing_enter(int ac, char **av, Compte *data)
{
	if (ac != 3)
		return (1);
	if ((data->file_nm = ft_strdup(av[1])) == NULL)
		return (2);
	if ((data->cpt_nm = ft_strdup(av[2])) == NULL)
		return (2);
	if ((data->file_rd = fopen(data->file_nm, "r")) == NULL)
		return (3);
	if ((data->file_wr = fopen(data->cpt_nm, "w")) == NULL)
		return (4);
	return (0);
}

int		is_word_cnt(int c, int i)
{
	if ((c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z') ||
		(c == '\'' && i != 0) ||
		(c == '-' && i != 0))
		return (1);
	return (0);
}

int		create_tab_wd(Compte *data)
{
	int		len;
	int		chr;
	int		i;

	len = 0;
	for (chr = getc(data->file_rd); chr != EOF; chr = getc(data->file_rd))
	{
		if (is_word_cnt(chr, 0))
		{	
			for (; chr != EOF && is_word_cnt(chr, 1);
				chr = getc(data->file_rd));
			len++;
		}
	}
	rewind(data->file_rd);
	if (!(data->tab_wd = (ListeM*)malloc(sizeof(ListeM) * len)))
		return (1);
	for (i = 0; i < len; i++)
		data->tab_wd[i] = NULL;
	data->len_twd = len;
	return (0);
}

int		count_word(Compte data)
{
	char	word[50];
	ListeM	tmp;
	int		i;
	int		chr;

	if (create_tab_wd(&data))
	{
		free_data(&data);
		return (2);
	}
	for (chr = getc(data.file_rd); chr != EOF; chr = getc(data.file_rd))
	{
		if (is_word_cnt(chr, 0))
		{
			for (i = 0; chr != EOF && is_word_cnt(chr, 1);
				chr = getc(data.file_rd))
			{
				word[i] = chr;
				i++;
			}
			word[i] = '\0';
			if (AjouteDico(data.tab_wd, word, data.len_twd) == 0)
			{
				free_data(&data);
				return (2);
			}
		}
	}
	for (i = 0; i < data.len_twd; i++)
		for (tmp = data.tab_wd[i]; tmp; tmp = tmp->suivant)
			fprintf(data.file_wr, "%s %d\n", tmp->mot, tmp->nombre);
	tab_info(data);
	free_data(&data);
	return (0);
}
