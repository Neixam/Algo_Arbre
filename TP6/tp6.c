#define PERE 0
#define RANG 1
#define N 256
#define M 2048
#define O 200
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static unsigned int     cherchePere = 0;

void    Initialisation(int peres[][2])
{
    int     i;

    for (i = 0; i < N; i++)
    {
        peres[i][PERE] = i;
        peres[i][RANG] = 1;
    }
}

int     TrouveNaif(int peres[][2], int x)
{
    int     i;

    cherchePere++;
    for (i = x; peres[i][PERE] != i; i = peres[i][PERE])
        cherchePere++;
    return (i);
}

void    affiche_ta_merde(int peres[][2])
{
    int     i;

    for (i = 0; i < N; i++)
        printf("%2d | ", peres[i][PERE]);
    printf("\n");
    for (i = 0; i < N; i++)
        printf("%2d | ", peres[i][RANG]);
    printf("\n\n");
}

void    FusionNaive(int peres[][2], int x, int y)
{
    if (TrouveNaif(peres, x) == TrouveNaif(peres, y))
        return ;
    peres[y][PERE] = x;
}

int     TrouveCompresse(int peres[][2], int x)
{
    cherchePere++;
    if (peres[x][PERE] != x)
        peres[x][PERE] = TrouveCompresse(peres, peres[x][PERE]);
    return (peres[x][PERE]);
}

void    FusionRang(int peres[][2], int x, int y)
{
    int     pere_x;
    int     pere_y;
    int     rang_tot;
    int     i;

    if ((pere_x = TrouveCompresse(peres, x)) == (pere_y = TrouveCompresse(peres, y)))
        return ;
    rang_tot = peres[x][RANG] + peres[y][RANG];
    if (peres[x][RANG] < peres[y][RANG])
    {
        for (i = 0; i < N; i++)
        {
            if (pere_x == peres[i][PERE])
            {
                peres[i][PERE] = pere_y;
                peres[i][RANG] = rang_tot;
            }
            if (pere_y == peres[i][PERE])
                peres[i][RANG] = rang_tot;
        }
    }
    if (peres[x][RANG] >= peres[y][RANG])
    {
        for (i = 0; i < N; i++)
        {
            if (pere_y == peres[i][PERE])
            {
                peres[i][PERE] = pere_x;
                peres[i][RANG] = rang_tot;
            }
            if (pere_x == peres[i][PERE])
                peres[i][RANG] = rang_tot;
        }
    }
}

void    ecritDebut(FILE *out)
{
    fprintf(out, "set terminal pdfcairo\nset xrange[0:3]\nset yrange[0:%d]\n",
            (M / N == 0 && N > 100) ? 5 : 5 * (M / N));
    fprintf(out, "set xtics (\"Naif\" 1, \"Compresse\" 2)\nset xlabel \"Methode\"\n");
    fprintf(out, "set ylabel \"Moyenne d'iteration (sur %d essais)\"\nplot \"-\" using 1:2 notitle with boxes\n", O);
    fprintf(out, "#\tX\tY\n");
}

void    ecritMoy(FILE *out, double moy1, double moy2)
{
    fprintf(out, "1.0\t%.1f\n2.0\t%.1f\n", moy1, moy2);
}


double  moyenneTab(int *tab, int taille)
{
    int     i;
    double  ret;

    ret = 0.;
    for (i = 0; i < taille; i++)
        ret += tab[i];
    ret /= taille;
    return (ret);
}

void    ecritFichier(FILE *out, int stats[][O])
{
    double  moyenne_N;
    double  moyenne_C;

    moyenne_N = moyenneTab(stats[0], O);
    moyenne_C = moyenneTab(stats[1], O);
    ecritDebut(out);
    ecritMoy(out, moyenne_N, moyenne_C);
    fclose(out);
}

int     traite_info(int stats[][O])
{
    FILE    *data;

    if (!(data = fopen(".data.plt", "w")))
        return (1);
    ecritFichier(data, stats);
    system("gnuplot .data.plt > .print.pdf");
    system("evince .print.pdf &");
    return (0);
}

int     main(void)
{
    int     i;
    int     j;
    int     tmp_x;
    int     tmp_y;
    int     peresNaif[N][2];
    int     peres[N][2];
    int     stats[2][O];

    srand(time(NULL));
    for (j = 0; j < O; j++)
    {
        Initialisation(peresNaif);
        Initialisation(peres);
        for (i = 0; i < M; i++)
        {
            tmp_x = rand() % N;
            tmp_y = rand() % N;
            FusionNaive(peresNaif, tmp_x, tmp_y);
            FusionRang(peres, tmp_x, tmp_y);
        }
        cherchePere = 0;
        TrouveNaif(peresNaif, 4);
        stats[0][j] = cherchePere;
        cherchePere = 0;
        TrouveCompresse(peres, 4);
        stats[1][j] = cherchePere;
    }
    if (traite_info(stats))
        return (1);
    return (0);
}
