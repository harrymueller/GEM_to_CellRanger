
#include "process.h"

void process(bool verbose) 
{
    char **genes = (char**) malloc(GENES_SIZE * sizeof(char*));
    if (!genes) {
        printf("Unable to allocate space for genes array.\n");
        exit(EXIT_FAILURE);
    }

    // find genes and dimensions
    discovery(genes);
    
    /*
    // checks that genes are sorted
    // TODO optimise
    int c = check_genes_unique(genes);
    if (c != 0) {
        printf("GEM file not sorted by gene."); // TODO
        return 1;
    }
    */

    // round dimensions
    round_dims();

    // save genes to file
    save_genes(files->genes, genes);

    // create new process and save barcodes and spatial info to file
    save_barcodes();

    // read through file, adding to output
    counts(genes);
}