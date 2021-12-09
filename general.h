/*
    LIBRARIES
*/  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    PREPROCESSOR VARIABLES
*/
#define BUFF_SIZE 128

/*
    CUSTOM VARIABLES
*/
// basic info about spot dims
typedef struct Dimensions {
    int min_x;
    int max_x;
    int x_bins;
    
    int min_y;
    int max_y;
    int y_bins;
} DIMENSIONS;

// stores stats inc. info about dims and bin size
typedef struct Statistics {
    DIMENSIONS *dims;

    int bin_size;
    int nFeatures;
    int nBarcodes;
    int nCounts; // not sum, but number of unique counts
} STATISTICS;

// Stores all req. filenames
typedef struct FileNames {
    char *gem_file;
    char *output_dir;
    char *label;

    char *matrix;   // matrix.mtx   10
    char *barcodes; // barcodes.tsv 12
    char *genes;    // genes.tsv    9
    char *spatial;  // spatial.tsv  11
} FILENAMES;

/*
    GLOBAL VARIABLES
*/
extern STATISTICS *stats;
extern FILENAMES *files;