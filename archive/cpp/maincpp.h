#include <iostream>
#include <string>
#include <cstdlib>


// number of genes
#define GENES_SIZE (1<<16)

extern "C" int discovery(char *, char **, int *);