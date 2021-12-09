#include "main.h"


int main(int argc, char *argv[]) 
{
    // TODO deal with args
    if (argc < 3) {
        printf("Missing source file arg and bin arg\n");
        return 1;
    } else {
        genes = (char**) malloc(GENES_SIZE * sizeof(char*));
        
        stats = malloc(sizeof(STATISTICS));
        stats->dims = malloc(sizeof(DIMENSIONS));
        stats->dims->min_x = 10000; stats->dims->min_y = 10000; // ensure min x and y are captured
        
        stats->filename = argv[1];
        stats->bin_size = atoi(argv[2]);

        x_bins = malloc(sizeof(int)*NUM_BINS);
        y_bins = malloc(sizeof(int)*NUM_BINS);

        printf("File: %s\nBin Size: %d\n\n", stats->filename, stats->bin_size);
        
        discovery();
        /*
        // checks that genes are sorted
        // TODO optimise
        int c = check_genes_unique(genes);
        if (c != 0) {
            printf("GEM file not sorted by gene."); // TODO
            return 1;
        }
        
        int bin_size = atoi(argv[2]);

        round_dims(dims);

        // gen barcodes <lab:x_y>
        if (NULL) {
            char *template = "tongue4"; // max length 7 TODO improve <- num chars stored for each
            char **barcodes = gen_barcodes(template, bin_size, dims);
            for (int i = 0; i < 25; i++) {
                printf("%s\n", barcodes[i]);
            }
        }
        // gen matrix*/
        print_stats();

        printf("...done\n");
    }


}

void print_stats()
{
    printf("Number of Genes: %d\n", stats->nFeatures);
    printf("Number of Barcodes: %d\n", stats->nBarcodes);

    printf("\nDimensions:\n");
    printf("\tMin x = %d\n", stats->dims->min_x);
    printf("\tMax x = %d\n", stats->dims->max_x);
    printf("\tMin y = %d\n", stats->dims->min_y);
    printf("\tMax y = %d\n", stats->dims->max_y);
}