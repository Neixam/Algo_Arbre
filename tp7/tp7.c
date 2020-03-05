/* Auteur       : Bourennane Amine
*  Creation     : 04-03-2020
*  Modification : 04-03-2020   */
#include <stdio.h>
#define N 4
#define LIMIT 7
#define __QE__

void    affiche_tab(int *tab, int n)
{
    int     i;

    for (i = 0; i < n; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

int     estTas(int *tab, int taille)
{
    int     i;

    for (i = 1; i < taille; i++)
    {
        if (tab[i] < tab[(i - 1) / 2])
            return (0);
    }
    return (1);
}

int     enumPermutation(int *tab, int premier, int n)
{
    int     i;
    int     nb_permu;

    if (premier > n)
        return (1);
    nb_permu = 0;
    for (i = 0; i < n; i++)
    {
        if (!tab[i])
        {
            tab[i] = premier;
            nb_permu += enumPermutation(tab, premier + 1, n);
            tab[i] = 0;
        }
    }
    return (nb_permu);
}

int     enumTasNaif(int *tab, int premier, int n)
{
    int     i;
    int     nb_tas;

    if (premier > n)
    {
        if (estTas(tab, n))
        {
            if (n < LIMIT)
                affiche_tab(tab, n);
            return (1);
        }
        return (0);
    }
    nb_tas = 0;
    for (i = 0; i < n; i++)
    {
        if (!tab[i])
        {
            tab[i] = premier;
            nb_tas += enumTasNaif(tab, premier + 1, n);
            tab[i] = 0;
        }
    }
    return (nb_tas);
}

int     estTasPartiel(int *tab, int n)
{
    int     i;

    for (i = 0; i < n; i++)
        if (i >= tab[i] && tab[i] != 0)
            return (0);
    return (1);
}

#ifndef __QE__

int     enumTas(int *tab, int premier, int n)
{
    int     i;
    int     nb_tas;

    if (!estTasPartiel(tab, n))
        return (0);
    if (premier > n)
    {
        if (n < LIMIT)
            affiche_tab(tab, n);
        return (1);
    }
    nb_tas = 0;
    for (i = 0; i < n; i++)
    {
        if (!tab[i])
        {
            tab[i] = premier;
            nb_tas += enumTasNaif(tab, premier + 1, n);
            tab[i] = 0;
        }
    }
    return (nb_tas);
}

#endif
#ifdef __QE__

int     enumTas(int *tab, int premier, int n)
{
    int     i;
    int     nb_tas;

    if (premier > n)
    {
        if (n < LIMIT)
            affiche_tab(tab, n);
        return (1);
    }
    nb_tas = 0;
    for (i = 0; i < n; i++)
    {
        if (!tab[i] && (i == 0 || !tab[(i - 1) / 2]))
        {
            tab[i] = premier;
            nb_tas += enumTasNaif(tab, premier + 1, n);
            tab[i] = 0;
        }
    }
    return (nb_tas);
}

#endif

/* 2/ d)
    Il aurait été plus pratique de représenter les cases vides par la valeur n+1
    car on doit ignorer les cases vides et dans le cas des cases vides à 0 on
    doit gérer le cas dans la condition tandis que si c'était n+1 il aurait été
    ignorer automatiquement dans la condition principale.

      e)
    Car on placerai que si la case est vide et que c'est la première case ou
    bien que le noeud supérieur existe déjà.

      f)
    La valeur maximum de n que l'on peut traiter en 1 minute est 12
*/

int     main(void)
{
    int tab[N] = {0};

    printf("%d\n", enumPermutation(tab, 1, N));
    printf("%d\n", enumTasNaif(tab, 1, N));
    printf("%d\n", enumTas(tab, 1, N));
    return (0);
}


