/*
    First iteration through GEM file
        Get array of unique genes, and dimensions
*/
#include "general.h"

void get_words(char **, char *);
void dimensions(int x, int y);

void discovery(char **genes)
{
    FILE *fp = fopen(files->gem_file, "r");

    if (!fp) {
        printf("File '%s' is not accessible.\n", files->gem_file);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFF_SIZE], *words[4]; 
    int x, y;

    char *temp = "";
    genes[0] = temp;
    char **last_gene = genes;

    fgets(buffer, BUFF_SIZE, fp); // skip first line
    while (fgets(buffer, BUFF_SIZE, fp)) {
        get_words(words, buffer);

        // check if gene is different -> adds to unique_genes
        if (strcmp(words[0], *last_gene) != 0) {
            last_gene++;
            *last_gene = strdup(words[0]);
            stats->nFeatures++;
        }

        // get x and y
        x = atoi(words[1]);
        y = atoi(words[2]);

        dimensions(x, y);
        stats->nCounts++;
    }

    fclose(fp);
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

/*
    Changes values in dims if x || y is <||> current values
*/
void dimensions(int x, int y)
{
        if (x < stats->dims->min_x) stats->dims->min_x = x;
        else if (x > stats->dims->max_x) stats->dims->max_x = x;

        if (y < stats->dims->min_y) stats->dims->min_y = y;
        else if (y > stats->dims->max_y) stats->dims->max_y = y;
}