#include "barcodes.h"

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

/*
    Adds the positions to x_bins and y_bins if not already stored

    returns 1 if found, 0 if added
*/
int add_barcode(int x, int y) {
    int x_start = x / stats->bin_size * stats->bin_size;
    int y_start = y / stats->bin_size * stats->bin_size;

    int *x_ptr = x_bins, *y_ptr = y_bins;

    while (*x_ptr) {
        if (*x_ptr == x_start && *y_ptr == y_start) return 1;
        x_ptr++; y_ptr++;
    }

    // add
    *x_ptr = x_start; 
    *y_ptr = y_start; 

    stats->nBarcodes++;
    return 0;
}