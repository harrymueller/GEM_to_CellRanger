#include "general.h"

/*
    BGI uses 'whole' number bins ie 1000-1100
*/
int find_start(int a) {
    return (a / stats->bin_size * stats->bin_size);
}

/*
    Rounds min/max dims to start positions; calculates number of bins for x and y; calculates number of barcodes 
*/
void round_dims()
{
    // round to the start
    stats->dims->min_x = find_start(stats->dims->min_x);
    stats->dims->max_x = find_start(stats->dims->max_x);
    stats->dims->min_y = find_start(stats->dims->min_y);
    stats->dims->max_y = find_start(stats->dims->max_y);

    // calculate number of bins required for xs and ys
    stats->dims->x_bins = (stats->dims->max_x - stats->dims->min_x) / stats->bin_size;
    stats->dims->y_bins = (stats->dims->max_y - stats->dims->min_y) / stats->bin_size;
    
    stats->nBarcodes = stats->dims->x_bins * stats->dims->y_bins;
}

/*
    Saves barcodes and spatial info
*/
void save_barcodes()
{
    FILE *barcodes_fp = fopen(files->barcodes, "w");
    FILE *spatial_fp = fopen(files->spatial, "w");

    for (int j = stats->dims->min_y; j <= stats->dims->max_y; j+=stats->bin_size) {
        for (int i = stats->dims->min_x; i <= stats->dims->max_x; i+=stats->bin_size) {
            fprintf(barcodes_fp, "%s_x%d_y%d\n", files->label, i, j);
            fprintf(spatial_fp, "%s_x%d_y%d\t%d\t%d\n", files->label, i, j, i, j);
        }
    }

    fclose(barcodes_fp);
    fclose(spatial_fp);
}