#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gem line size
// shouldn't need to be larger
#define BUFF_SIZE 128

void get_words(char **, char *);
void print_stuff(char **, int *);

extern char **barcodes, **genes;
extern struct Dimensions dims;