#include "tp4.h"

void    ecrireDebut(FILE *f)
{
    assert(f != NULL);
    fprintf(f, "digraph arbre {\n\tnode [shape=record, height=.1]\n\tedge \
[tailclip=false, arrowtail=dot, dir=both];\n");
}
