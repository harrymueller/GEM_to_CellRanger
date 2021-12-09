#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Saves all genes to genes.tsv
*/
void save_genes(char *file, char **genes) {
    FILE *fp = fopen(file, "w");

    if (!fp) {
        printf("Output file '%s' not writeable.", file);
        exit(EXIT_FAILURE);
    }

    char **gene_ptr = genes;
    while (*++gene_ptr) {
        fprintf(fp, "%s\t%s\n", *gene_ptr, *gene_ptr);
    }

    fclose(fp);
}

/*
    Runs through genes checking that all are unique
*/
int check_genes_unique(char **genes) 
{
    char **ptr = genes;
    int counter = 0;
    while (*genes) { // loop through all genes
        while (*ptr) { // checking ptr
            if (genes != ptr && strcmp(*genes, *ptr) == 0) counter++;
            ptr++;
        }
        genes++;
    }

    return counter;
}