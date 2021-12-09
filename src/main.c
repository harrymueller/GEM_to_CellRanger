#include "main.h"

int main(int argc, char *argv[])
{
    int option;
    bool verbose = false;
    opterr = 0;

    files = malloc(sizeof(FILENAMES));
    char *label = "STOmics";
    files->label = label;

    stats = malloc(sizeof(STATISTICS));
    stats->dims = malloc(sizeof(DIMENSIONS));
    stats->dims->min_x = 10000; stats->dims->min_y = 10000; // ensure min x and y are captured
    stats->bin_size = 10; // default

    while((option = getopt(argc, argv, CLI_OPTIONS)) != -1) {
        switch (option) {
            case 'i': 
                files->gem_file = strdup(optarg);
                break;
            case 'b': 
                stats->bin_size = atoi(optarg);
                break;
            case 'o': 
                files->output_dir = strdup(optarg);
                break;
            case 'l': 
                files->label = strdup(optarg);
                break;
            case 'v': 
                verbose = true;
                break;
            case 'h':
                usage();
                exit(EXIT_SUCCESS);
            default: 
                printf("Unknown argument supplied.\n\n");
                usage();
                exit(EXIT_FAILURE);
        }
    }

    check_params_set();
    populate_files();
    if (verbose) printf("GEM: %s\nDIR: %s/\nBin Size: %d\n\n", files->gem_file, files->output_dir, stats->bin_size);
   
    process(verbose);

    if (verbose) print_stats(); 

    exit(EXIT_SUCCESS);
}

/*
    Ensures required params (input and output) are given
*/
void check_params_set()
{
    if (!files->output_dir) 
        printf("Missing output dir - specifiy with -o\n");
    if (!files->gem_file) 
        printf("Missing input gem file - specifiy with -i\n");

    if (!files->output_dir || !files->gem_file) exit(EXIT_FAILURE);
}

/*
    Using the output dir, creates 4 full file paths for saving later
*/
void populate_files()
{
    int n = strlen(files->output_dir);

    // check output_dir is valid
    if (!opendir(files->output_dir)) {
        printf("Failed to open output directory '%s'\n", files->output_dir);
        exit(EXIT_FAILURE);
    }

    files->matrix   = malloc(sizeof(char) * (n + 2 + 10));
    sprintf(files->matrix, "%s/matrix.mtx", files->output_dir);
    files->matrix[n+11] = '\0';

    files->barcodes = malloc(sizeof(char) * (n + 2 + 12));
    sprintf(files->barcodes, "%s/barcodes.tsv", files->output_dir);
    files->barcodes[n+13] = '\0';
    
    files->genes    = malloc(sizeof(char) * (n + 2 + 9));
    sprintf(files->genes, "%s/genes.tsv", files->output_dir);
    files->genes[n+10] = '\0';
    
    files->spatial  = malloc(sizeof(char) * (n + 2 + 11));
    sprintf(files->spatial, "%s/spatial.tsv", files->output_dir);
    files->spatial[n+12] = '\0';
}

/*
    Prints usage information
*/
void usage()
{
    printf("Usage: GEMtoCellRanger [OPTIONS] -i [INPUT] -o [OUTPUT] \n");
    printf("Converts a GEM file to a CellRanger format with a spatial file.\n\n");
    
    // options
    printf("  -i filename\t GEM file\n");
    printf("  -o dir\t Specifies the output dir\n");
    printf("  -b binsize\t Size of bins to use [default=10]\n");
    printf("  -v \t\t Verbose\n");
    printf("  -h\t\t Help\n");
}

/*
    Prints some basic stats
*/
void print_stats()
{
    printf("Number of Genes: %d\n", stats->nFeatures);
    printf("Number of Barcodes: %d\n", stats->nBarcodes);
    printf("Number of Counts: %d\n", stats->nCounts);

    printf("\nDimensions:\n");
    printf("\tMin x = %d\n", stats->dims->min_x);
    printf("\tMax x = %d\n", stats->dims->max_x);
    printf("\tMin y = %d\n", stats->dims->min_y);
    printf("\tMax y = %d\n", stats->dims->max_y);
}