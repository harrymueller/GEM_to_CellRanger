/*
    LIBRARIES
*/
#include <stdbool.h>
#include "general.h"

/*
    PREPROCESSOR VARIABLES
*/
#define GENES_SIZE (1<<17)

/*
    FUNCTIONS
*/
extern void discovery(char **);

extern void counts(char **);

extern void round_dims();
extern void save_barcodes();

extern void save_genes(char *, char **);