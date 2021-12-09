#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// number of genes
#define GENES_SIZE (1<<16)

extern int discovery(char *, char **, int *);
extern char **gen_barcodes(char*, int, int*);
extern void round_dims(int*);
extern int check_genes_unique(char **);