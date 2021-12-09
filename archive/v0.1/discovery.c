/*
    First iteration through GEM file
        Get array of unique genes, and dimensions

    @param dims = [min x, max x, min y, max y, num_genes]
*/
#include "discovery.h"

int discovery(char *filename, char **genes, int *dims)
{
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("File not accessible.");
        return 1;
    }

    char buffer[BUFF_SIZE], *words[4]; 
    int a;

    char *temp = "";
    genes[0] = temp;
    char **last_gene = genes;
    fgets(buffer, BUFF_SIZE, fp); // skip first line

    while (fgets(buffer, BUFF_SIZE, fp)) {
        get_words(words, buffer);

        // check that &buffer is different -> add &buffer to unique_genes
        if (strcmp(words[0], *last_gene) != 0) {
            last_gene++;
            *last_gene = strdup(words[0]);
            dims[4]++;
        }

        a = atoi(words[1]); // get x
        if (a < dims[0]) dims[0] = a;
        else if (a > dims[1]) dims[1] = a;

        a = atoi(words[2]); // get y
        if (a < dims[2]) dims[2] = a;
        else if (a > dims[3]) dims[3] = a;
    }
    print_stuff(genes, dims);
    return 0;
}

/*
    Replaces \t w/ \0 and adds ptrs of each part in the line to words
*/
void get_words(char **words, char *buffer)
{
    int ptr = 0;
    words[ptr++] = buffer;

    for (int i = 0; i < BUFF_SIZE; i++) {
        if (buffer[i] == '\t') {
            buffer[i] = '\0';
            words[ptr++] = &buffer[i+1];
        } else if (buffer[i] == '\0') return;
    }
}

void print_stuff(char **genes, int *dims)
{
    /*printf("Genes:\n");

    while (1) {
        genes++;
        if (*genes) printf("\t%s\n", *genes);
        else break;
    }*/
    printf("Number of Genes: %d\n", dims[4]);
    
    printf("\nDimensions:\n");
    printf("\tMin x = %d\n", dims[0]);
    printf("\tMax x = %d\n", dims[1]);
    printf("\tMin y = %d\n", dims[2]);
    printf("\tMax y = %d\n", dims[3]);
}

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