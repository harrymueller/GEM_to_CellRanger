#include <stdlib.h>
#include <stdio.h>

/*
    BGI uses 'whole' number bins ie 1000-1100
*/
void round_dims(int *dims, int bin_size) {
    for (int i = 0; i < 4; i++) {
        dims[i] = dims[i] / bin_size * bin_size;
        if (i % 2 == 1) dims[i] += bin_size;
    }
}

/*
    Create an array containing all possible barcodes
*/
char **gen_barcodes(char *template, int bin_size, int *dims)
{
    int num_x = (dims[1] - dims[0]) / bin_size + 1; 
    int num_y = (dims[3] - dims[2]) / bin_size + 1;
    int index = 0; // faster than recalculating the index each time

    char **barcodes = (char **) malloc(sizeof(char*) * num_x * num_y);
    for (int j = dims[2]; j <= dims[3]; j+=bin_size) {
        for (int i = dims[0]; i <= dims[1]; i+=bin_size) {
            barcodes[index] = malloc(sizeof(char*) * 20);
            sprintf(barcodes[index++], "%s:%d_%d", template, i, j);
        }
    }
    return barcodes;
}