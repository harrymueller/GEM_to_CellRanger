/*
    LIBRARIES
*/
#include <getopt.h>
#include <stdbool.h>
#include <dirent.h> // check dir exists
#include "general.h"

/*
    PREPROCESSOR VARIABLES
*/
#define CLI_OPTIONS "i:b:o:vhl:"

/*
    GLOBAL VARIABLES
*/
STATISTICS *stats;
FILENAMES *files;

/*
    FUNCTIONS
*/
void print_stats();
void populate_files();
void usage();
void check_params_set();

extern int process(bool);