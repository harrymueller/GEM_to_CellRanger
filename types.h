typedef struct Dimensions {
    int min_x;
    int max_x;
    int x_bins;
    
    int min_y;
    int max_y;
    int y_bins;
} DIMENSIONS;

typedef struct Statistics {
    DIMENSIONS *dims;

    int bin_size;
    char *filename;
    int nFeatures;
    int nBarcodes;

} STATISTICS;