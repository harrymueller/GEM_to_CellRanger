#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"

// number of genes
#define GENES_SIZE (1<<16)
#define NUM_BINS (1<<26)

void print_stats();

extern int discovery();
//extern char **gen_barcodes(char*, int, int*);
//extern void round_dims(int*);
//extern int check_genes_unique(char **);

// global vars
char **genes; // store genes
int *x_bins, *y_bins; // store bin start positions

STATISTICS *stats; // store stats