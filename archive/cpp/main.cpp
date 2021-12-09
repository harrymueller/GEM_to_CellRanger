#include "main.h"

int main(int argc, char *argv[])
{
    // TODO deal with args
    if (argc < 2) {
        std::cout << "Missing source file arg" << "\n";
        return 1;
    } else {
        char **genes = (char**) malloc(GENES_SIZE * sizeof(char*));
        int *dim = (int*) calloc(5, sizeof(int));
        dim[0] = 10000; dim[2] = 10000; // ensure min x and y are captured

        discovery(argv[1], genes, dim);

        std::cout << "...done" << "\n";
    }


}