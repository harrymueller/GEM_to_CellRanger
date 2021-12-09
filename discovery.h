#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// gem line size
// shouldn't need to be larger
#define BUFF_SIZE 128

void get_words(char **, char *);
void dimensions(int x, int y);

extern int add_barcode(int, int);

extern char **genes;
extern int *x_bins, *y_bins;
extern STATISTICS *stats;