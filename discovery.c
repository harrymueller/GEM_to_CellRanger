/*
    First iteration through GEM file
        Get array of unique genes, and dimensions

    @param dims = [min x, max x, min y, max y, num_genes]
*/
#include "discovery.h"

int discovery()
{
    FILE *fp = fopen(stats->filename, "r");

    if (!fp) {
        printf("File not accessible.");
        return 1;
    }

    char buffer[BUFF_SIZE], *words[4]; 
    int x, y;

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
            stats->nFeatures++;
        }

        // get x and y
        x = atoi(words[1]);
        y = atoi(words[2]);

        //add_barcode(x, y);
        dimensions(x, y);
    }

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

void dimensions(int x, int y)
{
        if (x < stats->dims->min_x) stats->dims->min_x = x;
        else if (x > stats->dims->max_x) stats->dims->max_x = x;

        if (y < stats->dims->min_y) stats->dims->min_y = y;
        else if (y > stats->dims->max_y) stats->dims->max_y = y;
}