#include "tp2.h"

int		construireArbreQuelconque(Arbre *a, FILE *in)
{
	int     chr;
    int     test;
    int     val;

    for (chr = getc(in); chr != EOF; chr = getc(in))
    {
        if (est_nombre(chr))
        {
            for (test = 0; chr != EOF && est_nombre(chr); chr = getc(in))
                test = (test * 10) + (chr - '0');
            chr = getc(in);
            for (val = 0; chr != EOF && est_nombre(chr); chr = getc(in))
                val = (val * 10) + (chr - '0');
            if ((*a = alloueNoeud(val)) == NULL)
                return (0);
            if (test == 0)
                return (1);
            if (test == 1)
                return (construireArbreQuelconque(&((*a)->fd), in));
            if (test == 2)
                return (construireArbreQuelconque(&((*a)->fg), in));
            return (construireArbreQuelconque(&((*a)->fg), in) &&
                    construireArbreQuelconque(&((*a)->fd), in));
        }
    }
    return (1);
}
