/*
    Performs a second pass of the GEM file, saving count information to matrix.mtx
*/
#include "general.h"

extern void get_words(char **, char *);
extern int find_start(int);

void counts(char **genes)
{
    FILE *fp = fopen(files->gem_file, "r");
    FILE *wfp = fopen(files->matrix, "w"); // TODO

    if (!fp) {
        printf("File '%s' is not accessible.\n", files->gem_file);
        exit(EXIT_FAILURE);
    } else if (!wfp) {
        printf("File '%s' is not accessible.\n", files->matrix);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFF_SIZE], *words[4]; 
    int x, y, barcode_index, c;

    // add info to start of mtx filei
    fprintf(wfp, "%%%%MatrixMarket matrix coordinate integer general\n");
    fprintf(wfp, "%% %s matrix file\n", files->label);
    fprintf(wfp, "%d %d %d\n", stats->nFeatures, stats->nBarcodes, stats->nCounts);

    char *current = "";
    current = strdup(current);
    int gene_index = 0; // iterate from 1 
    fgets(buffer, BUFF_SIZE, fp); // skip first line

    while (fgets(buffer, BUFF_SIZE, fp)) {
        get_words(words, buffer);

        // new -> gene
        if (strcmp(words[0], current) != 0) {
            gene_index++;
            free(current); // free current gene and then realloc 
            current = strdup(words[0]);
        }

        // get x, y, c
        x = atoi(words[1]);
        y = atoi(words[2]);
        c = atoi(words[3]); // counts

        // calculate barcode index
        barcode_index = (find_start(x) - stats->dims->min_x) / stats->bin_size + 1 +
            (find_start(y) - stats->dims->min_y) / stats->bin_size * stats->dims->x_bins;

        fprintf(wfp, "%d %d %d\n", gene_index, barcode_index, c);
    }

    fclose(fp); fclose(wfp);
}
