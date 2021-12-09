#include "main.h"
#include "globals.h"


int main(int argc, char *argv[]) 
{
    // TODO deal with args
    if (argc < 3) {
        printf("Missing source file arg and bin arg\n");
        return 1;
    } else {
        printf("File: %s\nBin Size: %s\n", argv[1], argv[2]);

        genes = (char**) malloc(GENES_SIZE * sizeof(char*));
        int *dims = (int*) calloc(5, sizeof(int));
        dims[0] = 10000; dims[2] = 10000; // ensure min x and y are captured

        discovery(argv[1], genes, dims);

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
        // gen matrix

        printf("...done\n");
    }


}